#include "apartado2.hpp"

void
rellenarManualMatriz(std::vector<std::vector<double>> &m, int n){
    for(int i = 0; i < n; i++){
        std::cout<< " FILA "<<i<<std::endl;
        for(int j = 0; j < n; j++){
            std::cout<< " COL ["<<i<<"] = ";
            std::cin>>m[i][j];
            std::cout<<std::endl;
        }
    }
}
void
rellenarAutomaticoMatriz(std::vector<std::vector<double>> &m, int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.95, 1.05);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = dis(gen);
        }
    }
}
void
ajusteCubico(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a){
    int grado = 4;
    std::vector<std::vector<double>> A = std::vector<std::vector<double>>(grado, std::vector<double>(grado));
    std::vector<std::vector<double>> B = std::vector<std::vector<double>>(grado, std::vector<double>(1));
    std::vector<std::vector<double>> X = std::vector<std::vector<double>>(grado, std::vector<double>(grado));

    for(int i = 0; i < grado; i++) {
        for(int j = 0; j < 1; j++){
            B[i][0] = sumatorio(n,tiemposReales,i,1);
        }
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
    a.push_back(X[2][0]);
    a.push_back(X[3][0]);
}
void cuadradoMatriz(const vector < vector < double > > &m1, vector < vector < double > > &producto)
{

	for(unsigned int i = 0; i < m1.size(); i++) //Recorre filas de la primera matriz
	{
		for(unsigned int j = 0; j < m1[0].size(); j++) //Recorre columnas de la segunda matriz
		{
			producto[i][j] = 0.0;
			for(unsigned int k = 0; k < m1[0].size(); k++) //Recorre los elementos a multiplicar (numero de columnas de la primera matriz)
				producto[i][j] = producto [i][j] + m1[i][k]*m1[k][j];
		}
	}
}
void 
tiemposMatrizCuadrada(int nMin, int nMax, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos, int inc){
    Clock time;
    double aux = 0;
    for(double i = nMin; i < nMax; i+=inc){
        numeroElementos.push_back(i);
        std::vector<std::vector<double>> M =  std::vector<std::vector<double>>(i, std::vector<double>(i)), P = std::vector<std::vector<double>>(i, std::vector<double>(i));
        rellenarAutomaticoMatriz(M, i);
        time.start();
        cuadradoMatriz(M,P);
        time.stop();
        tiemposReales.push_back(time.elapsed());
    }
}
void 
calcularTiemposEstimadosCubico(const std::vector<double> &numeroElementos, const std::vector<double> &a, std::vector<double>& tiemposEstimados){
    for(int i = 0; i < numeroElementos.size(); i++){
        tiemposEstimados.push_back(a[0]+a[1]*numeroElementos[i]+a[2]*pow(numeroElementos[i],2)+a[3]*pow(numeroElementos[i],3));
    }
}
double
calcularTiempoEstimadoMatriz(const double &n, const vector <double> &a){
    return a[0] + a[1] * n + a[2] * pow(n, 2) + a[3]*pow(n,3);
}