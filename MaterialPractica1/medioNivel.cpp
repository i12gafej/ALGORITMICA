#include <vector>
#include <iostream>

#include "funciionesOrdenacion.hpp"
#include "medioNivel.hpp"
void ordenacionSeleccion(){
    int nMin = 0, nMax = 0 , inc = 0, rep= 0;
    std::vector< double > numeroElementos;
    std::vector< double > tiemposReales;
    std::vector< double > tiemposEstimados;

    std::cout<< "nMin : "<<std::endl;
    std::cin>>nMin;
    std::cout<< "nMax : "<<std::endl;
    std::cin>>nMax;
    std::cout<< "Incremento : "<<std::endl;
    std::cin>>inc;
    std::cout<< "Repeticiones : "<<std::endl;
    std::cin>>rep;

   tiemposOrdenacionSeleccion( nMin,  nMax, inc, rep, tiemposReales, numeroElementos);

   std::vector<std::vector <double> > B;
   B = 

}