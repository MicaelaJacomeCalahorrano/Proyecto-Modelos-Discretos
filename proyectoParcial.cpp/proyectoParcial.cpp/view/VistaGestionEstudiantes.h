#ifndef VISTA_GESTION_ESTUDIANTES_H
#define VISTA_GESTION_ESTUDIANTES_H

#include "../model/Estudiante.h"
#include "../model/Nodo.h"
#include <string>

// Persona 1: solo muestra datos de estudiantes y menus de gestion
// Ahora funciona iterando sobre memoria dinamica via Nodos
class VistaGestionEstudiantes {
public:
    void mostrarMenu();
    int leerOpcion();
    
    // Metodos para ingreso y visualizacion de datos base
    Estudiante leerDatosEstudiante();
    std::string leerNombre();
    
    void mostrarLista(Nodo* cabeza);
    void mostrarEstudiante(const Estudiante& estudiante);
    
    void mostrarMensaje(const std::string& mensaje);
    void mostrarError(const std::string& mensajeError);
    void mostrarExito(const std::string& mensajeExito);
    void pausa();
    
    // Metodos para el sistema de inferencia logica
    void mostrarTablaVerdad(const Estudiante& e, const std::string& estadoDeducido);
    void mostrarOperacionConjuntos(const std::string& nombreOperacion, Nodo* cabeza);
    void mostrarResumen(int total, int aprobados, int recuperacion, int reprobados);
};

#endif