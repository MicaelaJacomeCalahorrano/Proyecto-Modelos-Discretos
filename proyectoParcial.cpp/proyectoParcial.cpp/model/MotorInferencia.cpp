#include "MotorInferencia.h"

using namespace std;

EstadoAcademico MotorInferencia::deducirEstado(const Estudiante &estudiante) {
  bool p = estudiante.evaluarP();
  bool q = estudiante.evaluarQ();
  bool r = estudiante.evaluarR();

  // Reglas de Inferencia (Actualizadas con R):
  // Si P AND Q AND R, el estudiante aprueba.
  // Si (!P AND Q) OR (P AND Q AND !R), el estudiante pasa a recuperacion.
  // Si no cumple asistencia (!Q), reprueba directamente.

  if (p && q && r) {
    return APROBADO;
  } else if ((!p && q) || (p && q && !r)) {
    return RECUPERACION;
  } else {
    return REPROBADO;
  }
}

string MotorInferencia::estadoToString(EstadoAcademico estado) {
  switch (estado) {
  case APROBADO:
    return "Aprueba";
  case RECUPERACION:
    return "Recuperacion";
  case REPROBADO:
    return "Reprueba";
  default:
    return "Desconocido";
  }
}
