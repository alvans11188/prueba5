#include <iostream>
using namespace std;

int shellsort(int [], int);

int main(){
	int n=11;
	int arreglo[n] = {0,5,4,3,2,1,6,7,8,10,9};
	
	int i;
	for (i=1;i<n;i++){
		cout << "El elemento "<< i  << " del arreglo es: " << arreglo[i] << endl;
		
	}
	
	cout << "ORDENAMIEN''TO SHELLSORT " << endl;
	shellsort(arreglo,n);
	for (i=1;i<n;i++){
		cout << "El elemento "<< i  << " del arreglo es: " << arreglo[i+1] << endl;	
	}
	
	return 0;
}
int shellsort(int arreglo[], int x){
	int i,k,cen,aux;
	k = x+1;
	while (k>1){
		k = k/2;
		cen = 1;
		while (cen == 1){
			cen = 0;
			i=1;
			while ( i+k <= x){
				if (arreglo[i+k] < arreglo[i]){
					aux = arreglo[i];
					arreglo[i] = arreglo[i+k];
					arreglo[i+k] = aux;
					cen = 1;
				}
				i = i+1;
			}
		}
	}
}
