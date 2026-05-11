#ifndef REPOSITORIO_ESTUDIANTES_H
#define REPOSITORIO_ESTUDIANTES_H

#include "Estudiante.h"
#include "EstructurasDinamicas.h"

class RepositorioEstudiantes {
private:
    ListaEstudiantes estudiantes;

public:
    void agregar(const Estudiante& e);
    bool eliminar(const std::string& nombre);
    Estudiante* buscar(const std::string& nombre) const;
    
    // Retorna la cabeza de la lista para iterar sin hacer copias pesadas
    Nodo* getCabeza() const;
    
    int contar() const;
    bool estaVacio() const;
    void limpiar();
};

#endif