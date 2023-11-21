#include "apartado1.hpp"
#include "moneda.hpp"

#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <unistd.h>
#include <algorithm>

void problemaCambio(){
    vector<Moneda> sistemaMonetario;
    vector<vector <int>> matrizEstados;
    vector<int> solucion;
    int centimos;
    system("clear");
    cout << "Introduce la cantidad a cambiar en centimos: ";
    cin >> centimos;

    cargarSistemaMonetario(sistemaMonetario, "sistemamonetario.txt");
    cout << "Sistema monetario cargado"<<endl;
    cambio(centimos, sistemaMonetario, matrizEstados);
    obtenerSolucion(matrizEstados, sistemaMonetario, solucion);
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
    
    matrizEstados = vector<vector<int>>(sistemaMonetario.size(), vector<int>(cantidad + 1));
    for(int i = 0; i<sistemaMonetario.size(); i++){
        for(int j = 0; j < cantidad; j++){
            if(j == 0)
                matrizEstados[i][j] = 0;
            else
                matrizEstados[i][j] = std::numeric_limits<int>::max();
        }
    }
    for(int i = 0; i <= sistemaMonetario.size() - 1; i++){
        for(int j = 1; j <= cantidad; j++){
            if(i == 0)
                matrizEstados[i][j] = 1 + matrizEstados[i][j - sistemaMonetario[0].getValor()];
            else{
                if(j < sistemaMonetario[i].getValor()){
                    matrizEstados[i][j] = matrizEstados[i - 1][j];
                }
                else{
                    matrizEstados[i][j] = min(matrizEstados[i - 1][j], 1 + matrizEstados[i][j - sistemaMonetario[i].getValor()]);
                }
            }
            
        }
    } 
}
void obtenerSolucion(vector<vector <int>>& matrizEstados, vector <Moneda> &sistemaMonetario, vector<int> &solucion){
    solucion = vector<int>(sistemaMonetario.size(), 0);
    int i = sistemaMonetario.size() - 1, j = matrizEstados[0].size() - 1;
    
    while(i > 0){
        if(matrizEstados[i][j] == matrizEstados[i - 1][j]){
            i--;
        }    
        else if(matrizEstados[i][j] == 1 + matrizEstados[i][j - sistemaMonetario[i].getValor()]){
            solucion[i] = solucion[i] + 1;
            j -= sistemaMonetario[i].getValor();
        }
        if(j == 1 && i == 0){
            solucion[i] = 1;
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