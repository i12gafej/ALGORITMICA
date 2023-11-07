#include "medioNivel.hpp"
#include <iostream>
using namespace std;

void 
comparacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, int nElementosMinimo){
    vector<double> tiemposRealesQS1;
    vector<double> tiemposRealesQS2;
    vector<int> numeroElementos = vector<int>();


    tiemposOrdenacionVariantesQuicksort(nMin, nMax, incremento, repeticiones, nMediana, nElementosMinimo, tiemposRealesQS1, tiemposRealesQS2, numeroElementos);
}
