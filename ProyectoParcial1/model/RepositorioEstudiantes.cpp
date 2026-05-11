#include "RepositorioEstudiantes.h"
#include <algorithm>

void RepositorioEstudiantes::agregar(const Estudiante& e) {
    estudiantes.push_back(e);
}

bool RepositorioEstudiantes::eliminar(const std::string& nombre) {
    auto it = std::remove_if(estudiantes.begin(), estudiantes.end(),
        [&nombre](const Estudiante& e) { return e.getNombre() == nombre; });
    
    if (it != estudiantes.end()) {
        estudiantes.erase(it, estudiantes.end());
        return true;
    }
    return false;
}

std::optional<Estudiante> RepositorioEstudiantes::buscar(const std::string& nombre) const {
    for (const auto& e : estudiantes) {
        if (e.getNombre() == nombre) {
            return e;
        }
    }
    return std::nullopt;
}

std::vector<Estudiante> RepositorioEstudiantes::obtenerTodos() const {
    return estudiantes;
}

int RepositorioEstudiantes::contar() const {
    return estudiantes.size();
}

bool RepositorioEstudiantes::estaVacio() const {
    return estudiantes.empty();
}

void RepositorioEstudiantes::limpiar() {
    estudiantes.clear();
}