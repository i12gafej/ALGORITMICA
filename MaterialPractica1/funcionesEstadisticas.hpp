#include <vector>
#include <cmath>

double sumatorio(std::vector <double> &n, std::vector <double> &t,int expN, int expT){
    double acc = 0;
    for(int i = 0; i < n.size(); i++){
        acc += pow(n[i], expN) * pow(t[i], expT);
    }
    return acc;
}

double media(std::vector <double > v){
    double acc = 0;
    for(int i = 0; i < v.size(); i++){
        acc += v[i];
    }
    return acc/v.size();
}
double varianza (std::vector<double> v, double media){
    double acc = 0;
    for(int i = 0; i < v.size(); i++){
        acc += pow(v[i] - media,2);
    }
    return acc/v.size();
}
