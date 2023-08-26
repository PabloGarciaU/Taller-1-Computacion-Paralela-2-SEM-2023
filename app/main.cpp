#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>

using namespace std;

int bucle = 0;
int opcion;
int filas;
int columnas;

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

void generaryresolverLaberinto(int filas, int columnas) {
    int **matriz;
    matriz = new int *[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 2; // 0 para espacio libre, 1 para pared
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
    resolverlaberinto(matriz, startX, startY, endX, endY);

    // Imprimir el laberinto con la entrada, salida y camino eficiente
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 1) {
                cout << '#'; // Pared
            } else if (matriz[i][j] == 0) {
                cout << ' '; // Espacio libre
            } else if (matriz[i][j] == 2) {
                cout << 'C'; // Camino más eficiente
            }
        }
        cout << "\n";
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void menu() {
    system("cls");
    cout << "---- Menu Taller 1 ----" << endl;
    cout << "Programado por Pablo Garcia Urzua" << endl;
    cout << "------------------------" << endl;
    cout << "Computacion paralela y distribuida, seccion 411" << endl;
    cout << "1. Generar un laberinto aleatorio y resolverlo con una posible solucion" << endl;
    cout << "2. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            system("cls");
            cout << "Ingrese los parametros del laberinto (Min 10x10, Max 50x50)" << endl;
            cout << "Ancho: ";
            cin >> columnas;
            cout << "Largo: ";
            cin >> filas;
            system("cls");
            cout << "Generando laberinto..." << endl;
            generaryresolverLaberinto(filas, columnas);
            system("pause");
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