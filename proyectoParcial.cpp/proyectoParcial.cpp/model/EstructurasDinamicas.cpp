#include "EstructurasDinamicas.h"
#include <iostream>

// ==========================================
// 1. LISTA DINAMICA
// ==========================================
ListaEstudiantes::ListaEstudiantes() {
    cabeza = nullptr;
    cantidad = 0;
}

ListaEstudiantes::~ListaEstudiantes() {
    limpiar();
}

void ListaEstudiantes::limpiar() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* borrar = actual;
        actual = actual->siguiente;
        delete borrar; // Libera memoria
    }
    cabeza = nullptr;
    cantidad = 0;
}

void ListaEstudiantes::agregar(const Estudiante& e) {
    Nodo* nuevo = new Nodo(e);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cantidad++;
}

bool ListaEstudiantes::eliminar(const std::string& nombre) {
    if (cabeza == nullptr) return false;
    
    // Si es el primero
    if (cabeza->dato.getNombre() == nombre) {
        Nodo* borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
        cantidad--;
        return true;
    }
    
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->dato.getNombre() != nombre) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente != nullptr) {
        Nodo* borrar = actual->siguiente;
        actual->siguiente = borrar->siguiente;
        delete borrar;
        cantidad--;
        return true;
    }
    return false;
}

Estudiante* ListaEstudiantes::buscar(const std::string& nombre) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato.getNombre() == nombre) {
            return &(actual->dato);
        }
        actual = actual->siguiente;
    }
    return nullptr; // No encontrado
}

Nodo* ListaEstudiantes::getCabeza() const { return cabeza; }
int ListaEstudiantes::tamano() const { return cantidad; }
bool ListaEstudiantes::vacia() const { return cabeza == nullptr; }

// ==========================================
// 2. PILA DINAMICA (LIFO)
// ==========================================
PilaEstudiantes::PilaEstudiantes() {
    tope = nullptr;
    cantidad = 0;
}

PilaEstudiantes::~PilaEstudiantes() {
    while (!vacia()) {
        desapilar();
    }
}

void PilaEstudiantes::apilar(const Estudiante& e) {
    Nodo* nuevo = new Nodo(e);
    nuevo->siguiente = tope;
    tope = nuevo;
    cantidad++;
}

Estudiante PilaEstudiantes::desapilar() {
    if (vacia()) {
        throw std::runtime_error("Pila vacia");
    }
    Nodo* borrar = tope;
    Estudiante e = borrar->dato;
    tope = tope->siguiente;
    delete borrar;
    cantidad--;
    return e;
}

Estudiante PilaEstudiantes::verTope() const {
    if (vacia()) throw std::runtime_error("Pila vacia");
    return tope->dato;
}

bool PilaEstudiantes::vacia() const { return tope == nullptr; }
int PilaEstudiantes::tamano() const { return cantidad; }

// ==========================================
// 3. COLA DINAMICA (FIFO)
// ==========================================
ColaEstudiantes::ColaEstudiantes() {
    frente = nullptr;
    final = nullptr;
    cantidad = 0;
}

ColaEstudiantes::~ColaEstudiantes() {
    while (!vacia()) {
        desencolar();
    }
}

void ColaEstudiantes::encolar(const Estudiante& e) {
    Nodo* nuevo = new Nodo(e);
    if (vacia()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cantidad++;
}

Estudiante ColaEstudiantes::desencolar() {
    if (vacia()) {
        throw std::runtime_error("Cola vacia");
    }
    Nodo* borrar = frente;
    Estudiante e = borrar->dato;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr; // Si quedo vacia, final tambien es nulo
    }
    delete borrar;
    cantidad--;
    return e;
}

Estudiante ColaEstudiantes::verFrente() const {
    if (vacia()) throw std::runtime_error("Cola vacia");
    return frente->dato;
}

bool ColaEstudiantes::vacia() const { return frente == nullptr; }
int ColaEstudiantes::tamano() const { return cantidad; }
