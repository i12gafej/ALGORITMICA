#include "apartado1.hpp"
#include "moneda.hpp"

#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

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

void cambio(int cantidad, vector <Moneda> sistemaMonetario, vector<vector <int>>& matrizEstados){
    int resto = cantidad;
    
    matrizEstados = vector<vector<int>>(sistemaMonetario.size(), vector<int>(cantidad));
    for(int i = 0; i<sistemaMonetario.size(); i++){
        for(int j = 0; j < cantidad; j++){
            if(j == 0)
                matrizEstados[i][j] = 0;
            matrizEstados[i][j] = numeric_limits<int>::max();
        }
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