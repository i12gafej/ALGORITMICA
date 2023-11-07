#include "medioNivel.hpp"


int main(){
    int opt = 0;
    do{
        std::cout<<"Que prefieres hacer?"<<std::endl;
        std::cout<<"1)        Ordenacion Selección"<<std::endl;
        std::cout<<"2)        Cuadrado de la matriz"<<std::endl;
        std::cout<<"3)        Fibonacci Recursivo"<<std::endl;
        std::cout<<"0)        Salir"<<std::endl;
        std::cin>>opt;
        switch(opt){
            case 1:
                ordenacionSeleccion();
                break;
            case 2:
                cuadradoMatriz();
                break;
            case 3:
                fibonacciRecursivo();
                break;
            default:
            return 0;
        }
    }while(opt > 0);
}