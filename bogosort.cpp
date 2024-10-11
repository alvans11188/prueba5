#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 8;

void tarea() {
    // Simulación de una tarea que consume tiempo
    for (int i = 0; i < 100000000000000000; i++);
}

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        int j = rand() % size;
        swap(arr[i], arr[j]);
    }
}

void bogosort(int arr[], int size) {
    while (!isSorted(arr, size)) {
        shuffle(arr, size);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "INGRESE LA CANTIDAD DE VALORES DE SU ARREGLO: ";
    cin >> n;

    int arreglo1[n];
    int arreglo2[n];

    cout << "LOS VALORES DEL ARREGLO SON: " << endl;

    for (int i = 0; i < n; i++) {
        arreglo1[i] = rand() % 1000 + 1;
        arreglo2[i] = arreglo1[i];
        cout << arreglo1[i] << " ";
    }
    cout << "\n" << endl;

    clock_t start = clock();
    tarea();
    bogosort(arreglo1, n);
    clock_t end = clock();

    double duracion_segundos1 = double(end - start) / CLOCKS_PER_SEC;
    double duracion1 = double(end - start) / CLOCKS_PER_SEC * 1000.0;

    cout << "Tiempo de ejecucion: " << duracion_segundos1 << " s" << endl;
    cout << "Tiempo de ejecucion: " << duracion1 << " ms" << endl;

    cout << "Array ordenado: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo1[i] << " ";
    }
    
    cout << endl;

    return 0;
}

