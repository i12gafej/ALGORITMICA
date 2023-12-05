#include <iostream>
#include "montecarlo.hpp"
#include "ClaseTiempo.hpp"
#include <unistd.h>
#include <vector>
#include <random>
#include <cstdlib>
using namespace std;

void imprimir(vector<int> v);   

void Montecarlo(){
    system("clear");
    cout << "Introduce el orden de la matriz: ";
    int n;
    cin >> n;
    vector<vector<int>> A, B, C, AB = vector<vector<int>>(n, vector<int>(n));
    rellenarMatrices(n, A, B);
    Clock time;

    time.start();
    productoMatrices(A, B, AB);
    time.stop();
    long long t1 = time.elapsed();

    if(lanzarDado() % 2 == 0){
        C = AB;
    }
    else{
        AB[n/2][n/2] += 1;
        C = AB;
    }
    cout << "Introduzca el numero de pruebas a realizar: ";
    int nPruebas;
    cin >> nPruebas;
    Clock time2;
    time2.start();
    int exitosas = repetirVerificarProductoMontecarlo(A, B, C, n, nPruebas);
    time2.stop();
    long long t2 = time2.elapsed();
    if(exitosas != nPruebas){
        cout << "Numero de pruebas que se han necesitado: "<<exitosas <<endl;
    }else{
        float p = 1.0 - (1.0 / static_cast<float>(pow(2, nPruebas)));
        cout << "La probabilidad de verificación es: "<< p << endl;
    }
    cout << "----------------------" << endl;
    cout << "Tiempo de montecarlo: "<< t2 << endl;
    cout << "Tiempo de producto de matrices: "<< t1 << endl;


}

void rellenarMatrices(int n, vector<vector<int>>& matriz1, vector<vector<int>>& matriz2){
    matriz1=vector<vector<int>>(n, vector<int>(n));
    matriz2=vector<vector<int>>(n, vector<int>(n));

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz1[i][j] = rand() % 3 - 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz2[i][j] = rand() % 3 - 1;
        }
    }
}
void productoMatrices(const vector < vector < int > > &m1, const vector < vector < int > > &m2, vector < vector < int > > &producto){
	for(unsigned int i = 0; i < m1.size(); i++){
		for(unsigned int j = 0; j < m2[0].size(); j++){
			producto[i][j] = 0.0;
			for(unsigned int k = 0; k < m1[0].size(); k++){ 
				producto[i][j] = producto [i][j] + m1[i][k]*m2[k][j];
                
            }
		}
	}
}
int lanzarDado(){
    srand(static_cast<unsigned int>(time(nullptr)));
    return (rand() % 6) + 1;
}
int repetirVerificarProductoMontecarlo(vector<vector<int>> A,vector<vector<int>> B,vector<vector<int>> C, int n, int nPruebas){
    int exitosas = 0;
    for(int i = 0; i < nPruebas; i++){
        if(verificarProductoMontecarlo(A, B, C, A.size())){
            exitosas++;
        }
    }
    return exitosas;
}
bool verificarProductoMontecarlo(vector<vector<int>> A,vector<vector<int>> B,vector<vector<int>> C, int n){
    vector<int> XAB, XA, XC;
    vector<int> X;
    XAB = vector<int>(n);
    XA = vector<int>(n);
    XC = vector<int>(n);
    X = generarVectorX(n);
    productoMatrices2(X, A, XA);
    productoMatrices2(XA, B, XAB);
    
   
    productoMatrices2(X, C, XC);
    
    
    if(comprobarIgualdad(XAB, XC) == true){
        return true;
    }
    else{
        return false;
    }
}
void imprimir(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ", ";
    }
    cout << endl;
}
vector<int> generarVectorX(int n){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, 1); 
    
    vector<int> X(n);
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i < n; i++){
        X[i] = dis(gen);
    }
    return X;
}

bool comprobarIgualdad(vector<int>& matrizA, vector<int>& matrizB){
    for (size_t p = 0; p < matrizA.size(); ++p) {
        if (matrizA[p] != matrizB[p])
            return false;
    }
    return true;
}
void productoMatrices2(const vector < int > &m1, const vector < vector < int > > &m2, vector < int > &producto){
	for(unsigned int i = 0; i < m1.size(); i++){
		producto[i] = 0.0;
        for(unsigned int j = 0; j < m1.size(); j++){
            producto[i] = producto [i] + m1[j]*m2[j][i];
		}
	}
}
