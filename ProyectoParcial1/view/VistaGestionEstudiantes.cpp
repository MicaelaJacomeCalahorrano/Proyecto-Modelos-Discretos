#include "VistaGestionEstudiantes.h"
#include <iostream>
#include <iomanip>
#include <limits>

void VistaGestionEstudiantes::mostrarMenu() {
    std::cout << "\n========================================\n";
    std::cout << "   GESTION DE ESTUDIANTES \n";
    std::cout << "========================================\n";
    std::cout << "1. Agregar estudiante\n";
    std::cout << "2. Listar todos los estudiantes\n";
    std::cout << "3. Buscar estudiante\n";
    std::cout << "4. Eliminar estudiante\n";
    std::cout << "5. Salir del modulo\n";
    std::cout << "========================================\n";
    std::cout << "Opcion: ";
}

int VistaGestionEstudiantes::leerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

Estudiante VistaGestionEstudiantes::leerDatosEstudiante() {
    std::string nombre;
    double promedio, asistencia;
    int tareas;
    
    std::cout << "\n--- NUEVO ESTUDIANTE ---\n";
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Promedio (0-10): ";
    std::cin >> promedio;
    std::cout << "Asistencia (0-100%): ";
    std::cin >> asistencia;
    std::cout << "¿Entrego todas las tareas? (1=Si, 0=No): ";
    std::cin >> tareas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    return Estudiante(nombre, promedio, asistencia, tareas == 1);
}

std::string VistaGestionEstudiantes::leerNombre() {
    std::string nombre;
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    return nombre;
}

void VistaGestionEstudiantes::mostrarLista(const std::vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        std::cout << "\n No hay estudiantes registrados.\n";
        return;
    }
    
    std::cout << "\n LISTA DE ESTUDIANTES\n";
    std::cout << std::left << std::setw(25) << "Nombre"
              << std::setw(10) << "Promedio"
              << std::setw(12) << "Asistencia%"
              << "Tareas\n";
    std::cout << std::string(55, '-') << "\n";
    
    for (const auto& e : estudiantes) {
        std::cout << std::left << std::setw(25) << e.getNombre()
                  << std::setw(10) << e.getPromedio()
                  << std::setw(12) << e.getAsistencia()
                  << (e.getTareasCompletas() ? "Sí" : "No") << "\n";
    }
    std::cout << "Total: " << estudiantes.size() << " estudiantes\n";
}

void VistaGestionEstudiantes::mostrarEstudiante(const Estudiante& e) {
    std::cout << "\n ESTUDIANTE ENCONTRADO:\n";
    std::cout << "   Nombre: " << e.getNombre() << "\n";
    std::cout << "   Promedio: " << e.getPromedio() << "\n";
    std::cout << "   Asistencia: " << e.getAsistencia() << "%\n";
    std::cout << "   Tareas completas: " << (e.getTareasCompletas() ? "Sí" : "No") << "\n";
}

void VistaGestionEstudiantes::mostrarMensaje(const std::string& msg) {
    std::cout << msg << "\n";
}

void VistaGestionEstudiantes::mostrarError(const std::string& msg) {
    std::cout << "Error " << msg << "\n";
}

void VistaGestionEstudiantes::mostrarExito(const std::string& msg) {
    std::cout << "Éxito " << msg << "\n";
}

void VistaGestionEstudiantes::pausa() {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.get();
}