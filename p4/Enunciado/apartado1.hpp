#ifndef apartado1
#define apartado1

#include <vector>
#include <string>
#include "moneda.hpp"

using namespace std;
void cargarSistemaMonetario(vector <Moneda> &sistemaMonetario, const char * nombreFichero);
void cambio(int cantidad, vector <Moneda> sistemaMonetario, vector<vector <int>>& matrizEstados);
void escribirSolucion(vector<int> &solucion, vector <Moneda> &sistemaMonetario);

#endif