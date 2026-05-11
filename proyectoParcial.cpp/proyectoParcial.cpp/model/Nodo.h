#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

// Estructura basica de un Nodo para listas, pilas y colas
struct Nodo {
  Estudiante dato;
  Nodo *siguiente;

  // Constructor basico
  Nodo(Estudiante e) {
    dato = e;
    siguiente = nullptr;
  }
};

#endif
