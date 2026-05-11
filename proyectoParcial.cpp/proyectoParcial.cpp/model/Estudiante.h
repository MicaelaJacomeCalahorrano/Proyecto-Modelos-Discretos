#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

using namespace std;

class Estudiante {
private:
    string nombre;
    double promedio;
    double asistencia;
    bool tareasCompletas;

public:
    Estudiante(string nombre = "", double promedio = 0, 
               double asistencia = 0, bool tareas = false);
    
    // Getters
    string getNombre() const;
    double getPromedio() const;
    double getAsistencia() const;
    bool getTareasCompletas() const;
    
    // Setters
    void setNombre(const string& nombre);
    void setPromedio(double promedio);
    void setAsistencia(double asistencia);
    void setTareasCompletas(bool tareas);

    // Proposiciones Lógicas
    bool evaluarP() const; // P: Promedio >= 7
    bool evaluarQ() const; // Q: Asistencia >= 80%
    bool evaluarR() const; // R: Entregó tareas
};

#endif