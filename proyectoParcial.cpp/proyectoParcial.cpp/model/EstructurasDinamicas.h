#ifndef ESTRUCTURAS_DINAMICAS_H
#define ESTRUCTURAS_DINAMICAS_H

#include "Nodo.h"

// ==========================================
// 1. LISTA DINAMICA (Reemplaza std::vector y std::list)
// ==========================================
class ListaEstudiantes {
private:
    Nodo* cabeza;
    int cantidad;

public:
    ListaEstudiantes();
    ~ListaEstudiantes();
    
    void agregar(const Estudiante& e);
    bool eliminar(const std::string& nombre);
    Estudiante* buscar(const std::string& nombre) const;
    
    // Iteracion basica
    Nodo* getCabeza() const;
    int tamano() const;
    bool vacia() const;
    void limpiar();
};

// ==========================================
// 2. PILA DINAMICA (Reemplaza std::stack)
// LIFO: Last In, First Out
// ==========================================
class PilaEstudiantes {
private:
    Nodo* tope;
    int cantidad;

public:
    PilaEstudiantes();
    ~PilaEstudiantes();
    
    void apilar(const Estudiante& e); // push
    Estudiante desapilar();           // pop
    Estudiante verTope() const;       // top
    
    bool vacia() const;
    int tamano() const;
};

// ==========================================
// 3. COLA DINAMICA (Reemplaza std::queue)
// FIFO: First In, First Out
// ==========================================
class ColaEstudiantes {
private:
    Nodo* frente;
    Nodo* final;
    int cantidad;

public:
    ColaEstudiantes();
    ~ColaEstudiantes();
    
    void encolar(const Estudiante& e); // push (al final)
    Estudiante desencolar();           // pop (del frente)
    Estudiante verFrente() const;      // front
    
    bool vacia() const;
    int tamano() const;
};

#endif
