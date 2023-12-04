#ifndef BACKTRACKING_HPP
#define BACKTRACKING_HPP 


#include <vector>
#include <cstdint>

using namespace std;

bool nReinasBacktracking( int n, vector<vector <int>>&soluciones);
void escribirSoluciones( vector<vector <int>>&soluciones,bool todas);
bool nReinasBacktracking( int n, vector<int>&solucion);
void escribirSolucion( vector<int>&solucion);
bool lugar(int k, vector<int>&x);
void tiempo(uint64_t time);
#endif

