/*BUSQUEDA BINARIA
Para este caso es necesario tener el arreglo ordenado obligatoriamente
contrariamente al metodo busqueda secuencial q no es necesario
*/
#include <iostream>
using namespace std;
int binaria(int [], int, int);
int main(){
	int i,j,buscar,s;
	int n = 11;
	int arreglo[n]= {0,101,315,325,410,502,507,600,610,612,670};
	cout << "LOS VALORES DEL ARREGLO SON: " << endl;
	for (i=1;i<n;i++){
		cout << "El valor " << i << " tiene el valor de: " << arreglo[i] << endl;
	}
	
	cout << "Que valor deseas buscar " << endl;
	cin >> buscar;
	s = binaria(arreglo, n, buscar);
	if (s<0){
		cout << "El valor " << buscar << " nose encuentra en arreglo" << endl;
	}else{
		cout << "El valor " << buscar << " se encuentra en la posicion: " << s << endl;
	}
	
	return 0;
}

int binaria(int a[], int n,int dato){
	int m ,izq ,der ,pos , i, cen;
	izq = 1;
	der = n;
	cen = 0;
	while (izq <= der && cen == 0){
		m = ((izq + der)/2);
		if (a[m]== dato){
			cen = 1;
		}else{
			if (dato>a[m]){
				izq = m+1;
			}else{
				der = m-1;
			}
		}
	}
	if (cen == 1){
		pos = m;
	}else{
		pos = -1*izq;
	}
	
	return pos;
}

