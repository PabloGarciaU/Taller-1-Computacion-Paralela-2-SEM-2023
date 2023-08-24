#include <iostream>
#include <cstdlib>

using namespace std;

// Variables utilizadas
int bucle = 0;
int opcion;

// Funciones utilizadas

void menu(){
    system("cls");
    cout<<"---- Menu Taller 1 ----"<<endl;
    cout<<"1. Generar y resolver un laberinto aleatorio"<<endl;
    cout<<"2. Salir"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1:
            system("cls");
            cout<<"Generar y resolver un laberinto aleatorio"<<endl;
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