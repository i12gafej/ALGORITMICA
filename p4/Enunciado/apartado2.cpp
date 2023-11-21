#include "apartado2.hpp"
#include "materialUsado.hpp"
#include "material.hpp"

#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <limits>

void problemaMochila(){
    vector<Material> materiales;
    vector<MaterialUsado> solucion;
    vector<vector<double>> matrizEstimados;
    float volumen;

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
    for(int i = 0; i < matrizEstados.size(); i++){
        for(int j = 0; j < matrizEstados[0].size(); j++){
            cout << matrizEstados[i][j] << " ";
        }
        cout << endl;
    }
}
void obtenerSolucion(vector<vector<double>>& matrizEstados, vector<Material>& materiales, vector<MaterialUsado> &solucion){
    int i = matrizEstados.size() - 1, j = matrizEstados[0].size() - 1;

    while(i > 0){
        if(j - materiales[i].getVolumen() < 0){
            j = 0;
        }
        if(matrizEstados[i][j] == matrizEstados[i - 1][j] && 
        matrizEstados[i][j] != matrizEstados[i - 1][j - materiales[i].getVolumen()] + materiales[i].getPrecio()*materiales[i].getVolumen()){
            i--;
            j -= materiales[i].getVolumen();
            cout << materiales[i].getEtiqueta()<<" no está"<<endl;
        }
        else if(matrizEstados[i][j] != matrizEstados[i - 1][j] && 
        matrizEstados[i][j] == matrizEstados[i - 1][j - materiales[i].getVolumen()] + materiales[i].getPrecio()*materiales[i].getVolumen()){
            solucion.push_back(MaterialUsado(materiales[i], materiales[i].getVolumen()));
            i--;
            j -= materiales[i].getVolumen();
            cout << materiales[i].getEtiqueta()<<" está"<<endl;
        }
    }
    /*if(C(i, j) == C(i - 1, j) && C(i, j) != C(i - 1, j - vi)+pi∗vi)
        i - - 
        j - = j - vi
    else if(C(i, j) != C(i - 1, j) && C(i, j) = C(i - 1, j−vi)+pi∗vi)
    solucion i = mi
    i - -
    j - = j - vi*/

}
void escribirSolucion(vector<MaterialUsado> &solucion){
    float total = 0.0;
    for(auto i = solucion.begin(); i != solucion.end(); i++){
        total += i->getMaterial().getPrecio()*i->getVolumenUsado();
        cout << "Material <"<<i->getMaterial().getEtiqueta()<<"> con volumen "<<i->getVolumenUsado()<<" tiene un precio de "<<i->getMaterial().getPrecio()*i->getVolumenUsado()<<endl;
    }
    cout << "El valor total en la mochila es "<<total<<" unidades monetarias"<<endl;
}