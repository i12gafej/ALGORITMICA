#include <iostream>
#include "ClaseTiempo.hpp"
#include "seleccion.hpp"
#include "funciionesOrdenacion.hpp"

using namespace std;


int main(){
    int opt = -1;
    while(opt != 0){
        cout << "¿Qué desea hacer?"<<endl;
        cout<< "1 ) ordenar seleccion"<<endl;
        cout<< "2 ) Matriz cuadrado"<<endl;
        cout<< "3 ) fibnacci Recursivo"<<endl;
        cout << "0) Salir"<<endl;
        cin >> opt;
        switch(opt){
            case 1:
                ordenacionSeleccion();
                break;
            case 2:
                //void matrizCuadrado();
                break;
            case 3:
                //void fibonacciRecursivo();
                break;
        }
    }
}   