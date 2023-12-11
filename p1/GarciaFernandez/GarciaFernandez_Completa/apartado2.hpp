#include <random>
#include "funcionesBasicas.hpp"

void
rellenarManualMatriz(std::vector<std::vector<double>> &m, int n);
void
rellenarAutomaticoMatriz(std::vector<std::vector<double>> &m, int n);
void
ajusteCubico(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a);
void 
tiemposMatrizCuadrada(int nMin, int nMax, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos, int inc);
double
calcularTiempoEstimadoMatriz(const double &n, const vector <double> &a);
void 
calcularTiemposEstimadosCubico(const std::vector<double> &numeroElementos, const std::vector<double> &a, std::vector<double>& tiemposEstimados);