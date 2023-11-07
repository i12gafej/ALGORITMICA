#include "medioNivel.hpp"


void ordenacionSeleccion(){
    std::cout<<"Valor minimo   : ";
    int min;
    std::cin>>min;
    std::cout<<"Valor maximo   : ";
    int max;
    std::cin>>max;
    std::cout<<"Incremento     : ";
    int inc;
    std::cin>>inc;
    std::cout<<"Repeticiones   : ";
    int rep;
    std::cin>>rep;
    std::vector <double> tiemposReales, numeroElementos, a,tiemposEstimados;
    tiemposOrdenacionSeleccion(min, max, inc,rep, tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);

    std::cout<<"------------------------------------------------------"<<std::endl;
    std::string ecuacion = std::to_string(a[0])+ " + "+to_string(a[1])+"n + " + to_string(a[2]) + " n²";
    std::cout<<"          t(0) = "+ecuacion<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;


    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);
    std::cout<<"Coeficiente de determinación: "<<calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados)<<std::endl;
    imprimirColumnasTRTEyNE("datosFinalesSeleccion.txt", numeroElementos, tiemposReales, tiemposEstimados);
    double n = 1;
    while(n != 0){
        std::cout<<"------------------------------------------------------"<<std::endl;
        std::cout<<"N para la funcion " + ecuacion<<std::endl; 
        std::cout<<"n = ";
        std::cin>> n;
        double t = calcularTiempoEstimadoPolinomico(n, a);
        imprimir(ecuacion, t);
    }
    
    
}

void cuadradoMatriz(){
    int nMini, nMaxi, incremento;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<< "Cuantos elementos NxN va a tener tu matriz?"<<std::endl;
    std::cout<<"N mínimo = ";
    std::cin>>nMini;
    std::cout<<std::endl;
    std::cout<<"N maximo = ";
    std::cin>>nMaxi;
    std::cout<<std::endl;
    std::cout<<"Incremento = ";
    std::cin>>incremento;
    std::cout<<std::endl;
    std::vector <double> tiemposReales, numeroElementos, a,tiemposEstimados;
    tiemposMatrizCuadrada(nMini, nMaxi, tiemposReales, numeroElementos, incremento);
    ajusteCubico(numeroElementos, tiemposReales, a);
    std::cout<<"------------------------------------------------------"<<std::endl;
    std::string ecuacion = std::to_string(a[0])+ " + "+to_string(a[1])+"n + " + to_string(a[2]) + " n² + "+to_string(a[3]) + " n³ ";
    std::cout<<"      t(0) = "+ecuacion<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;

    calcularTiemposEstimadosCubico(numeroElementos, a, tiemposEstimados);
    std::cout<<"Coeficiente de determinación: "<<calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados)<<std::endl;
    imprimirColumnasTRTEyNE("datosFinalesMatriz.txt", numeroElementos, tiemposReales, tiemposEstimados);
    std::cout<<"------------------------------------------------------"<<std::endl;
    
    double n = 1;
    while(n != 0){
        std::cout<<"------------------------------------------------------"<<std::endl;
        std::cout<<"N para la funcion " + ecuacion<<std::endl; 
        std::cout<<"n = ";
        std::cin>> n;
        double t = calcularTiempoEstimadoMatriz(n, a);
        imprimir(ecuacion, t);
    }
    
}
void fibonacciRecursivo(){
    int nMini, nMaxi, incremento;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout<< "Cuantos elementos N vas a calcular de Fibonacci?"<<std::endl;
    std::cout<<"N mínimo = ";
    std::cin>>nMini;
    std::cout<<std::endl;
    std::cout<<"N maximo = ";
    std::cin>>nMaxi;
    std::cout<<std::endl;
    std::cout<<"Incremento = ";
    std::cin>>incremento;
    std::cout<<std::endl;
    std::vector <double> tiemposReales, numeroElementos, a,tiemposEstimados, z;
    tiemposFibonacci(nMini, nMaxi, tiemposReales, numeroElementos, incremento);
    cambioVariable(numeroElementos, z);
    ajusteExponencial(z, tiemposReales, a);

    std::cout<<"------------------------------------------------------"<<std::endl;
    std::string ecuacion = std::to_string(a[0])+ " + "+to_string(a[1])+"*2^n";
    std::cout<<"      t(0) = "+ecuacion<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;

    calcularTiemposEstimadosExponencial(numeroElementos, tiemposReales, a, tiemposEstimados);
    std::cout<<"Coeficiente de determinación: "<<calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados)<<std::endl;
    imprimirColumnasTRTEyNE("datosFinalesFibonacci.txt", numeroElementos, tiemposReales, tiemposEstimados);
    std::cout<<"------------------------------------------------------"<<std::endl;
    
    double n = 1;
    while(n != 0){
        std::cout<<"------------------------------------------------------"<<std::endl;
        std::cout<<"N para la funcion " + ecuacion<<std::endl; 
        std::cout<<"n = ";
        std::cin>> n;
        double t = calcularTiempoEstimadoExponencial(n, a);
        imprimir(ecuacion, t);
    }
}