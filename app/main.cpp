#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * Función que muestra los participantes del grupo
 * @param programa nombre del ejecutable
 */
void participantes(std::string programa);

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */

void laberinto(){

}

int main(int argc, char** argv) {

    /**
     * Incluir acá la lógica del programa
     * 
     */
    if (argc > 1) {
        // @TODO programar proyecto
    } else {
        // Mostrar los integrantes
        participantes(argv[0]);
    }
    return EXIT_SUCCESS;
}

void participantes(std::string programa) {
    std::cout << std::endl << "Taller 1: Resolucion de laberintos mediantes algoritmos" << std::endl;
    std::cout << std::endl << "Integrantes:" << std::endl;
    std::cout << std::endl << "- Pablo Garcia Urzua"; 
    std::cout << std::endl << "- Nombre"; 
    std::cout << std::endl << "- Nombre" << std::endl;
    std::cout << std::endl << "Todos los completos reservados ©" << std::endl;  
}
