#include "funcionesBasicas.hpp"

void
ordenacionSeleccion(std::vector<int> &v);
bool 
estaOrdenado(const std::vector <int> &v);
void 
tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int
repeticiones, std::vector <double> &tiemposReales, std::vector <double>
&numeroElementos);
void 
ajusteCuadratico(const std::vector <double>
&numeroElementos, const std::vector <double> &tiemposReales, std::vector <double>
&a);
void
calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
double
calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a);