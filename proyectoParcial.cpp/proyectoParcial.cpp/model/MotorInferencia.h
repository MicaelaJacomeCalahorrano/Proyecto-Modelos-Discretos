#ifndef MOTOR_INFERENCIA_H
#define MOTOR_INFERENCIA_H

#include "Estudiante.h"
#include <string>

using namespace std;

enum EstadoAcademico {
    APROBADO,
    RECUPERACION,
    REPROBADO
};

class MotorInferencia {
public:
    // Aplica las reglas lógicas y devuelve el estado
    static EstadoAcademico deducirEstado(const Estudiante& estudiante);
    static string estadoToString(EstadoAcademico estado);
};

#endif
