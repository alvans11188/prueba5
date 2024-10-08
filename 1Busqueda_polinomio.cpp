/*BUSQUEDA EJERCICIO
1- Se tiene un polinomio almacenado en un arreglo. Se pide leer un monomio y buscar si forma parte del polinomio. Usar busqueda secuencial*/
#include <iostream>
using namespace std;

struct termino {
    int coef; 
    int exp;  
};




int secuencialdes(termino t[], int n, int b1, int b2){
	int pos, i;
	pos = 0;
	i = 1;
	while (i<=n && t[i].coef != b1, t[i].exp != b2){
		i=i+1;
	}
	if(i<=n){
		pos = i;
	}
	return pos;
}

int main() {
    int i, buscar1, buscar2;
    int n, s;

    cout << "Ingrese la cantidad de monomios que desea ingresar (coeficiente, exponente): ";
    cin >> n;
    
    
    termino terminos[n];
    
    
    for (i = 0; i < n; i++) {
        cout << "Ingrese el coeficiente: ";
        cin >> terminos[i].coef;
        cout << "Ingrese el exponente: ";
        cin >> terminos[i].exp;
        cout << "Registrado\n";
    }

    
    cout << "Terminos ingresados: " << endl;
    for (i = 0; i < n; i++) {
        cout << "Monomio " << i + 1 << ": " << terminos[i].coef << "x^" << terminos[i].exp << endl;
    }

    
    cout << "Ingrese el coeficiente y exponente a buscar: " << endl;
    cout << "Coeficiente: ";
    cin >> buscar1;
    cout << "Exponente: ";
    cin >> buscar2;

    
    s = secuencialdes(terminos, n, buscar1, buscar2);

    
    if (s > 0) {
        cout << "El monomio " << buscar1 << "x^" << buscar2 << " se encuentra en la posicion: " << s + 1 << endl;
    } else {
        cout << "El monomio " << buscar1 << "x^" << buscar2 << " no se encontró." << endl;
    }

    return 0;
}

