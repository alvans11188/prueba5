/*BUSQUEDA EJERCICIO
1- Se tiene un polinomio almacenado en un arreglo. Se pide leer un monomio y buscar si forma parte del polinomio. Usar busqueda secuencial*/
#include <iostream>
using namespace std;
struct polinomio {
    int coef; 
    int exp;  
};

int secuencialdes(polinomio t[], int n, int b1, int b2){
	int pos, i;
	pos = 0;
	i = 1;
	while (i<=n && t[i].coef != b1 && t[i].exp != b2){
		i=i+1;
	}
	if(i<=n){
		pos = i;
	}
	return pos;
}

int main() {
    int i, buscar1, buscar2,s;
    int n = 4;
    cout << "EL POLINOMIO SERA :" << endl;
    polinomio polinomios[n] = {{0,0},{1,2},{2,3},{3,4}};
    
     for (i = 1; i < n; i++) {
        
        cout << polinomios[i ].coef << "X^" << polinomios[i].exp;
        if (i != n) {
            cout << " + ";  
        }
    }
    cout << "Ingrese el coeficiente y exponente que desea buscar en el polinomio: " << endl;
    cout << "coeficiente: ";
    cin >> buscar1;
    cout << "exponente: ";
    cin >> buscar2;
    s=secuencialdes(polinomios,n,buscar1,buscar2);
    cout << s << endl;
     if (s > 0) {
        cout << "El monomio " << buscar1 << "x^" << buscar2 << " se encuentra en la posicion: " << s << endl;
    } else {
        cout << "El monomio " << buscar1 << "x^" << buscar2 << " no se encontro." << endl;
    }
    return 0;
}

