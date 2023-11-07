#include "medioNivel.hpp"
#include "quicksort.hpp"
#include <getopt.h>
#include <string.h>
#include <ctype.h>


void ayuda(){
    cout<<"Opciones:"<<endl;
    cout<<"-h, --help             Imprimir esta ayuda"<<endl;
    cout<<"-m, --nMin             Numero minimo de elementos"<<endl;
    cout<<"-M, --nMax,            Numero maximo de elementos"<<endl;
    cout<<"-i, --inc              Incremento"<<endl;
    cout<<"-r, --rep              Repeticiones"<<endl;
    cout<<"-e, --nMed             Numero de elementos para calcular mediana"<<endl;
    cout<<"-n, --nMin             Numero minimo de elementos para usar el metodo de la mediana"<<endl;
}

int main(int argc, char * const *argv){
    //Ejemplo de ejecución: ./main -m 1000000 -M 5000000 -i 100000 -r 3 -e 5 -n 1000
    //minSize maxSize incSize numRep numMediana numMin
    static struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"minSize", required_argument, NULL, 'm'},
        {"maxSize", required_argument, NULL, 'M'},
        {"inc", required_argument, NULL, 'i'},
        {"rep", required_argument, NULL, 'r'},
        {"nMed", required_argument, NULL, 'e'},
        {"nMin", required_argument, NULL, 'n'},
        {0,0,0,0}
    };
    int c;
    int min, max, inc, rep, med = 21, nMin= 10;

    if(argc == 1){
        cout << "Missing parameters\n\n"<<endl;
        ayuda();
        cout <<"\n"<<"Ejemplo de ejecución: ./main -m 1000000 -M 5000000 -i 100000 -r 3 -e 5 -n 1000"<<endl;
        return 0;

    }
    
    while((c = getopt_long(argc, argv, "hm:M:i:r:e:n:", long_options, NULL)) != -1){
        //printf("optind: %d, optarg: %s, optopt: %c, opterr: %d\n\n", optind, optarg, optopt, opterr);
        switch(c){
            case 'h':
                ayuda();
            break;
            case 'm':
                min = stoi(optarg);
            break;
            case 'M':
                max = stoi(optarg);
            break;
            case 'i':
                inc = stoi(optarg);
            break;
            case 'r':
                rep = stoi(optarg);
            break;
            case 'e':
                med  = stoi(optarg);
            break;
            case 'n':
                nMin = stoi(optarg);
            break;
            case '?':
                cout<<"Error"<<endl;
                // if(optopt == 'u' || optopt == 'g') // Para el caso de que 'c' no tenga el argumento
                //                                                     // obligatorio.
                // fprintf(stderr, "La opción %c requiere un argumento. Valor de opterr = "
                //             "%d\n",
                //             optopt, opterr);
                // else if (isprint(optopt)) // Se mira si el caracter es imprimible
                //     fprintf(stderr,"Opción desconocida \"-%c\". Valor de opterr = %d\n",
                //             optopt, opterr);
                // else // Caracter no imprimible o especial
                //     fprintf(stderr, "Caracter `\\x%x'. Valor de opterr = %d\n",
                //             optopt, opterr);
                return 1;       
            break;
            default:
                abort();
        }
    }
    if(med %2 == 0){
        cout << "El numero de valores para la mediana debe ser impar" << endl;
        return 0;
    }

    
    
    comparacionVariantesQuicksort(min, max, inc, rep, med, nMin);
    
    
}

