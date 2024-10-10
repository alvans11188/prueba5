/*BUSQUEDA EJERCICIO
2-Se tienen los siguientes atributos de un articulo codigo, descripcion, precio, cantidad
Ordene un conjunto de articulos descendentemente segun el monto de la inversion.
El monto de inversion se calcula multiplicando el precio de cada articulo por la cantidad de articulos. 
Use ordenacion por intercambio directo por la derecha
*/
#include <iostream>
#include <string>
using namespace std;

struct articulo {
    string cod;
    string des;
    int pre;
    int cant;
    int inv;
};

int ordenaDes(int n, articulo a[]);

int main() {
    int i, n;
    cout << "Ingrese la cantidad de articulos" << endl;
    cin >> n;
    
    articulo articulos[n];  

    for (i = 0; i < n; i++) { 
        cout << "Ingrese el codigo/descripcion/precio/cantidad" << endl;
        cin >> articulos[i].cod;
        cin >> articulos[i].des;
        cin >> articulos[i].pre;
        cin >> articulos[i].cant;
        cout << "\n" << endl;
    }

    ordenaDes(n, articulos);

    cout << "EL ORDEN DE LOS ARTICULOS ES:" << endl;

    for (i = 0; i < n; i++) {  
        cout << "Articulo numero " << i + 1 << endl;
        cout << "Codigo: " << articulos[i].cod << endl;
        cout << "Descripcion: " << articulos[i].des << endl;
        cout << "Precio: " << articulos[i].pre << endl;
        cout << "Cantidad: " << articulos[i].cant << endl;
        cout << "Inversion: " << articulos[i].inv << endl;
        cout << "\n" << endl;
    }
    return 0;
}

int ordenaDes(int n, articulo a[]) {
    int i, j;
    articulo aux;

    for (i = 0; i < n; i++) { 
        a[i].inv = a[i].pre * a[i].cant;
    }

    for (i = 0; i < n; i++) {
        cout << "Inversion del articulo " << i + 1 << ": " << a[i].inv << endl;
    }

    for (i = 0; i < n - 1; i++) {  
        for (j = 0; j < n - i - 1; j++) {  
            if (a[j].inv < a[j + 1].inv) {  
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    return 0;
}
