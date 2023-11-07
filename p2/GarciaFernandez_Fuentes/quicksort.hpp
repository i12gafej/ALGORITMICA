#include "funcionesBasicas.hpp"
#include "ClaseTiempo.hpp"
void
quicksort1(int izquierda, int derecha, vector<double> &v);
void
quicksort2(int izquierda, int derecha, vector<double> &v, int nEleMinimo, int nEleMediana);
int
calcularMediana(vector<double> v, int n, int de, int iz);
void 
tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, 
int nElementosMinimo, vector <double> &tiemposRealesQS1, vector <double> &tiemposRealesQS2, vector <int> &numeroElementos);