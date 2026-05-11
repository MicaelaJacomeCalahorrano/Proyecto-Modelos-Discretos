#include "RepositorioEstudiantes.h"

void RepositorioEstudiantes::agregar(const Estudiante& e) {
    estudiantes.agregar(e);
}

bool RepositorioEstudiantes::eliminar(const std::string& nombre) {
    return estudiantes.eliminar(nombre);
}

Estudiante* RepositorioEstudiantes::buscar(const std::string& nombre) const {
    return estudiantes.buscar(nombre);
}

Nodo* RepositorioEstudiantes::getCabeza() const {
    return estudiantes.getCabeza();
}

int RepositorioEstudiantes::contar() const {
    return estudiantes.tamano();
}

bool RepositorioEstudiantes::estaVacio() const {
    return estudiantes.vacia();
}

void RepositorioEstudiantes::limpiar() {
    estudiantes.limpiar();
}