/*
4-Se tienen los siguientes atributos de personal : DNI, nombres, día, mes y año de nacimiento. 
Se pide realizar una búsqueda binaria por fecha de nacimiento. 
Sugerencia: Use dos registros (personal y fecha) y tres funciones (uno para ordenar el arreglo 
por cada inserción, otro para la búsqueda y el último para comparar fechas). Asuma que nadie comparte la misma fecha de nacimiento
*/
#include <iostream>
#include <string>
using namespace std;
struct personal{
	string dni;
	string nom;
};
struct fecha{
	int dia;
	int mes;
	int anio;
};

int ordenarinsercion(int n, fecha f[], personal p[]) {
    for (int i = 1; i < n; i++) { 
        fecha aux = f[i]; 
        personal auxPersonal = p[i]; 
        int j = i - 1;

       
        while (j >= 0 && ((f[j].anio > aux.anio) || 
                          (f[j].anio == aux.anio && f[j].mes > aux.mes) || 
                          (f[j].anio == aux.anio && f[j].mes == aux.mes && f[j].dia > aux.dia))) {
            f[j + 1] = f[j]; 
            p[j + 1] = p[j]; 
            j--;
        }
        f[j + 1] = aux; 
        p[j + 1] = auxPersonal; 
    }
    return 0;
}
int comparar(int n, fecha f[]) {
	int pos,i,j;
	pos = 0;
    for ( i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            if (f[i].dia == f[j].dia && f[i].mes == f[j].mes && f[i].anio == f[j].anio) {
                pos = pos +1; 
            }
        }
    }
    return pos;
}
int buscarbinaria(int n, fecha f[], personal p[],int anio, int mes, int dia){
	int izq,der,cen,pos,m;
	izq = 1;
	der = n;
	cen = 0;
	while (izq <= der && cen == 0){
		m =((izq+der)/2);
		if(f[m].anio == anio && f[m].mes == mes && f[m].dia==dia){
			cen = 1;
		}else{
			if(anio>f[m].anio && mes > f[m].mes && dia > f[m].dia){
				izq = m + 1;
			}else{
				der = m - 1;
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
int main(){
	int i,n, s,b;
	int buscar1, buscar2, buscar3;
	cout << "Ingrese la cantidad del personal" << endl;
	cin >> n;
	fecha fechas[n];
	personal personals[n];
	cout << "Ingrese los atributos del personal " << endl;
	for(i=0;i<n;i++){
		cout << "PERSONAL: " << i+1 << endl;
		/*cin >> personals[i].dni;
		cin >> personals[i].nom;*/
		cout << "Dia: ";
		cin >> fechas[i].dia;
		cout << "Mes: ";
		cin >> fechas[i].mes;
		cout << "Anio: ";
		cin >> fechas[i].anio;
		cout << "\n" << endl;
	}
	
	ordenarinsercion(n,fechas,personals);
	
	for(i=0;i<n;i++){
		cout << "PERSONAL: " << i+1 << endl;
		/*cout << personals[i].dni;
		cout << personals[i].nom;*/
		cout << " Dia: ";
		cout << fechas[i].dia;
		cout << " Mes: ";
		cout << fechas[i].mes;
		cout << " Anio: ";
		cout << fechas[i].anio;
		cout << "\n" << endl;
	}
	cout << "INGRESE LA FECHA QUE DESEA BUSCAR: " << endl;
	cout << "Anio: ";
	cin >> buscar1;
	cout << "Mes: ";
	cin >> buscar2;
	cout << "Dia: ";
	cin >> buscar3;
	b = buscarbinaria(n,fechas,personals,buscar1,buscar2,buscar3);
	cout << "BUSQUEDA DE FECHA" << endl;
	if (b!=0){
		cout << "Existe fechas buscada " << endl;
	}else{
		cout << "Ninguna fecha encontrada " << endl;
	}
	cout << "COMPARACION DE FECHAS" << endl;
	s = comparar(n,fechas);
	if (s>0){
		cout << "Existen fechas iguales " << endl;
	}else{
		cout << "Ninguna fecha es igual " << endl;
	}
	
	return 0;
}
