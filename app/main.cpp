#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

/*

Info

*/

// Variables utilizadas
int bucle = 0;
int opcion;
int filas;
int columnas;

bool solveMaze(int **matriz, int x, int y, int endX, int endY) {
    if (x < 0 || y < 0 || x >= columnas || y >= filas || matriz[y][x] != 0)
        return false;

    matriz[y][x] = 2; // Marcar como visitado

    if (x == endX && y == endY)
        return true;

    if (solveMaze(matriz, x + 1, y, endX, endY) ||
        solveMaze(matriz, x, y + 1, endX, endY) ||
        solveMaze(matriz, x - 1, y, endX, endY) ||
        solveMaze(matriz, x, y - 1, endX, endY))
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

    // Generar laberinto aleatorio
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 2; // 0 para espacio libre, 1 para pared
        }
    }

    // Marcar la entrada y la salida
    matriz[0][1] = 0;                   // Entrada
    matriz[filas - 1][columnas - 2] = 0; // Salida

    // Resolver el laberinto
    solveMaze(matriz, 1, 0, columnas - 2, filas - 1);

    // Imprimir el laberinto con el camino más eficiente
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 1) {
                cout << "#"; // Pared
            } else if (matriz[i][j] == 0) {
                cout << "  "; // Espacio libre
            } else if (matriz[i][j] == 2) {
                cout << "O "; // Camino más eficiente
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

// Funcion del menu principal

void menu(){
    system("cls");
    cout<<"---- Menu Taller 1 ----"<<endl;
    cout<<"Programado por Pablo Garcia Urzua"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Computacion paralela y distribuida, seccion 411"<<endl;
    cout<<"1. Generar un laberinto aleatorio"<<endl;
    cout<<"2. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    switch(opcion){
        case 1:
            system("cls");
            cout<<"Ingrese el tamñao del laberinto (Min 10x10, Max 50x50)"<<endl;
            cout<<"Ancho: ";
            cin>>columnas;
            cout<<"Largo: ";
            cin>>filas;
            system("cls");
            cout<<"Generando laberinto..."<<endl;
			generaryresolverLaberinto(filas, columnas);
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"Saliendo....."<<endl;
			bucle++;
            break;
        default:
            system("cls");
            cout<<"Opcion no valida"<<endl;
            break;
    }
}

int main() {
   while(bucle == 0){
       menu();
   }
}