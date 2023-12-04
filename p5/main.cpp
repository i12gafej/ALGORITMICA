#include <iostream>
#include <unistd.h>
#include <limits>
using namespace std;

void nReinasBackTodas();
void nReinasBackUna();
void nReinasVegas();
void Montecarlo();

int main(){
    system("clear");
    while(1){        
        cout << "-------------------" << endl;
        cout << "Introduce el metodo" << endl;
        cout << "-------------------" << endl;
        cout << "[1] Calcular NReinas método Backtracking: todas las soluciones" << endl;
        cout << "[2] Calcular NReinas método Backtracking: una solucion" << endl;
        cout << "[3] Calcular NReinas método de Las Vegas" << endl;
        cout << "[4] Calcular producto de matrices mediante Monte Carlo" << endl;
        cout << "[0] Salir" << endl;
        cout << endl;
        cout << endl;
        cout << "Opcion: ";
        int opt;
        cin >> opt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(opt){
            case 1:
                nReinasBackTodas();
                break;
            case 2:
                nReinasBackUna();
                break;
            case 3:
                nReinasVegas();
                break;
            case 4:
                Montecarlo();
                break;
            default:
                system("clear");
                return 0;
                break;
        }
        cout << "Presiona Enter para continuar...";
        cin.get();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
        //TODO: hacer que se presione enter para seeguir
    }
}