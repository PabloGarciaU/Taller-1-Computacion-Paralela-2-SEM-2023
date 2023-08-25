#include <iostream>
#include <cstdlib>

using namespace std;

// Variables utilizadas
int bucle = 0;
int opcion;
int ancho;
int largo;

// Funciones utilizadas

void menu(){
    system("cls");
    cout<<"---- Menu Taller 1 ----"<<endl;
    cout<<"1. Generar y resolver un laberinto aleatorio"<<endl;
    cout<<"2. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    switch(opcion){
        case 1:
            system("cls");
            cout<<"Ingrese el tamñao del laberinto (Min 10x10, Max 50x50)"<<endl;
            cout<<"Ancho: ";
            cin>>ancho;
            cout<<"Largo: ";
            cin>>largo;
            if(ancho < 10 || largo < 10 || ancho > 50 || largo > 50){
                system("cls");
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