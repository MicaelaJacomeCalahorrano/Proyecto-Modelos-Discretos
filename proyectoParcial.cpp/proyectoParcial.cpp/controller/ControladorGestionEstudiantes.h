#ifndef CONTROLADOR_GESTION_ESTUDIANTES_H
#define CONTROLADOR_GESTION_ESTUDIANTES_H

#include "../model/RepositorioEstudiantes.h"
#include "../model/ConjuntoEstudiantes.h"
#include "../model/MotorInferencia.h"
#include "../view/VistaGestionEstudiantes.h"
#include "../model/EstructurasDinamicas.h"

class ControladorGestionEstudiantes {
private:
    RepositorioEstudiantes repositorio;
    VistaGestionEstudiantes vista;
    
    // Conjuntos Logicos
    ConjuntoEstudiantes conjuntoA; // Aprobados
    ConjuntoEstudiantes conjuntoB; // Recuperacion
    ConjuntoEstudiantes conjuntoC; // Reprobados
    
    // (HistorialAprobados fue eliminado para integrar Pila LIFO en la simulación de recuperación)

public:
    ControladorGestionEstudiantes();
    void ejecutar();
    
    // Metodos para el sistema
    void ejecutarMotorInferencia();
    void mostrarOperacionesConjuntos();
    void mostrarResumenFinal();
    void simularRecuperacion();
    
    // Metodos para que otras personas accedan a los datos
    RepositorioEstudiantes* getRepositorio();
};

#endif