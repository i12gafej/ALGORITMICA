#include "backtracking.hpp"
#include "ClaseTiempo.hpp"
#include <vector>
#include <iomanip>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <unistd.h>
#define RED     "\x1b[31m"
#define WHITE   "\x1B[37m"
#define BG_BLACK   "\x1B[40m"
#define RESET   "\x1b[0m"

using namespace std;

void nReinasBackTodas(){
    system("clear");
    cout << "Introduce el numero de reinas: ";
    int n;
    cin >> n;
    vector<vector <int>> soluciones;
    cout << "Quieres ver las soluciones en modo tablero?" << endl;
    cout << "[1] Si" << endl;
    cout << "[2] No" << endl;
    cout << endl;
    cout << "Opcion: ";
    int n2;
    cin >> n2;
    bool todas = n2 == 1 ? true : false;
    if(nReinasBacktracking(n, soluciones)){
        escribirSoluciones(soluciones, todas);
    }else{
        cout << "No hay soluciones" << endl;
    }
}

bool nReinasBacktracking( int n, vector<vector <int>>&soluciones){
    vector<int> x(n);
    int k = 0;
    x[k] = -1;
    while(k >= 0){
        x[k]++;
        while(x[k] < n && !lugar(k, x)){
            x[k]++;
        }
        if(x[k] < n){
            if(k == n - 1){
                soluciones.push_back(x);
            }else{
                k++;
                x[k] = -1;
            }
        }else{
            k--;
        }
    }
    return soluciones.size() > 0;
}
void escribirSoluciones( vector<vector <int>>&soluciones, bool todas){
    cout << "------------------------------------" << endl;
    cout << "               Solucion" << endl;
    cout << "------------------------------------" << endl;
    if(todas){
        for(int i = 0; i < soluciones.size(); i++){
            cout << "Solucion " << i + 1 << endl;
            for(int j = 0; j < soluciones[i].size(); j++){
                for(int k = 0; k < soluciones[i].size(); k++){
                    if(soluciones[i][j] == k){
                        cout <<RED << BG_BLACK<< "R ";
                    }else{
                        cout <<WHITE << BG_BLACK<< "X ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
    }else{
        for(int i = 0; i < soluciones.size(); i++){
            cout << "Solucion " << i + 1 << endl;
            for(int j = 0; j < soluciones[i].size(); j++){
                cout << soluciones[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
void nReinasBackUna(){
    system("clear");
    cout << "Introduce el numero de reinas: ";
    int n;
    cin >> n;
    vector<int> solucion;
    Clock time;
    time.start();
    bool sol = nReinasBacktracking(n, solucion);
    time.stop();
    if(sol){
        escribirSolucion(solucion);
        tiempo(time.elapsed());
    }else{
        cout << "No hay soluciones" << endl;
    }
    cout << endl;

}
bool nReinasBacktracking( int n, vector<int>&solucion){
    vector<int> x(n);
    int k = 0;
    x[k] = -1;
    
    while (k >= 0) {
        x[k]++;
        while (x[k] < n && !lugar(k, x)) {
            x[k]++;
        }
        
        if (x[k] < n) {
            if (k == n - 1) {
                solucion = x;
                return true;  // Devuelve true cuando se encuentra una solución
            } else {
                k++;
                x[k] = -1;
            }
        } else {
            k--;
        }
    }
    return false; 
}
void escribirSolucion( vector<int>&solucion){
    cout << "------------------------------------" << endl;
    cout << "               Solucion" << endl;
    cout << "------------------------------------" << endl;
    for(int i = 0; i < solucion.size(); i++){
        cout << solucion[i] << " ";
    }
    cout << endl;
    for(int j = 0; j < solucion.size(); j++){
        for(int k = 0; k < solucion.size(); k++){
            if(solucion[j] == k){
                cout <<RED << BG_BLACK<< "R " << RESET;
            }else{
                cout <<WHITE << BG_BLACK<< "X "<< RESET;
            }
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
}
bool lugar(int k, vector<int>&x){
    for(int i = 0; i < k; i++){
        if(x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)){
            return false;
        }
    }
    return true;
}
void tiempo(uint64_t time){
    long long ti, m, secs, mili;
    ti = static_cast<long long>(time);
    mili = (ti /1000);
    secs = mili / 1000;
    ti %= 1000;
    m = secs / 60; 
    m %= 60;
    secs %= 60;
    mili %= 1000;
    ti %= 1000;
    cout<<"Minutos     : "<<m<<endl;
    cout<<"Segundos    : "<<secs<<endl;
    cout<<"Milisegundos: "<<mili<<endl;
    cout <<"Microsegundos: "<<ti<<endl;
    cout << "------------------------------------" << endl;
    
}
