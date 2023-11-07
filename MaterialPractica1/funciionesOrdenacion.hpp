#include <vector>
using namespace std;
void tiemposOrdenacionSeleccion(int nMin, int nMax,int incremento, int repeticiones, vector <double> &tiemposReales, vector <double> &numeroElementos);
void rellenarVector(vector<int> &v);
void ordenacionSeleccion(vector<int> &v);
bool estaOrdenado(const vector <int> &v);
void calcularTiemposEstimadosPolinomico(const vector <double> &numeroElementos, const vector <double> &a, vector <double> &tiemposEstimados);