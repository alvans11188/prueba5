/*
También conocido como quicksort, este método es otra de las variantes del método de intercambio directo,
 que se caracteriza por ser la más rápida en memoria interna.  

Consiste en encontrar la posición de un cierto elemento del arreglo, 
al que llamaremos pivote, de tal manera que todos los valores que se encuentren a su izquierda 
sean menores o iguales a él y los que se encuentren a su derecha sean mayores o iguales a él.
 Este proceso se repite para cada uno de los valores que queden a la izquierda y a la derecha del pivote. 
 
*/

#include <iostream>
using namespace std;

int quicksort(int [], int);
int reduce(int [], int, int);
int main(){
	int i;
	int n = 10;
	int arreglo[n] = {3,5,2,8,6,1,4,10,7,11};
	//1,2,3,4,5,6,7,8,10,11
	cout << "LOS VALORES DEL ARREGLO SON " << endl;
	for (i = 0; i<n;i++){
		cout << "El valor " << i+1  << " del arreglo es: " << arreglo[i] << endl;
	}
	quicksort(arreglo, n);
	
	cout << "\nARREGLO ORDENADO POR EL METODO QUICKSORT" << endl;
	for (i = 0; i<n;i++){
	cout << "El valor " << i+1  << " del arreglo es: " << arreglo[i] << endl;
	}
	cout << "FIN DEL PROGRAMA ";
	return 0;
}

int quicksort(int ar[], int x){
	reduce(ar, 0, x );
}

int reduce (int ar[], int inicio, int final){
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
