/* ORDENACION DE UN POLINOMIO
Ordenacion de terminos segun el grado de del exponente
* se ingresan terminos para cada exponente y coeficiente
* se ordena descendientemente segun el exponente*/

#include <iostream>
using namespace std;

struct termino{
	int coef;
	int exp;
};
void ordenarPol(int n,termino t[]){
	int i,j;
	termino aux;
	for (i=0;i<=n;i++){
		for (j=0;j<n-i-1;j++){
			if(t[j].exp < t[j+1].exp){
				aux = t[j];
				t[j]= t[j+1];
				t[j+1] = aux;
			}
		}
	}
}
int main(){
	int i,j;
	int n;
	cout << "Ingrese la cantidad de monomios que desea ingresar (coeficiente, exponente)" << endl;
	cin >> n;
	termino terminos[n];
	for (i=0;i<n;i++){
		cout << "Ingrese el coeficiente: ";
        cin >> terminos[i].coef;
        cout << "Ingrese el exponente: ";
        cin >> terminos[i].exp;
        cout << "Registrado\n";
		
	}
	cout << "Terminos ingresados: " << endl;
    for (i = 0; i < n; i++) {
        cout << "Monomio " << i+1 << ": " << terminos[i].coef << "x^" << terminos[i].exp << endl;
    }
    ordenarPol(n,terminos);
    
    cout << "\nTérminos ordenados por exponente descendente:\n";
    for (i = 0; i < n; i++) {
        cout << "Monomio " << i+1 << ": " << terminos[i].coef << "x^" << terminos[i].exp << endl;
    }    
	return 0;
}
