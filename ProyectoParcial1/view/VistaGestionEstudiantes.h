#ifndef VISTA_GESTION_ESTUDIANTES_H
#define VISTA_GESTION_ESTUDIANTES_H

#include "../model/Estudiante.h"
#include <vector>
#include <string>

// Persona 1: solo muestra datos de estudiantes y menús de gestión
class VistaGestionEstudiantes {
public:
    void mostrarMenu();
    int leerOpcion();
    
    Estudiante leerDatosEstudiante();
    std::string leerNombre();
    
    void mostrarLista(const std::vector<Estudiante>& estudiantes);
    void mostrarEstudiante(const Estudiante& e);
    void mostrarMensaje(const std::string& msg);
    void mostrarError(const std::string& msg);
    void mostrarExito(const std::string& msg);
    void pausa();
};

#endif