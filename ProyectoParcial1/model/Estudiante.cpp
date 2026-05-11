#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, double promedio, double asistencia, bool tareas)
    : nombre(nombre), promedio(promedio), asistencia(asistencia), tareasCompletas(tareas) {}

std::string Estudiante::getNombre() const { return nombre; }
double Estudiante::getPromedio() const { return promedio; }
double Estudiante::getAsistencia() const { return asistencia; }
bool Estudiante::getTareasCompletas() const { return tareasCompletas; }

void Estudiante::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Estudiante::setPromedio(double promedio) { this->promedio = promedio; }
void Estudiante::setAsistencia(double asistencia) { this->asistencia = asistencia; }
void Estudiante::setTareasCompletas(bool tareas) { this->tareasCompletas = tareas; }