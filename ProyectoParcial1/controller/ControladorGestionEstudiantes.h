#ifndef CONTROLADOR_GESTION_ESTUDIANTES_H
#define CONTROLADOR_GESTION_ESTUDIANTES_H

#include "../model/RepositorioEstudiantes.h"
#include "../view/VistaGestionEstudiantes.h"


class ControladorGestionEstudiantes {
private:
    RepositorioEstudiantes repositorio;
    VistaGestionEstudiantes vista;

public:
    void ejecutar();
    
    // Métodos para que otras personas accedan a los datos
    RepositorioEstudiantes* getRepositorio();
};

#endif