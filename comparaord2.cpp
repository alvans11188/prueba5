/*
Comparacion de 2 algoritmos 
uno tiene que ser logaritmico y otro en teoria lineal
por ejemplo
ORDENAMIENTO

directo		intercambio directo
logaritmico quicksort
el INT aguanta valores desde 2-31 a 2 31 -1
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int interdire (int [], int );
int quicksort (int [], int);

void tarea() {
    // Simulación de una tarea que consume tiempo
    for (int i = 0; i < 100000000; i++);
}

int main(){
	srand(time(0));

    int i, n, opcion;
    cout << "INGRESE LA CANTIDAD DE VALORES DE SU ARREGLO" << endl;
    cin >> n;
    int arreglo1[n];
    int arreglo2[n];
    cout << "LOS VALROES DEL ARREGLO SON " << endl;
    
    for (i=1; i<=n; i++){
    	
    	arreglo1 [i] = rand() % 1000+1;
    	arreglo2 [i] = arreglo1[i];
    	cout << arreglo1[i] << " ";
	}
	cout << "\n" << endl;

	do {
		cout << "\nESCOGE UNA OPCION " << endl;
		cout << "1- Ordenar por interacmbio directo "<< endl;
		cout << "2- Ordenar por el metodo shellsort " << endl;
		cout << "3- Mostrar tiempos de ejecucion  " << endl;
		cout << "4- Salir  del programa  " << endl;
		
		cin >> opcion;
		switch (opcion){
			case 1: {
				cout << "ORDENAMIENTO INTERCAMBIO DIRECTO" << endl;
				
				clock_t start = clock();
				tarea(); 
				quicksort(arreglo1, n);
				clock_t end = clock();
				cout << "ORDENADO1" << endl;
				for (i=1; i<=n; i++){
    		    	cout << arreglo1 [i] << " ";

				}
				double duracion_segundos1 = double(end - start) / CLOCKS_PER_SEC;
				double duracion1 = double(end - start) / CLOCKS_PER_SEC * 1000.0;
				
				/*
				for (i=1;i<=n;i++){
					cout << arreglo[i] << " ";
				}
				cout << "\n";
				*/
				cout << "\n" << endl;
				cout << "Tiempo de ejecucion: " << duracion_segundos1 << " s" << endl;
				cout << "Tiempo de ejecucion: " << duracion1 << " ms" << endl;
				break;
			}
				
				
				
			case 2: {
				cout << "ORDENAMIENTO POR SHELLSORT " << endl;
				
				clock_t start = clock();
				tarea();
				quicksort(arreglo2, n);
				clock_t end = clock();
				cout << "ORDENADO2" << endl;
				for (i=1; i<=n; i++){
    		    	cout << arreglo2 [i]<< " ";
				}
				double duracion_segundos2 = double(end - start) / CLOCKS_PER_SEC;
				double duracion2 = double(end - start) / CLOCKS_PER_SEC * 1000.0;
				/*
				for (i=1;i<=n;i++){
					cout << arreglo[i] << " ";
				}
				*/
				cout << "\n";
				cout << "Tiempo de ejecucion: " << duracion_segundos2 << " s" << endl;
				cout << "Tiempo de ejecucion: " << duracion2 << " ms" << endl;
				break;			
			}
				
			case 3:
				cout << "Saliendo del programa" << endl;
				break;
			
			default :
				cout << "Valor invalido" << endl;
				break;
		}
	} while (opcion != 4);
	
	return 0; 
}

int interdire (int arreglo[],int x){
	int i,j,aux,k;
	cout << "ORDENADO1" << endl;
	for (i = 1; i <= x - 1; i++) {
    	for (j = 1; j <= x - i; j++) {
        	if (arreglo[j] > arreglo[j + 1]) {
            	
				for (k=1; k<=x; k++){
    		    	cout << arreglo[k] << " ";

				}
				cout << endl;
				int aux = arreglo[j];
           	 	arreglo[j] = arreglo[j + 1];
           	 	arreglo[j + 1] = aux;
        	}
    	}
	}
}

int reduce(int ar[], int inicio, int final){
	int izq, der, pos, cen, aux;
	izq = inicio;
	der = final;
	pos = izq;
	cen = 1;
	while (cen == 1){
		cen = 0;
		// recorrido de derecha a izquierda
		while (ar[pos] <= ar[der] && pos != der){
			der = der - 1;	
		}
		if ( pos != der )	{
			aux = ar[pos];
			ar[pos] = ar[der];
			ar[der] = aux;
			pos = der;
			//recorrido de izquierda a derecha
			while (ar[pos] >= ar[izq] && pos != izq){
				izq = izq + 1;
			}
			if (pos != izq){
				aux = ar[pos];
				ar[pos] = ar[der];
				ar[der] = aux;
				pos = izq;
				cen = 1;
			}
		}
		if (pos - 1 > inicio ){
			/*llamado recursivo a quicsort
			para el subarreglo izquierdo*/
			reduce(ar, inicio, pos -1);
		}
		if (pos + 1 < final ){
			/* Llamado recursivo a Quicksort
			para el subarreglo derecho*/
			reduce(ar, pos +1, final);
		}
	}
}
int quicksort(int ar[], int x){
	reduce(ar, 0, x );
}
