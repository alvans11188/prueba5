/*METODO DE BUSQUEDA SECUENCIAL DESORDENADO*/
#include <iostream>
using namespace std;
int secuencialdes(int a[], int n, int dato){
	int pos, i;
	pos = 0;
	i = 1;
	while (i<=n && a[i] != dato){
		i=i+1;
	}
	if(i<=n){
		pos = i;
	}
	return pos;
}

int main(){
	int i,j, buscar, s,pos;
	int n = 8;
	int arreglo[n] = {0,18,14,23,12,48,56,8};
	cout << "LOS DATOS DEL ARREGLO SON:" << endl;
	for (i=1;i<n; i++){
		cout << "El valor numero " << i << " es : " << arreglo[i] << endl;
	}
	do {
		cout << "\nQue valor desea buscar? " << endl;
		cin >> buscar;
		s= secuencialdes(arreglo,n,buscar);
		if (s == 0){
			cout << "El valor buscado no existe en el arreglo" << endl;
		}else{
			cout << "El valor " << buscar << " se encuentra en la posicion " << s << endl;
		}
		
	} while (buscar != 0);

	
	return 0;
}

