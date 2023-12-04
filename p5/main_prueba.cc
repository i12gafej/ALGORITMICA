#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Función para generar matrices cuadradas A y B de forma aleatoria
void generarMatrices(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 3 - 1;
            B[i][j] = rand() % 3 - 1;
        }
    }
}

// Función para multiplicar dos matrices cuadradas
void multiplicarMatrices(const vector<vector<int>>& A, const vector<int>& B, vector<int>& resultado) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        resultado[i] = 0;
        for (int j = 0; j < n; ++j) {
            resultado[i] += A[i][j] * B[j];
        }
    }
}

// Función para obtener la matriz C según las reglas del enunciado
void obtenerMatrizC(const vector<vector<int>>& AB, vector<vector<int>>& C) {
    int n = AB.size();
    int dado = rand() % 6 + 1; // Simula el lanzamiento de un dado de 6 caras
    if (dado % 2 == 0) {
        // Si el dado es par, C es igual a AB
        C = AB;
    } else {
        // Si el dado es impar, se modifica el elemento AB(n/2, n/2)
        C = AB;
        C[n/2][n/2]++;
    }
}

// Función para generar el vector X de n elementos con valores 0 o 1
void generarVectorX(vector<int>& X) {
    int n = X.size();
    for (int i = 0; i < n; ++i) {
        X[i] = rand() % 2;
    }
}

// Función para verificar el producto usando el algoritmo de Montecarlo
bool verificarProductoMontecarlo(const vector<vector<int>>& A, const vector<vector<int>>& B, const vector<int>& X, int numPruebas) {
    int n = A.size();
    vector<vector<int>> AB(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    multiplicarMatrices(A, B, AB);

    int exitosas = 0;
    for (int prueba = 0; prueba < numPruebas; ++prueba) {
        vector<vector<int>> A_rand(n, vector<int>(n));
        vector<vector<int>> B_rand(n, vector<int>(n));
        generarMatrices(A_rand, B_rand);
        obtenerMatrizC(AB, C);
        vector<int> AX(n);
        multiplicarMatrices(A_rand, X, AX);

        // Corrected comparison
        bool isEqual = true;
        for (int i = 0; i < n; ++i) {
            if (AX[i] != C[i][0]) {
                isEqual = false;
                break;
            }
        }

        if (isEqual) {
            exitosas++;
        }
    }

    double probabilidad = 1.0 - static_cast<double>(exitosas) / static_cast<double>(numPruebas);
    cout << "Probabilidad de que el producto se verifique: " << probabilidad << endl;

    return probabilidad == 0.0;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    cout << "Ingrese el orden de las matrices (n): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    generarMatrices(A, B);

    vector<vector<int>> resultado(n, vector<int>(n));

    // Multiplicar A por B y medir el tiempo
    clock_t inicio = clock();
    multiplicarMatrices(A, B, resultado);
    clock_t fin = clock();
    double tiempoMultiplicacion = static_cast<double>(fin - inicio) / CLOCKS_PER_SEC;
    cout << "Tiempo de multiplicación: " << tiempoMultiplicacion << " segundos" << endl;

    // Obtener matriz C y vector X
    vector<vector<int>> C(n, vector<int>(n));
    obtenerMatrizC(resultado, C);

    vector<int> X(n);
    generarVectorX(X);

    int numPruebas;
    cout << "Ingrese el número de pruebas a realizar: ";
    cin >> numPruebas;

    // Verificar el producto usando el algoritmo de Montecarlo y medir el tiempo
    inicio = clock();
    bool resultadoMontecarlo = verificarProductoMontecarlo(A, B, X, numPruebas);
    fin = clock();
    double tiempoMontecarlo = static_cast<double>(fin - inicio) / CLOCKS_PER_SEC;
    cout << "Tiempo de Montecarlo: " << tiempoMontecarlo << " segundos" << endl;

    return 0;
}
