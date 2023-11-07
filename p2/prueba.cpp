#include <vector>
#include <iostream>
#include <unistd.h>
#include "funcionesBasicas.hpp"
#include "quicksort.hpp"

using namespace std;

//g++ prueba.cpp funcionesBasicas.cpp quicksort.cpp -o prueba

int main(){
    auto v = vector<int>(20);
    auto w = vector<int>(20);
    rellenarVector(v, w);
    Clock time;

    cout << "Empieza: " << endl;
    time.start();

    sleep(2);

    time.stop();

    cout << "elapsed: "<<time.elapsed();


    time.restart();


    sleep(2);


    time.stop();

    cout << "elapsed: "<<time.elapsed();



    /*cout << endl;
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " " << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    quicksort2(0, v.size(), v, 10, 11);

    cout << endl;
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " " << endl;
    }*/
    cout << endl;
}