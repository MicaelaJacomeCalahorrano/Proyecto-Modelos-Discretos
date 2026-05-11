#ifndef CONJUNTO_ESTUDIANTES_H
#define CONJUNTO_ESTUDIANTES_H

#include "Estudiante.h"
#include "EstructurasDinamicas.h"
#include <string>

class ConjuntoEstudiantes {
private:
    std::string nombreConjunto;
    ListaEstudiantes elementos;

public:
    ConjuntoEstudiantes(std::string nombre = "");
    
    void agregar(const Estudiante& e);
    bool pertenece(const std::string& nombre) const;
    void mostrar() const;
    bool eliminar(const std::string& nombre);
    int tamano() const;
    
    std::string getNombre() const;
    Nodo* getElementos() const; // Iterador base
    void limpiar();
    
    // Operaciones Lógicas de Conjuntos
    ConjuntoEstudiantes unionConjuntos(const ConjuntoEstudiantes& otro, std::string nuevoNombre) const;
    ConjuntoEstudiantes interseccion(const ConjuntoEstudiantes& otro, std::string nuevoNombre) const;
    ConjuntoEstudiantes diferencia(const ConjuntoEstudiantes& otro, std::string nuevoNombre) const;
};

#endif
