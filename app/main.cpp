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

// Funcion para generar y resolver el laberinto, se basa en el algoritmo de busqueda de profundidad

void solveMaze(int **matriz, int filas, int columnas, int x, int y) {
    if (x < 0 || y < 0 || x >= columnas || y >= filas)
        return;

    if (matriz[y][x] != 0)
        return;

    matriz[y][x] = 2; // Marcamos como visitado

    solveMaze(matriz, filas, columnas, x + 1, y);
    solveMaze(matriz, filas, columnas, x - 1, y);
    solveMaze(matriz, filas, columnas, x, y + 1);
    solveMaze(matriz, filas, columnas, x, y - 1);
}

// Funcion para generar y resolver el laberinto



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
			//generaryresolverLaberinto(filas, columnas);
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