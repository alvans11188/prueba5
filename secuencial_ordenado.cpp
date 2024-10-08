/*
BUSQUEDA SECUENCIAL ORDENADO
*/
#include <iostream>
using namespace std;
int secuencialord(int [], int, int);
int main (){
	
	int i,j,buscar,s;
	int n = 8;
	int arreglo[n] = {0,3,8,9,11,15,23,35};
	cout << "LOS VAL{}RES DEL ARREGLO SON " << endl;
	for (i=1;i<n;i++){
		cout << "El valor " << i << " es de: " << arreglo[i] << endl;
	}
	cout << "Que dato desea buscar? " << endl;
	cin >> buscar;
	
	s = secuencialord(arreglo,n,buscar);
	if ( s > 0){
		cout << "El valor ingresado se encuentra en la posicion: " << s << endl;
	} else {
		cout << "El valor ingresado no se encuentra en el arreglo" << endl;
	}
	
	return 0;
}

int secuencialord(int a[],int n, int dato){
	int i, pos;
	i=1;
	while (i<=n && a[i] < dato) {
		i=i+1;
	}
	if (i>n || a[i] > dato){
		pos = -i;
	}else{
		pos = i;
	}
	return pos;
}
