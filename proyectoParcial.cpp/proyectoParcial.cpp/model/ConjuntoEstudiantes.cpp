#include "ConjuntoEstudiantes.h"
#include <iostream>

using namespace std;

ConjuntoEstudiantes::ConjuntoEstudiantes(string nombre) {
    this->nombreConjunto = nombre;
}

void ConjuntoEstudiantes::agregar(const Estudiante& e) {
    if (!pertenece(e.getNombre())) {
        elementos.agregar(e);
    }
}

bool ConjuntoEstudiantes::pertenece(const string& nombre) const {
    return elementos.buscar(nombre) != nullptr;
}

string ConjuntoEstudiantes::getNombre() const {
    return nombreConjunto;
}

bool ConjuntoEstudiantes::eliminar(const std::string& nombre) {
    return elementos.eliminar(nombre);
}

int ConjuntoEstudiantes::tamano() const {
    return elementos.tamano();
}

Nodo* ConjuntoEstudiantes::getElementos() const {
    return elementos.getCabeza();
}

void ConjuntoEstudiantes::limpiar() {
    elementos.limpiar();
}

// Operaciones de Conjuntos con iteracion por Nodos (while)

ConjuntoEstudiantes ConjuntoEstudiantes::interseccion(const ConjuntoEstudiantes& otro, string nuevoNombre) const {
    ConjuntoEstudiantes resultado(nuevoNombre);
    Nodo* actual = elementos.getCabeza();
    
    while (actual != nullptr) {
        if (otro.pertenece(actual->dato.getNombre())) {
            resultado.agregar(actual->dato);
        }
        actual = actual->siguiente;
    }
    return resultado;
}

ConjuntoEstudiantes ConjuntoEstudiantes::diferencia(const ConjuntoEstudiantes& otro, string nuevoNombre) const {
    ConjuntoEstudiantes resultado(nuevoNombre);
    Nodo* actual = elementos.getCabeza();
    
    while (actual != nullptr) {
        if (!otro.pertenece(actual->dato.getNombre())) {
            resultado.agregar(actual->dato);
        }
        actual = actual->siguiente;
    }
    return resultado;
}

ConjuntoEstudiantes ConjuntoEstudiantes::unionConjuntos(const ConjuntoEstudiantes& otro, string nuevoNombre) const {
    ConjuntoEstudiantes resultado(nuevoNombre);
    
    // Agregamos todos los elementos del primer conjunto
    Nodo* actual = elementos.getCabeza();
    while (actual != nullptr) {
        resultado.agregar(actual->dato);
        actual = actual->siguiente;
    }
    
    // Agregamos los del segundo conjunto (la funcion agregar ya evita duplicados)
    actual = otro.getElementos();
    while (actual != nullptr) {
        resultado.agregar(actual->dato);
        actual = actual->siguiente;
    }
    
    return resultado;
}
