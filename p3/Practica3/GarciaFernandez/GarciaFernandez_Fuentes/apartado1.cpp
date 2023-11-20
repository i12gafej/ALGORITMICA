#include "apartado1.hpp"
#include "moneda.hpp"

#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>

void problemaCambio(){
    vector<Moneda> sistemaMonetario;
    vector<int> solucion;
    int centimos;

    cout << "Introduce la cantidad a cambiar en centimos" << endl;
    cin >> centimos;

    cargarSistemaMonetario(sistemaMonetario, "sistemamonetario.txt");
    cout << "Sistema monetario cargado"<<endl;
    cambio(centimos, sistemaMonetario, solucion);
    escribirSolucion(solucion, sistemaMonetario);
    
}

void cargarSistemaMonetario(vector <Moneda> &sistemaMonetario, const char* nombreFichero){
    ifstream f(nombreFichero);
    int linea;
    while(f >> linea){
        Moneda moneda(linea);
        sistemaMonetario.push_back(moneda);
    }
    f.close();
}

void cambio(int cantidad, vector <Moneda> sistemaMonetario, vector<int>& solucion){
    int resto = cantidad;
    
    for(int j = 0; j < sistemaMonetario.size(); j++){
            //las soluciones son el resto entre el valor de la moneda mas grande
        solucion.push_back(resto / sistemaMonetario[j].getValor());
            //lo que sobra de dicha operación, es la cantidad de monedas a seguir operando
        resto = resto % sistemaMonetario[j].getValor();
    }
}
void escribirSolucion(vector<int> &solucion, vector <Moneda> &sistemaMonetario){
    cout << "--------------------------------------------------------"<<endl;
    cout << "                      Solución "<<endl;
    cout << "--------------------------------------------------------"<<endl;
    int acumulado = 0;
    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i] != 0){
            acumulado += solucion[i]*sistemaMonetario[i].getValor();
            cout << "De " << sistemaMonetario[i].getValor() <<" hay "<< solucion[i] << ".   Acumulado = "<<acumulado<<endl;
        }
    }
    cout << "--------------------------------------------------------"<<endl;
}