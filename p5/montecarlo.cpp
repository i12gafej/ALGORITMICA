#include "montecarlo.hpp"
#include "ClaseTiempo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Montecarlo(){
    cout << "Introduce el orden de las matrices: ";
    int n;
    cin >> n;
    vector<vector<int>> A, B, AB;
    rellenarMatrices(n, A, B);
    AB=vector<vector<int>>(n, vector<int>(n));
    Clock time;
    time.start();
    productoMatrices(A, B, AB);
    time.stop();
    long long t = time.elapsed();

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
			for(unsigned int k = 0; k < m1[0].size(); k++) //Recorre los elementos a multiplicar (numero de columnas de la primera matriz)
				producto[i][j] = producto [i][j] + m1[i][k]*m2[k][j];
		}
	}
}