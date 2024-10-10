/*
3-Se tienen los siguientes atributos de personal, DNI, nombres, dia, mes y año de nacimiento. 
Se pide ordenar por fecha de nacimiento.
Sugerencia: use dos registros (uno para personal y otro para fecha) y dos funciones (una para ordenacion por seleccion 
directa y otra para la comparacion de dos fechas)

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

int ordenar(int n, fecha f[], personal p[]) {
    int i, j, menor,k;
    
    for (i = 0; i < n - 1; i++) {
        menor = i; 
        k=i;
        for (j = i + 1 ; j < n; j++) {
            
            if ((f[j].anio < f[menor].anio) || 
               (f[j].anio == f[menor].anio && f[j].mes < f[menor].mes) || 
               (f[j].anio == f[menor].anio && f[j].mes == f[menor].mes && f[j].dia < f[menor].dia)) {
                
				menor = j; 
				k=j;
            }
        }
        fecha auxFecha = f[i];   
        f[i] = f[menor];         
        f[menor] = auxFecha;     

        
        personal auxPersonal = p[i];  
        p[i] = p[menor];               
        p[menor] = auxPersonal; 
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
int main(){
	int i,n, s;
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
	
	ordenar(n,fechas,personals);
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
	s = comparar(n,fechas);
	if (s>0){
		cout << "Existen fechas iguales " << endl;
	}else{
		cout << "Ninguna fecha es igual " << endl;
	}
	
	return 0;
}
