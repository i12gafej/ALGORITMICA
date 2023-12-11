#include "apartado2.hpp"
#include "materialUsado.hpp"
#include "material.hpp"

#include <vector>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fstream>

void problemaMochila(){
    vector<Material> materiales;
    vector<MaterialUsado> solucion;
    vector<vector<double>> matrizEstimados;
    float volumen;

    system("clear");
    cout << "Introduzca el volumen de la mochila: ";
    cin >> volumen;
    cargarMateriales(materiales, "materialesmochila.txt");
    mochila(volumen, materiales, matrizEstimados);
    obtenerSolucion(matrizEstimados, materiales, solucion);
    escribirSolucion(solucion);

}

void cargarMateriales(vector<Material> &materiales, const char *nombreFichero){
    ifstream f(nombreFichero);
    int etiqueta, volumen, precio;
    while(f >> etiqueta >> volumen >> precio){
        Material material(etiqueta, volumen, precio);
        materiales.push_back(material);
    }
    f.close();
}
void mochila(float volumenMochila, vector<Material> &materiales, vector<vector <double>>& matrizEstados){
    matrizEstados = vector<vector<double>>(materiales.size(), vector<double>(volumenMochila + 1));
    for(int i = 0; i<materiales.size(); i++){
        matrizEstados[i][0] = 0;
    }
    for(int i = 0; i < volumenMochila + 1 ; i++){
        if(i < materiales[0].getVolumen()){
            matrizEstados[0][i] = 0;
        }
        else{
            matrizEstados[0][i] = materiales[0].getPrecio() * materiales[0].getVolumen();
        }
    }
    for(int i = 1; i < materiales.size(); i++){
        for(int j = 1; j < volumenMochila + 1; j++){
            if(j < materiales[i].getVolumen()){
                matrizEstados[i][j] = matrizEstados[i - 1][j];
            }
            else{
                matrizEstados[i][j] = max(matrizEstados[i-1][j] ,materiales[i].getPrecio() * materiales[i].getVolumen() + 
                matrizEstados[i - 1][j - materiales[i].getVolumen()]);
            }
        }
    }
}
void obtenerSolucion(vector<vector<double>>& matrizEstados, vector<Material>& materiales, vector<MaterialUsado> &solucion){
    int i = matrizEstados.size() - 1, j = matrizEstados[0].size() - 1;

    while(i >= 0){
        
        if(i > 0){ 

            if(matrizEstados[i][j] == matrizEstados[i - 1][j] && 
            matrizEstados[i][j] != matrizEstados[i - 1][j - materiales[i].getVolumen()] + materiales[i].getPrecio()*materiales[i].getVolumen()){
                i--;
            }             
            else if(matrizEstados[i][j] != matrizEstados[i - 1][j] && 
            matrizEstados[i][j] == matrizEstados[i - 1][j - materiales[i].getVolumen()] + materiales[i].getPrecio()*materiales[i].getVolumen()){
                solucion.push_back(MaterialUsado(materiales[i], materiales[i].getVolumen()));
                j -= materiales[i].getVolumen();  
                i--; // va al siguiente material porque solo se puede meter una vez
            }
        }
        else if(i == 0){ 

            if(matrizEstados[0][j] == matrizEstados[0][j - materiales[i].getVolumen()] + materiales[i].getPrecio()*materiales[i].getVolumen()){
                solucion.push_back(MaterialUsado(materiales[i], materiales[i].getVolumen()));
                j -= materiales[i].getVolumen();
            }
            i = -1; // sale del bucle
        }
    }
}
void escribirSolucion(vector<MaterialUsado> &solucion){
    float total = 0.0;
    cout << "--------------------------------------------------------"<<endl;
    cout << "                      Solución "<<endl;
    cout << "--------------------------------------------------------"<<endl;
    for(auto i = solucion.begin(); i != solucion.end(); i++){
        total += i->getMaterial().getPrecio()*i->getVolumenUsado();
        cout << "Material <"<<i->getMaterial().getEtiqueta()<<"> --> volumen <"<<i->getVolumenUsado()<<">           Coste = "<<i->getMaterial().getPrecio()*i->getVolumenUsado()<<"."<<endl;
    }
    cout << "--------------------------------------------------------"<<endl;
    cout << "El valor total en la mochila es "<<total<<" unidades monetarias"<<endl;
    cout << "--------------------------------------------------------"<<endl;
    cout << endl;
}
