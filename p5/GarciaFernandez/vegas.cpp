#include "vegas.hpp"
#include "ClaseTiempo.hpp"
#include "backtracking.hpp"

#include <vector>
#include <iostream>
#include <cstdlib> //para rand

#include <unistd.h> //para system("clear")
using namespace std;


void nReinasVegas(){
    system("clear");
    cout << "Introduce el numero de reinas: ";
    int n;
    cin >> n;
    vector<int> solucion;
    Clock time;
    time.start();
    int contador = repetir(n, solucion);
    time.stop();
    escribirSolucion(solucion);
    cout << "Numero de intentos: " << contador << endl;
    cout << "------------------------------------" << endl;
    tiempo(time.elapsed());
    cout << endl;
}
int repetir(int n, vector<int>&x){
    int contador = 0;
    bool exito = false;
    do{
        exito = nReinasLasVegas(n, x);
        contador++;
    } while(!exito);
    return contador;
}
bool nReinasLasVegas( int n, vector<int >&solucion){
    //vector<int> x = vector<int>(n, 0);
    solucion = vector<int>(n, 0);
    
    for(int k = 0; k < n; k++){
        //recorremos n posiciones y contador fuera
        int contador = -1;
        vector<int> ok = vector<int>(n, 0);
        for(int j = 0; j < n; j++){
            //podemos que la solucion en la fila k sea la columna j
            solucion[k] = j;
            //si es solucion
            if(lugar(k, solucion)){
                //nos vamos a la siguiente fila
                contador++;
                //guardamos la columna j como posible solucion
                ok[contador] = j;
            }
        }
        if(contador == -1){
            //no hay solucion
            return false;
        }
        //elegimos una columna aleatoria de las posibles
        int columna = ok[rand() % (contador + 1)];
        solucion[k] = columna;
    }
    return true;
}

