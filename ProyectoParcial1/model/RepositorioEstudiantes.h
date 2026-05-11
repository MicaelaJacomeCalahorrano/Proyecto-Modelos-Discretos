#ifndef REPOSITORIO_ESTUDIANTES_H
#define REPOSITORIO_ESTUDIANTES_H

#include "Estudiante.h"
#include <vector>
#include <optional>

//usa vector como lista dinámica
class RepositorioEstudiantes {
private:
    std::vector<Estudiante> estudiantes;

public:
    void agregar(const Estudiante& e);
    bool eliminar(const std::string& nombre);
    std::optional<Estudiante> buscar(const std::string& nombre) const;
    std::vector<Estudiante> obtenerTodos() const;
    int contar() const;
    bool estaVacio() const;
    void limpiar();
};

#endif