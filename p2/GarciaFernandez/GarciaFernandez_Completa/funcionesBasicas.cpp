#include "funcionesBasicas.hpp"

void
rellenarVector(vector<double> &v1, vector<double> &v2){
    srand(time(nullptr));
    double a = 0;
    for(int i = 0; i < v1.size(); i++){
        a = (double)(rand() % 10000000);
        v1[i] = a;
        v2[i] = a;
    }
}

void imprimir(vector <double> qs1, vector <double> qs2, vector <int> n){
    ofstream f;
    f.open("tiempos.txt", ios::out);

    if(!f.is_open()){
        cout << "Error al abrir fichero" << endl;
        return;
    }

    for(int i = 0; i < n.size(); i++){
        f << n[i] << " " <<qs1[i] << " "<<qs2[i]<<endl;
    }
    f.close();

}

