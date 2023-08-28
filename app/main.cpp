#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>

using namespace std;

int bucle = 0;
int opcion;
int filas;
int columnas;
double densidad;

bool resolverlaberinto(int **matriz, int x, int y, int endX, int endY) {
    if (x < 0 || y < 0 || x >= columnas || y >= filas || matriz[y][x] != 0)
        return false;

    matriz[y][x] = 2; // Marcar como visitado

    if (x == endX && y == endY)
        return true;

    if (resolverlaberinto(matriz, x + 1, y, endX, endY) ||
        resolverlaberinto(matriz, x, y + 1, endX, endY) ||
        resolverlaberinto(matriz, x - 1, y, endX, endY) ||
        resolverlaberinto(matriz, x, y - 1, endX, endY))
        return true;

    matriz[y][x] = 0; // Marcar como no visitado (backtracking)
    return false;
}

void generaryresolverLaberinto(int filas, int columnas, double densidad) {
    int **matriz;
    matriz = new int *[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    bool laberintoEncontrado = false;

    while (!laberintoEncontrado) {
        srand(time(NULL));
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                double randomValue = static_cast<double>(rand()) / RAND_MAX;
                matriz[i][j] = randomValue < densidad ? 1 : 0; // Obstáculo con probabilidad densidad
            }
        }

        // Marcar la entrada y la salida
        matriz[0][1] = 0;                   // Entrada
        matriz[filas - 1][columnas - 2] = 0; // Salida

        int startX = 1;
        int startY = 0;
        int endX = columnas - 2;
        int endY = filas - 1;

        // Resolver el laberinto
        laberintoEncontrado = resolverlaberinto(matriz, startX, startY, endX, endY);
    }

    // Crear y escribir en el archivo de texto
    ofstream archivo("laberinto_resuelto.txt");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 1) {
                archivo << '#'; // Pared
            } else if (matriz[i][j] == 0) {
                archivo << ' '; // Espacio libre
            } else if (matriz[i][j] == 2) {
                archivo << 'o'; // Camino más eficiente
            }
        }
        archivo << "\n";
    }
    archivo.close();

    // Imprimir mensaje de confirmación
    cout << "Laberinto resuelto guardado en 'laberinto_resuelto.txt'" << endl;

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void menu() {
    system("cls");
    cout << "---- Menu Taller 1 ----" << endl;
    cout << "Programado por Pablo Garcia, Victor toledo, Fabian Rojas // Computacion paralela y distribuida, seccion 411" << endl << endl;
    cout << "------------------------" << endl;
    cout << "El programa se basa en el algoritmo de busqueda de profundidad (DFS - Depth First Seach)" << endl;
    cout <<"------------------------" << endl << endl;
    cout << "Seleccione una opcion" << endl;
    cout << "1. Generar un laberinto aleatorio y resolverlo con una posible solucion" << endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            system("cls");
            densidad = 0.3; // constante importante para que el algoritmo funcione
            cout << "Ingrese los parametros del laberinto (Min 5x5, Max 50x50)" << endl;
            cout << "Ancho: ";
            cin >> columnas;
            cout << "Alto: ";
            cin >> filas;
            if(filas){
                system("cls");
                cout << "Generando laberinto..." << endl;
                generaryresolverLaberinto(filas, columnas, densidad);
                cout << "Laberinto generado y resuelto" << endl;
                cout << "Guardado en laberinto_resuelto.txt" << endl;
                system("pause");
            }
            else{
                system("cls");
                cout << "Ingrese un valor valido" << endl;
                system("pause");
            }
            break;
        case 2:
            system("cls");
            cout << "Saliendo....." << endl;
            bucle++;
            break;
        default:
            system("cls");
            cout << "Opcion no valida, intentelo nuevamente" << endl;
            system("pause");
            break;
    }
}

int main() {
    while (bucle == 0) {
        menu();
    }
}