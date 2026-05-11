#include "Estudiante.h"

using namespace std;

Estudiante::Estudiante(string nombre, double promedio, double asistencia, bool tareas)
    : nombre(nombre), tareasCompletas(tareas) {
    setPromedio(promedio);
    setAsistencia(asistencia);
}

string Estudiante::getNombre() const { return nombre; }
double Estudiante::getPromedio() const { return promedio; }
double Estudiante::getAsistencia() const { return asistencia; }
bool Estudiante::getTareasCompletas() const { return tareasCompletas; }

void Estudiante::setNombre(const string& nombre) { this->nombre = nombre; }
void Estudiante::setPromedio(double promedio) { 
    if (promedio >= 0.0 && promedio <= 10.0) {
        this->promedio = promedio;
    } else {
        this->promedio = 0.0;
    }
}
void Estudiante::setAsistencia(double asistencia) { 
    if (asistencia >= 0.0 && asistencia <= 100.0) {
        this->asistencia = asistencia;
    } else {
        this->asistencia = 0.0;
    }
}
void Estudiante::setTareasCompletas(bool tareas) { this->tareasCompletas = tareas; }

bool Estudiante::evaluarP() const { return promedio >= 7.0; }
bool Estudiante::evaluarQ() const { return asistencia >= 80.0; }
bool Estudiante::evaluarR() const { return tareasCompletas; }