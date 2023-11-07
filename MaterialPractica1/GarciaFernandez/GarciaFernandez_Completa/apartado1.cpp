#include "apartado1.hpp"
void
ordenacionSeleccion(std::vector<int> &v){
    int posicionMenor = 0;
    for(int i = 0; i < v.size(); i++){
        posicionMenor = 0;
            //para j de i+1 hasta n hacer
            for(int j = i+1; j < v.size(); j++){
                //si v[j] < v[posicionM enor] entonces
                if(v[j] < v[posicionMenor]){
                    posicionMenor = j;
                }
            }
        int aux = v[i];
        v[i] = v[posicionMenor];
        v[posicionMenor] = aux;
    }
        
}
bool 
estaOrdenado(const std::vector <int> &v){
    for (size_t i = 0; i < v.size() - 1; ++i) {
        if (v[i] > v[i + 1]) {
            return false;  // Si encuentra un par de elementos desordenados, retorna falso
        }
    }
    return true;
}
void 
tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int
repeticiones, std::vector <double> &tiemposReales, std::vector <double>
&numeroElementos){
    Clock time;
    double aux = 0;
    for(int i = nMin; i < nMax; i+= incremento){
        numeroElementos.push_back(i);
        for(int j = 0; j < repeticiones; j++){
            std::vector<int> v = std::vector<int>(i);
            rellenarVector(v);
            time.start();
            ordenacionSeleccion(v);
            time.stop();
            aux += time.elapsed();
        }
        aux = aux / repeticiones;
        tiemposReales.push_back(aux);        
    }
}
void ajusteCuadratico(const std::vector <double>
&numeroElementos, const std::vector <double> &tiemposReales, std::vector <double>
&a){
    int n = 3;
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(n, std::vector<double>(n));
    std::vector<std::vector<double>> B = std::vector<std::vector<double>>(n, std::vector<double>(1));
    std::vector<std::vector<double>> X = std::vector<std::vector<double>>(n, std::vector<double>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 1; j++){
            B[i][0] = sumatorio(numeroElementos,tiemposReales,i,1);
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            //si fila es 0, 0,0 es a elevado a 0, si es 1, ...
            A[i][j] = sumatorio(numeroElementos,tiemposReales,i+j, 0);
            A[j][i] = sumatorio(numeroElementos,tiemposReales,i+j, 0);
        }
    }  
    
    resolverSistemaEcuaciones(A,B,n,X);

    a.push_back(X[0][0]);
    a.push_back(X[1][0]);
    a.push_back(X[2][0]);
}
void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, const std::vector <double> &a, std::vector <double> &tiemposEstimados){
    for(int i = 0; i < numeroElementos.size(); i++){
        tiemposEstimados.push_back(a[0]+a[1]*numeroElementos[i]+a[2]*pow(numeroElementos[i], 2));
    }
}
double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a){
    return a[0] + a[1] * n + a[2] * pow(n, 2);
}