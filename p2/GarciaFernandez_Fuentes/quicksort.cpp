#include "quicksort.hpp"
void 
tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, int nMediana, 
int nElementosMinimo, vector <double> &tiemposRealesQS1, vector <double> &tiemposRealesQS2, vector <int> &numeroElementos){
    Clock time1, time2;
    double aux1 = 0, aux2 = 0, media1 = 0, media2 = 2;
    size_t count = 0;
    vector<double>v1, v2;
    //cout << "Repeticiones : "<< repeticiones << endl;
    for(int i = nMin; i < nMax; i+= incremento){     
        
        numeroElementos.push_back(i);
        for(int j = 0; j < repeticiones; j++){
            
            //cout << "               Vectores        "<<endl;
            
            v1.clear();
            v1.resize(i);
            v2.clear();
            v2.resize(i);

            rellenarVector(v1, v2);
                
            time1.start();
            quicksort1(0, v1.size(), v1);
            time1.stop();

            aux1 += time1.elapsed();
            
            time2.start();
            quicksort2(0, v2.size(), v2, nElementosMinimo, nMediana);
            time2.stop();

            aux2 += time2.elapsed();


        }
        float por = (static_cast<float>(i)/nMax)*100;
        cout << "Para <"<<i<<"> ("<<por<<" %)"<<endl;
        aux1 = aux1 / repeticiones;
        media1 += aux1;
        tiemposRealesQS1.push_back(aux1);    
        cout<<"Tiempos Reales de QS1: "<<aux1;
        aux2 = aux2 / repeticiones;
        media2 += aux2;
        tiemposRealesQS2.push_back(aux2);   
        cout<<" // Tiempos Reales de QS2: "<<aux2<<endl;    
        count++;
    }
    media1 /= tiemposRealesQS1.size();
    media2 /= tiemposRealesQS2.size();

    cout << "Media tiempo QS1: "<<media1 <<endl;
    cout << "Media tiempo QS2: "<<media2 <<endl;
    cout << "Cociente: media QS2/media QS1: "<<media2/media1<<endl;
    
}
void quicksort1(int izquierda, int derecha, vector<double> &v){
    int i = izquierda, j = derecha, x = v[(izquierda+derecha)/2];
    do{
        while(v[i] < x){
            i++;
        }
        while(v[j] > x){
            j--;
        }
        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);
    if(izquierda < j){
        quicksort1(izquierda, j, v);
    }
    if(derecha > i){
        quicksort1(i, derecha, v);
    }
}
void
quicksort2(int izquierda, int derecha, vector<double> &v, int nEleMinimo, int nEleMediana){
    /*Lo que tengo que hacer por cada ramificación es calcular la mediana del vector, que será mi pivote
    Lo que pasa, lo que pasa, lo que pasa, es que 
    1º: se tienen que obtener aleatoriamente los elementos ddel vector para el v de la mediana
    2º: Ese vector aka vMediano, si el tamaño del fragmento de ordenación es igual al nEleMinimo
    ya no usamos lo de la mediana, solo usamos lo normal*/


    int i = izquierda, j = derecha, x;
    if(derecha-izquierda > nEleMinimo){
    
            
        x = calcularMediana(v, nEleMediana, izquierda, derecha);
        
            
    }
    else{
        x = v[izquierda+(derecha-izquierda)/2];
    }
    
    do{
        while(v[i] < x){
            i++;
        }
        while(v[j] > x){
            j--;
        }
        if(i <= j){
            int swap = v[i];
            v[i] = v[j];
            v[j] = swap;
            i++;
            j--;
        }
    }while(i <= j);
    if(izquierda < j){
        quicksort2(izquierda, j, v, nEleMinimo, nEleMediana);
    }
    if(derecha > i){
        quicksort2(i, derecha, v, nEleMinimo, nEleMediana);
    }
    
    
}
int
calcularMediana(vector<double> v, int n, int de, int iz){

    //lo que tengo que coger es el pedazo del vector partiendo de v[de+iz / 2] e is añadiendo de la derecha y de la izquierda poco a poco
    int centro = iz+(de-iz)/2;
    // for(int i = 0; i < n; i++){
    //     v2.push_back(v[rand()%(v.size())]);//añades a v2 el elemento de v en una posición aleatoria de su tamaño
    // }

    //tengo que hacerlo desde centro - n/2 a centro + n/2
    quicksort1(centro - n/2, centro + n/2, v);
    return v[centro];
}