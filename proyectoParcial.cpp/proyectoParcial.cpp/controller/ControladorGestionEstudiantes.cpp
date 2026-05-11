#include "ControladorGestionEstudiantes.h"

using namespace std;

ControladorGestionEstudiantes::ControladorGestionEstudiantes() 
    : conjuntoA("Aprobados (A)"), conjuntoB("Recuperacion (B)"), conjuntoC("Reprobados (C)") {}

void ControladorGestionEstudiantes::ejecutar() {
    int opcion;
    do {
        vista.mostrarMenu();
        opcion = vista.leerOpcion();
        
        switch(opcion) {
            case 1: { // Agregar
                Estudiante e = vista.leerDatosEstudiante();
                repositorio.agregar(e);
                vista.mostrarExito("Estudiante agregado correctamente");
                break;
            }
            case 2: { // Listar
                Nodo* estudiantes = repositorio.getCabeza();
                vista.mostrarLista(estudiantes);
                break;
            }
            case 3: { // Buscar
                string nombre = vista.leerNombre();
                Estudiante* estudiante = repositorio.buscar(nombre);
                if (estudiante != nullptr) {
                    vista.mostrarEstudiante(*estudiante);
                } else {
                    vista.mostrarError("Estudiante no encontrado");
                }
                break;
            }
            case 4: { // Eliminar
                string nombre = vista.leerNombre();
                if (repositorio.eliminar(nombre)) {
                    // También lo eliminamos de los conjuntos lógicos si existía
                    conjuntoA.eliminar(nombre);
                    conjuntoB.eliminar(nombre);
                    conjuntoC.eliminar(nombre);
                    vista.mostrarExito("Estudiante eliminado correctamente");
                } else {
                    vista.mostrarError("Estudiante no encontrado");
                }
                break;
            }
            case 5: { // Ejecutar Motor de Inferencia
                ejecutarMotorInferencia();
                break;
            }
            case 6: { // Operaciones de Conjuntos Lógicos
                mostrarOperacionesConjuntos();
                break;
            }
            case 7: { // Resumen Estadístico
                mostrarResumenFinal();
                break;
            }
            case 8: { // Simular Recuperación
                simularRecuperacion();
                break;
            }
            case 9:
                vista.mostrarMensaje("Saliendo del modulo de evaluacion academica...");
                break;
            default:
                vista.mostrarError("Opcion invalida");
        }
        
        if (opcion != 9) {
            vista.pausa();
        }
    } while(opcion != 9);
}

void ControladorGestionEstudiantes::ejecutarMotorInferencia() {
    Nodo* estudiantes = repositorio.getCabeza();
    if (estudiantes == nullptr) {
        vista.mostrarError("No hay estudiantes para evaluar.");
        return;
    }

    // IMPORTANTE: Ya NO limpiamos los conjuntos antes de ejecutar para poder mantener el historial.
    // Esto permite que las operaciones como A ∩ B (pasaron de recuperación a aprobación) tengan sentido.

    // USO EXPLICITO DE COLA (ColaEstudiantes)
    // Encolamos a todos los estudiantes pendientes de evaluacion
    ColaEstudiantes colaEvaluacion;
    Nodo* actual = estudiantes;
    while (actual != nullptr) {
        colaEvaluacion.encolar(actual->dato);
        actual = actual->siguiente;
    }
    
    // Procesamos la cola FIFO (First In, First Out)
    while (!colaEvaluacion.vacia()) {
        Estudiante e = colaEvaluacion.verFrente();
        colaEvaluacion.desencolar();
        
        EstadoAcademico estado = MotorInferencia::deducirEstado(e);
        string estadoStr = MotorInferencia::estadoToString(estado);
        
        vista.mostrarTablaVerdad(e, estadoStr);
        
        switch(estado) {
            case APROBADO: 
                conjuntoA.agregar(e); 
                // Apilamos al estudiante como historial de aprobados recientes
                // (Se ha eliminado historialAprobados para simplificar el menu, ahora Pila se usa en opcion 8)
                break;
            case RECUPERACION: conjuntoB.agregar(e); break;
            case REPROBADO: conjuntoC.agregar(e); break;
        }
    }
    vista.mostrarExito("Motor de inferencia ejecutado. Estudiantes clasificados.");
}

void ControladorGestionEstudiantes::mostrarOperacionesConjuntos() {
    // A INT B: estudiantes que pasaron de recuperacion a aprobacion
    // Con evaluacion actual estatica sera vacio porque un estudiante solo esta en 1 conjunto
    // a la vez, pero implementamos la logica exigida en el sistema de conjuntos.
    ConjuntoEstudiantes aIntB = conjuntoA.interseccion(conjuntoB, "A INT B (Pasaron de recuperacion a aprobacion)");
    vista.mostrarOperacionConjuntos(aIntB.getNombre(), aIntB.getElementos());
    
    // A - C: estudiantes que aprobaron directamente sin repetir
    ConjuntoEstudiantes aDifC = conjuntoA.diferencia(conjuntoC, "A - C (Aprobaron directamente sin repetir)");
    vista.mostrarOperacionConjuntos(aDifC.getNombre(), aDifC.getElementos());
    
    // B U C: estudiantes que necesitan apoyo adicional
    ConjuntoEstudiantes bUnionC = conjuntoB.unionConjuntos(conjuntoC, "B U C (Necesitan apoyo adicional)");
    vista.mostrarOperacionConjuntos(bUnionC.getNombre(), bUnionC.getElementos());
}

void ControladorGestionEstudiantes::mostrarResumenFinal() {
    int total = repositorio.contar();
    vista.mostrarResumen(total, conjuntoA.tamano(), conjuntoB.tamano(), conjuntoC.tamano());
}

RepositorioEstudiantes* ControladorGestionEstudiantes::getRepositorio() {
    return &repositorio;
}

void ControladorGestionEstudiantes::simularRecuperacion() {
    if (conjuntoB.getElementos() == nullptr) {
        vista.mostrarError("No hay estudiantes en recuperacion para simular el examen.");
        return;
    }
    
    vista.mostrarMensaje("\n--- INICIANDO EXAMEN DE RECUPERACION ---");
    int aprobados = 0;
    
    // Para calificar los examenes de recuperacion, el profesor evalua primero los
    // ultimos entregados (LIFO). Por lo tanto, usamos una Pila (PilaEstudiantes)
    PilaEstudiantes pilaExamenes;
    
    // Obtenemos los estudiantes de B y los apilamos
    Nodo* actualB = conjuntoB.getElementos();
    while (actualB != nullptr) {
        pilaExamenes.apilar(actualB->dato);
        actualB = actualB->siguiente;
    }
    
    // Desapilamos (LIFO) y procesamos cada examen
    while (!pilaExamenes.vacia()) {
        Estudiante e = pilaExamenes.desapilar();
        // Obtenemos el estudiante del repositorio original
        Estudiante* ptrEstudiante = repositorio.buscar(e.getNombre());
        if (ptrEstudiante != nullptr) {
            Estudiante actualizado = *ptrEstudiante;
            
            // Simulamos que el estudiante aprueba el examen con una nota aleatoria entre 7 y 10
            // y que asiste y entrega tareas. Para hacerlo simple sin rand(), le ponemos 7.5
            actualizado.setPromedio(7.5);
            actualizado.setAsistencia(100.0);
            actualizado.setTareasCompletas(true);
            
            // Actualizamos en repositorio eliminando y agregando
            repositorio.eliminar(actualizado.getNombre());
            repositorio.agregar(actualizado);
            
            vista.mostrarMensaje("- " + actualizado.getNombre() + " rindio recuperacion (LIFO) y obtuvo Promedio: 7.5");
            aprobados++;
        }
    }
    
    vista.mostrarExito("Simulacion finalizada. Usa la Opcion 5 (Ejecutar Motor de Inferencia) para actualizarlos logicamente.");
}