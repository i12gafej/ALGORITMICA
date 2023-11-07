#include "apartado3.hpp"

double fibonacci(double n){
    if(n <= 2)
        return (n-1);
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
void tiemposFibonacci(int nMin, int nMax, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos, int inc){
    Clock time;
    double aux = 0;
    int count = 0;
    for(double i = nMin; i < nMax; i+=inc){
        numeroElementos.push_back(i);
        time.start();
        fibonacci(i);
        time.stop();
        tiemposReales.push_back(time.elapsed());
        count++;        
    }
}
void ajusteExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a){
    int grado = 2;
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(grado, std::vector<double>(grado));
    std::vector<std::vector<double>> B = std::vector<std::vector<double>>(grado, std::vector<double>(1));
    std::vector<std::vector<double>> X = std::vector<std::vector<double>>(grado, std::vector<double>(grado));

    for(int i = 0; i < grado; i++) {
        B[i][0] = sumatorio(n,tiemposReales,i,1);        
    }
    for(int i = 0; i < grado;i++){
        for(int j = 0; j < grado;j++){
            //si fila es 0, 0,0 es a elevado a 0, si es 1, ...            
            A[i][j] = sumatorio(n,tiemposReales,i+j, 0);
            A[j][i] = sumatorio(n,tiemposReales,i+j, 0);                         
        }
    }

    resolverSistemaEcuaciones(A,B,grado,X);

    a.push_back(X[0][0]);
    a.push_back(X[1][0]);
}
void calcularTiemposEstimadosExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, const std::vector <double> &a, std::vector <double> &tiemposEstimados){
    for(int i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0]+a[1]*pow(2,n[i]));
    }
}
double calcularTiempoEstimadoExponencial(const double &n, const vector <double> &a){
    return a[0] + a[1]*pow(2, n);
}
void 
cambioVariable(const std::vector<double> &n, std::vector<double> &z){
    for(int i = 0; i < n.size(); i++){
        z.push_back(pow(2, n[i]));
    }
}