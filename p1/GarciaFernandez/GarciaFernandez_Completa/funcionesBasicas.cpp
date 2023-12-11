#include "funcionesBasicas.hpp"

void
rellenarVector(std::vector<int> &v){
    std::srand(time(nullptr));
    for(int i = 0; i < v.size(); i++){
        v[i] = rand() % 10000000;
    }
}


void imprimirColumnasTRTEyNE(std::string filename, std::vector <double> &numeroElementos, std::vector <double>
&tiemposReales, std::vector <double> &tiemposEstimados){
    std::ofstream f;
    f.open(filename, ios::out);
    if (!f.is_open())
        std::cout << "Error"<<std::endl;
    for(int i = 0; i < tiemposReales.size(); i++){
        f << numeroElementos[i] <<" "<< tiemposReales[i]<<" "<<tiemposEstimados[i];
        if(i != tiemposEstimados.size()-1)
            f << std::endl;
    }
    f.close();
    //system("gnuplot graficas.gp");
}

double sumatorio(const std::vector <double> &n, const std::vector <double> &t,
int expN, int expT){
    double sumaN = 0;
    for(int i = 0; i < n.size(); i++){
        sumaN += pow(n[i], expN)*pow(t[i], expT);
        //std::cout<<"n["<<i<<"] ("<<n[i]<<") * "<<expN<<" + "<<"t["<<i<<"] ("<<t[i]<<") * "<<expT<<"="<<sumaN<<" ";
    }
    //std::cout<<std::endl;
    return sumaN;
}

double varianza (std::vector<double> v, double media){
    double acc = 0;
    for(int i = 0; i < v.size(); i++){
        acc += pow(v[i] - media,2);
    }
    return acc/v.size();
}
double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, const std::vector <double> &tiemposEstimados){
    //double mediaReal = sumatorio(tiemposReales,tiemposEstimados,1,0)/tiemposReales.size(), mediaEstimado = sumatorio(tiemposReales,tiemposEstimados,0,1)/tiemposEstimados.size();
    double vE = varianza(tiemposEstimados, sumatorio(tiemposReales,tiemposEstimados,0,1)/tiemposEstimados.size()), vR = varianza(tiemposReales, sumatorio(tiemposReales,tiemposEstimados,1,0)/tiemposReales.size());
    std::cout<<"VE = "<<vE<<" ... VR = "<<vR<<std::endl;
    return vE/vR;
}
void 
imprimir(std::string ecuacion, double t){
    long long ti, an, di, horas, m, secs;
    ti = static_cast<long long>(t);
    std::cout<<"------------------------------------------------------"<<std::endl;
    secs = ti / 1000;
    m = secs / 60;
    horas = m / 60;
    di = horas / 24;
    an = di / 365;
    di %= 365;
    horas %= 24;
    m %= 60;
    secs %= 60;
    std::cout<<"Años        : "<<an<<std::endl;
    std::cout<<"dias        : "<<di<<std::endl;
    std::cout<<"horas       : "<<horas<<std::endl;
    std::cout<<"minutos     : "<<m<<std::endl;
    std::cout<<"segundos    : "<<secs<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
}