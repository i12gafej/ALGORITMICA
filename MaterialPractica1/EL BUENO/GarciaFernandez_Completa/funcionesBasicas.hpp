#ifndef FB
#define FB
#include "sistemaEcuaciones.hpp"
#include "ClaseTiempo.hpp"
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iostream> 
#include <vector>

void
rellenarVector(std::vector<int> &v);
void 
imprimirColumnasTRTEyNE(std::string filename, std::vector <double> &numeroElementos, std::vector <double>
&tiemposReales, std::vector <double> &tiemposEstimados);
double 
sumatorio(const std::vector <double> &n, const std::vector <double> &t,
int expN, int expT);
double 
varianza (std::vector<double> v, double media);
double 
calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, const std::vector <double> &tiemposEstimados);
void 
imprimir(std::string ecuacion, double t);

#endif