#include "materialUsado.hpp"
#include "material.hpp"

#include <vector>
#include <string.h>
using namespace std;



void cargarMateriales(vector<Material> &materiales, const char *nombreFichero);
void mochila(float volumenMochila, vector<Material> &materiales, vector<MaterialUsado>
&solucion);
void escribirSolucion(vector<MaterialUsado> &solucion);