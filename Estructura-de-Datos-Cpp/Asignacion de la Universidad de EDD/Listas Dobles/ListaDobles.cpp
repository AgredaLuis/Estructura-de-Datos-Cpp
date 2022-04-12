#include <iostream>
#include "ListaDoble.h"
using namespace std;

int main(int argc, char *argv[]) {
	system("color 0b");
	int op;
	Nodo<int> *node;
	ListaDoble<int> ld;
	
	
	int dato;
	cout << "Menu:" << endl;
	cout << "******" << endl;
	do {
		do {
			cout << "Ingrese una opcion: \n 1) Añadir elemento a la lista,\n 2) Eliminar Elemento de la lista,\n 3) Mostrar la lista \n" << endl;
			cin >> op;
		} while (op < 1 || op>5);
		
		switch (op) {
		case 1:
			node = new Nodo<int>;
			cout << "Ingresa el valor a ingresar en la lista" << endl;
			cin >> dato;
			node->FijarClave(dato);
			ld.Insertar(node);
			cout << "Agregado Exitosamente!" << endl;
			break;
		case 2:
			cout << "Ingrese el numero a eliminar de la lista" << endl;
			cin >> dato;
			Nodo<int> *n;
			n = ld.Buscar(dato);
			if (n != NULL) {
				ld.Eliminar(n);
			}
			else {
				cout << "El numero no se ha encontrado en la lista" << endl;
			}
			break;
		case 3:
			ld.MostrarLista();
			break;
		}
		
	} while (op != 5);
	
	
	system("pause");
	return 0;
}

