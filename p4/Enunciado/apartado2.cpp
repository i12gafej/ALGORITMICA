#include "apartado2.hpp"
#include "materialUsado.hpp"
#include "material.hpp"

#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>

void problemaMochila(){
    vector<Material> materiales;
    vector<MaterialUsado> solucion;
    float volumen;

    cout << "Introduzca el volumen de la mochila: ";
    cin >> volumen;
    cargarMateriales(materiales, "materialesmochila.txt");
    mochila(volumen, materiales, solucion);
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
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado> &solucion){
    sort(materiales.begin(), materiales.end(), [](Material& a, Material& b) {return a.getPrecio() > b.getPrecio();});
    float resto = volumenMochila;

    for(size_t i = 0; i < materiales.size(); i++){
        if(resto == materiales[i].getVolumen()){
            MaterialUsado aux(materiales[i], materiales[i].getVolumen());
            solucion.push_back(aux);
        }else if(resto > 0){
            MaterialUsado aux(materiales[i], resto);
            solucion.push_back(aux);
        }else{
            MaterialUsado aux(materiales[i],0.0);
            solucion.push_back(aux);
        }
        resto -= materiales[i].getVolumen();
    }
}
void escribirSolucion(vector<MaterialUsado> &solucion){
    float total = 0.0;
    for(auto i = solucion.begin(); i != solucion.end(); i++){
        total += i->getMaterial().getPrecio()*i->getVolumenUsado();
        cout << "Material <"<<i->getMaterial().getEtiqueta()<<"> con volumen "<<i->getVolumenUsado()<<" tiene un precio de "<<i->getMaterial().getPrecio()*i->getVolumenUsado()<<endl;
    }
    cout << "El valor total en la mochila es "<<total<<" unidades monetarias"<<endl;
}