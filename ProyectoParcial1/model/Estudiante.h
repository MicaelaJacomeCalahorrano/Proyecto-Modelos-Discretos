#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombre;
    double promedio;
    double asistencia;
    bool tareasCompletas;

public:
    Estudiante(std::string nombre = "", double promedio = 0, 
               double asistencia = 0, bool tareas = false);
    
    // Getters
    std::string getNombre() const;
    double getPromedio() const;
    double getAsistencia() const;
    bool getTareasCompletas() const;
    
    // Setters
    void setNombre(const std::string& nombre);
    void setPromedio(double promedio);
    void setAsistencia(double asistencia);
    void setTareasCompletas(bool tareas);
};

#endif