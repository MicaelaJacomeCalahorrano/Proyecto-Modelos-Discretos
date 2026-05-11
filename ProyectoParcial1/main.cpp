#include "controller/ControladorGestionEstudiantes.h"
#include <iostream>

int main() {
    ControladorGestionEstudiantes controlador;
    controlador.ejecutar();
    
    std::cout << "\nPresione Enter para salir...";
    std::cin.get();
    
    return 0;
}