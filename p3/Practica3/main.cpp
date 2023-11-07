#include "apartado1.hpp"
#include <iostream>

using namespace std;
//usando division entera se puede resolver con un esquema for
void problemaCambio();

void problemaMochila();

int main(){
    bool salir = true;
    int opt;

    while(salir){
        cout << "1) Problema del cambio"<<endl;
        cout << "2) Problema de la mochila"<<endl;
        cout << "0) Salir"<<endl;
        cout << "Tu opcion: ";
        
        cin>>opt;
        cout << endl;
        switch(opt){
            case 0: 
                salir = false;
                break;
            case 1:
                problemaCambio();
                break;
            case 2:
                //problemaMochila();
                break;
        }
    }
    
    return 0;
}