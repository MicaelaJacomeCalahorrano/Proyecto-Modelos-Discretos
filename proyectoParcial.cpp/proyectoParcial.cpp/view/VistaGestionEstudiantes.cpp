#include "VistaGestionEstudiantes.h"
#include <iomanip>
#include <iostream>
#include <limits>


using namespace std;

void VistaGestionEstudiantes::mostrarMenu() {
  cout << "\n========================================\n";
  cout << "   SISTEMA DE EVALUACION ACADEMICA \n";
  cout << "========================================\n";
  cout << "1. Agregar estudiante\n";
  cout << "2. Listar todos los estudiantes\n";
  cout << "3. Buscar estudiante\n";
  cout << "4. Eliminar estudiante\n";
  cout << "5. Ejecutar Motor de Inferencia (Clasificar)\n";
  cout << "6. Ver Operaciones de Conjuntos Logicos\n";
  cout << "7. Ver Resumen Estadistico\n";
  cout << "8. Simular Examen de Recuperacion (Pila LIFO)\n";
  cout << "9. Salir del modulo\n";
  cout << "========================================\n";
  cout << "Opcion: ";
}

int VistaGestionEstudiantes::leerOpcion() {
  int opcion;
  while (!(cin >> opcion)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida. Ingrese un numero: ";
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return opcion;
}

Estudiante VistaGestionEstudiantes::leerDatosEstudiante() {
  string nombre;
  double promedio, asistencia;
  int tareas;

  cout << "\n--- NUEVO ESTUDIANTE ---\n";
  cout << "Nombre: ";
  getline(cin, nombre);

  cout << "Promedio (0-10): ";
  while (!(cin >> promedio)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida. Ingrese un numero: ";
  }

  cout << "Asistencia (0-100%): ";
  while (!(cin >> asistencia)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida. Ingrese un numero: ";
  }

  cout << "Entrego todas las tareas? (1=Si, 0=No): ";
  while (!(cin >> tareas)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida. Ingrese 1 o 0: ";
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  return Estudiante(nombre, promedio, asistencia, tareas == 1);
}

string VistaGestionEstudiantes::leerNombre() {
  string nombre;
  cout << "Nombre: ";
  getline(cin, nombre);
  return nombre;
}

void VistaGestionEstudiantes::mostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "\n No hay estudiantes registrados.\n";
        return;
    }
    
    cout << "\n LISTA DE ESTUDIANTES\n";
    cout << left << setw(25) << "Nombre"
         << setw(10) << "Promedio"
         << setw(12) << "Asistencia%"
         << "Tareas\n";
    cout << string(55, '-') << "\n";
    
    int total = 0;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Estudiante e = actual->dato;
        cout << left << setw(25) << e.getNombre()
             << setw(10) << e.getPromedio()
             << setw(12) << e.getAsistencia()
             << (e.getTareasCompletas() ? "Si" : "No") << "\n";
        total++;
        actual = actual->siguiente;
    }
    cout << "Total: " << total << " estudiantes\n";
}

void VistaGestionEstudiantes::mostrarEstudiante(const Estudiante& e) {
    cout << "\n ESTUDIANTE ENCONTRADO:\n";
    cout << "   Nombre: " << e.getNombre() << "\n";
    cout << "   Promedio: " << e.getPromedio() << "\n";
    cout << "   Asistencia: " << e.getAsistencia() << "%\n";
    cout << "   Tareas completas: " << (e.getTareasCompletas() ? "Si" : "No") << "\n";
}

void VistaGestionEstudiantes::mostrarMensaje(const string& msg) {
    cout << msg << "\n";
}

void VistaGestionEstudiantes::mostrarError(const string& msg) {
    cout << "Error " << msg << "\n";
}

void VistaGestionEstudiantes::mostrarExito(const string& msg) {
    cout << "Exito " << msg << "\n";
}

void VistaGestionEstudiantes::pausa() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

void VistaGestionEstudiantes::mostrarTablaVerdad(const Estudiante& e, const string& estadoDeducido) {
    cout << "\n--- ANALISIS LOGICO: " << e.getNombre() << " ---\n";
    cout << " P (Promedio >= 7) : " << (e.evaluarP() ? "Verdadero" : "Falso") << "\n";
    cout << " Q (Asistencia >= 80%): " << (e.evaluarQ() ? "Verdadero" : "Falso") << "\n";
    cout << " R (Entrego Tareas) : " << (e.evaluarR() ? "Verdadero" : "Falso") << "\n";
    cout << " => Inferencia Aplicada: " << estadoDeducido << "\n";
}

void VistaGestionEstudiantes::mostrarOperacionConjuntos(const string& nombreOperacion, Nodo* cabeza) {
    cout << "\n--- CONJUNTO: " << nombreOperacion << " ---\n";
    if (cabeza == nullptr) {
        cout << " El conjunto esta vacio.\n";
    } else {
        int total = 0;
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Estudiante e = actual->dato;
            cout << " - " << e.getNombre() << " (Prom: " << e.getPromedio() << ", Asist: " << e.getAsistencia() << "%)\n";
            total++;
            actual = actual->siguiente;
        }
        cout << " Total en el conjunto: " << total << "\n";
    }
}

void VistaGestionEstudiantes::mostrarResumen(int total, int aprobados,
                                             int recuperacion, int reprobados) {
  cout << "\n========================================\n";
  cout << "   RESUMEN DE EVALUACION ACADEMICA\n";
  cout << "========================================\n";
  cout << " Estudiantes Analizados : " << total << "\n";
  cout << " Aprobados (A)          : " << aprobados << "\n";
  cout << " En Recuperacion (B)    : " << recuperacion << "\n";
  cout << " Reprobados (C)         : " << reprobados << "\n";
  cout << "========================================\n";
}