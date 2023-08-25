#include <iostream>
#include <cstdlib>

using namespace std;

// Variables utilizadas
int bucle = 0;
int opcion;
int filas;
int columnas;
int const densidad = 1;

// Funciones utilizadas para crear y resolver el laberinto

void generarLaberinto(int filas, int columnas, int densidad){
    int **matriz;
	matriz = new int *[filas];

	int FParedes = densidad * 8; 
	densidad = filas*columnas*densidad / 4;

	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[columnas];
	}
	//valores
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) {
				matriz[i][j] = 1;
			}
			else {
				matriz[i][j] = 0; 
			}
		}
	}
	//laberinto 
	srand(time(NULL));
	for (int i = 0; i < densidad; i++) {
		int x = rand() % (columnas - 4) + 2; // 2 18 
		x = (x / 2) * 2; 
		int y = rand()% (filas - 4) + 2;
		y = (y / 2) * 2;
		matriz[y][x] = 1; 
		for (int j = 0; j < FParedes; j++) {
			int mx[4] = { x,  x,  x + 2, x - 2 };
			int my[4] = { y + 2,y - 2, y ,  y };
			int r = rand() % 4;
			if (matriz[my[r]][mx[r]] == 0) {
				matriz[my[r]][mx[r]] = 1; 
				matriz[my[r] +( y - my[r])/2][mx[r]+(x- mx[r])/2] = 1;
			}
				
		}
	}
	//pintar
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] == 1) {
				char a = 178; 
				cout << a << a; 
			}
			if(matriz[i][j] == 0) {
				cout << "  ";
			}
		}
		cout << "\n"; 
	}
}

// Funcion del menu principal

void menu(){
    system("cls");
    cout<<"---- Menu Taller 1 ----"<<endl;
    cout<<"Programado por Pablo Garcia Urzua"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Computacion paralela y distribuida, seccion 411"<<endl;
    cout<<"1. Generar y resolver un laberinto aleatorio"<<endl;
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
            if(columnas < 10 || filas < 10 || columnas > 50 || filas > 50){
                cout<<"El tamaño ingresado no es valido"<<endl;
                system("pause");
                break;
            }
            else{
                system("cls");
                cout<<"Generando laberinto..."<<endl;
                system("pause");
                break;
            }
            break;
        case 2:
            system("cls");
            cout<<"Salir"<<endl;
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