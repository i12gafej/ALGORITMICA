#include "montecarlo.hpp"
#include "ClaseTiempo.hpp"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Montecarlo(){
    cout << "Introduce el orden de las matrices: ";
    int n;
    cin >> n;

    vector<vector<int>> A, B, C;

    rellenarMatrices(n, A, B);

    vector<vector<int>> AB=vector<vector<int>>(n, vector<int>(n));

    Clock time;

    time.start();
    productoMatrices(A, B, AB);
    time.stop();
    long long t1 = time.elapsed();

    if(lanzarDado()){
        C = AB;
    }
    else{
        AB[n/2][n/2] += 1;
        C = AB;
    }

    cout << "Introduzca el numero de pruebas a realizar: ";
    int nPruebas;
    cin >> nPruebas;
    
    time.start();
    verificarProductoMontecarlo(A,B,C, nPruebas);
    cout <<"FUERAA"<<endl;
    time.stop();
    long long t2 = time.elapsed();
    
    
    // if(intentos_exitosos != nPruebas){
    //     cout << "Numero de pruebas que se han necesitado: "<<intentos_exitosos <<endl;
    // }else{
    //     float p = 1.0 - (1.0 / static_cast<float>(2, nPruebas));
    //     cout << "La probabilidad de verificación es: "<< p << endl;
    // }
    cout << "----------------------" << endl;
    cout << "Tiempo de montecarlo: "<< t2 << endl;
}
int verificarProductoMontecarlo(vector<vector<int>> A,vector<vector<int>> B,vector<vector<int>> C, int n){    
    int exitosas = 0;
    vector<vector<int>> X, XAB, XA, XC;
    XAB = vector<vector<int>>(A.size(), vector<int>(1));
    XA = vector<vector<int>>(A.size(), vector<int>(1));
    XC = vector<vector<int>>(A.size(), vector<int>(1));

    for(int i = 0; i < n; i++){
        cout << "Inicio"<<endl;
        //limpiar(X);
        if(i == 1)
            cout << "X size:"<<X.size() << " "<<X[0].size();
        X = generarVectorX(A.size());
        
        cout << "Producto XA" << endl;
        productoMatrices(X, A, XA);
        cout << "Producto XAB" << endl;
        productoMatrices(XA, B, XAB);
        cout << "Producto XC" << endl;
        productoMatrices(X, C, XC);
        cout << "Fin productos" << endl;
        for(int i = 0; i < X.size(); i++){
            for(int j = 0; j < X[0].size(); j++){
                cout << X[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------"<<endl;
        for(int i = 0; i < XAB.size(); i++){
            for(int j = 0; j < XAB[0].size(); j++){
                cout << XAB[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------"<<endl;
        for(int i = 0; i < XC.size(); i++){
            for(int j = 0; j < XC[0].size(); j++){
                cout << XC[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------"<<endl;
        if(comprobarIgualdad(XAB, XC) == true){
            cout << "Exitosas"<<endl;
            exitosas++;
        }
        else{
            cout << "No exitosas" << endl;
        }
        
    }
    
    return exitosas;
}
// void limpiar(vector<vector<int>> &m){
//     for (auto& fila : m) {
//         fila.clear(); 
//     }
//     m.clear(); 
// }
bool comprobarIgualdad( vector<vector<int>>& matrizA,  vector<vector<int>>& matrizB) {
    for (size_t i = 0; i < matrizA.size(); ++i) {
        cout << "i = "<<i<<endl;
        if (matrizA[i][0] != matrizB[i][0]) {
            cout << "Dentro" <<endl;
            return false;
            cout << "Otra vez"<<endl;
        }
    }
    return true;
}
vector<vector<int>> generarVectorX(int n){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, 1); 
    
    vector<vector<int>> X(1, vector<int>(n));
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i < n; i++){
        X[0][i] = dis(gen);
    }
    return X;
}
int lanzarDado(){
    srand(static_cast<unsigned int>(time(nullptr)));
    return (rand() % 6) + 1;
}
void rellenarMatrices(int n, vector<vector<int>>& matriz1, vector<vector<int>>& matriz2){
    matriz1=vector<vector<int>>(n, vector<int>(n));
    matriz2=vector<vector<int>>(n, vector<int>(n));

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Generar un número aleatorio entre -1, 0 y 1
            matriz1[i][j] = rand() % 3 - 1;
            //cout << matriz1[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << "----------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Generar un número aleatorio entre -1, 0 y 1
            matriz2[i][j] = rand() % 3 - 1;
            //cout << matriz2[i][j] << " ";
        }
        //cout << endl;
    }
}
void productoMatrices(const vector < vector < int > > &m1, const vector < vector < int > > &m2, vector < vector < int > > &producto)
{
	for(unsigned int i = 0; i < m1.size(); i++) //Recorre filas de la primera matriz
	{
        
		for(unsigned int j = 0; j < m2[0].size(); j++) //Recorre columnas de la segunda matriz
		{
            
			producto[i][j] = 0.0;
            
			for(unsigned int k = 0; k < m1[0].size(); k++){ //Recorre los elementos a multiplicar (numero de columnas de la primera matriz)
                
				producto[i][j] = producto [i][j] + m1[i][k]*m2[k][j];
                
            }
		}
	}
}