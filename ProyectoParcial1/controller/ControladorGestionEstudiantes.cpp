#include "ControladorGestionEstudiantes.h"

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
                auto estudiantes = repositorio.obtenerTodos();
                vista.mostrarLista(estudiantes);
                break;
            }
            case 3: { // Buscar
                std::string nombre = vista.leerNombre();
                auto estudiante = repositorio.buscar(nombre);
                if (estudiante.has_value()) {
                    vista.mostrarEstudiante(estudiante.value());
                } else {
                    vista.mostrarError("Estudiante no encontrado");
                }
                break;
            }
            case 4: { // Eliminar
                std::string nombre = vista.leerNombre();
                if (repositorio.eliminar(nombre)) {
                    vista.mostrarExito("Estudiante eliminado correctamente");
                } else {
                    vista.mostrarError("Estudiante no encontrado");
                }
                break;
            }
            case 5:
                vista.mostrarMensaje("Saliendo del módulo de gestión...");
                break;
            default:
                vista.mostrarError("Opción inválida");
        }
        
        if (opcion != 5) {
            vista.pausa();
        }
    } while(opcion != 5);
}

RepositorioEstudiantes* ControladorGestionEstudiantes::getRepositorio() {
    return &repositorio;
}