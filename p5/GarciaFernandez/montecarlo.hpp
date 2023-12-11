#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <vector>
using namespace std;


void rellenarMatrices(int n, vector<vector<int>>& matriz1, vector<vector<int>>& matriz2);
void productoMatrices(const vector < vector < int > > &m1, const vector < vector < int > > &m2, vector < vector < int > > &producto);
int lanzarDado();
int repetirVerificarProductoMontecarlo(vector<vector<int>> A,vector<vector<int>> B,vector<vector<int>> C, int n, int nPruebas);
bool verificarProductoMontecarlo(vector<vector<int>> A,vector<vector<int>> B,vector<vector<int>> C, int n);
vector<int> generarVectorX(int n);
bool comprobarIgualdad( vector<vector<int>>& matrizA,  vector<vector<int>>& matrizB);
bool comprobarIgualdad(vector<int>& matrizA, vector<int>& matrizB);
void productoMatrices2(const vector < int > &m1, const vector < vector < int > > &m2, vector < int > &producto);

#endif