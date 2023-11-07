#include "funciionesOrdenacion.hpp"
#include "ClaseTiempo.hpp"
#include <ctime>
#include <stdlib.h>

void tiemposOrdenacionSeleccion(int nMin, int nMax,int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos){
    Clock time;
    for(int i = nMin; i <= nMax; i += incremento){
        std::vector<int> v(i);
        double tiempoAcumulado = 0;
        for(int j = 0; j < repeticiones; j++){
            rellenarVector(v);
            time.start();
            ordenacionSeleccion(v);
            time.stop();
            tiempoAcumulado += time.elapsed();
        }
        tiemposReales.push_back(tiempoAcumulado/repeticiones);
        std::cout<<" n = "<<i<<" // tiempo = "<<tiempoAcumulado/repeticiones<<std::endl;
        numeroElementos.push_back(i);
    }
}

void rellenarVector(vector<int> &v){
    srand(time(nullptr));
    for(int i = 0; i < v.size(); i++){
        v[i] = rand() % 10000000;
    }
}
void ordenacionSeleccion(vector<int> &v){
    for(int i = 0; i < v.size() -1 ; i++){
        int pos = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[j] < v[pos]){
                pos = j;
            }
        }
        int aux = v[i];
        v[i] = v[pos];
        v[pos]  = aux;
    }
}

void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados){
    
}
//bool estaOrdenado(const vector <int> &v){

//}