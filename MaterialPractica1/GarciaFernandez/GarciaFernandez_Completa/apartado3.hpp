#include "funcionesBasicas.hpp"

double 
fibonacci(double n);
void 
tiemposFibonacci(int nMin, int nMax, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos, int inc);
void 
ajusteExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a);
void
calcularTiemposEstimadosExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
double
calcularTiempoEstimadoExponencial(const double &n, const vector <double> &a);
void 
cambioVariable(const std::vector<double> &n, std::vector<double> &z);