
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
class Nodo {
	T clave;
	Nodo<T> *proximo;
public:
	Nodo() {
		proximo = NULL;
	}
	void FijarProximo(Nodo <T>*x) {
		proximo = x;
	}
	Nodo<T> *ObtenerProximo() {
		return proximo;
	}
	void FijarClave(T c) {
		clave = c;
	}
	T ObtenerClave() {
		return clave;
	}
};
template <class T>
class ListaSimple {
	Nodo <T> *inicio;
public:
	ListaSimple(){
		inicio = NULL;
	}
	void Insertar(Nodo<T> *x) {
		x->FijarProximo(inicio);
		inicio = x;
	}
	void Eliminar(Nodo<T> *k) {
		Nodo<T> *x;
		if (k == inicio) {
			inicio = k->ObtenerProximo();
			return;
		}
		else {
			x = inicio;
			while (x != NULL && x->ObtenerProximo() != k)
				x = x->ObtenerProximo();
		}
		if (x != NULL) {
			x->FijarProximo(k->ObtenerProximo());
		}
		delete k;
	}
	void Recortar(int m) {
		Nodo<T> *x = inicio;
		Nodo<T> *y=inicio;
		Nodo<T> *z;
		int contador = 1;
		while (x != NULL) {
			if (contador >= m) {
				z = x;
				x = x->ObtenerProximo();
				z->FijarProximo(NULL);
				while (x != NULL) {
					y = x;
					x = x->ObtenerProximo();
					delete(y);
				}
			}
			else {
				x = x->ObtenerProximo();
				contador++;
			}
		}
	}
	void EliminarOcurrencias(T key) {
		Nodo<T> *x = inicio;
		Nodo<T> *y;
		while (x != NULL) {
			if (x->ObtenerClave() == key) {
				y = x->ObtenerProximo();
				Eliminar(x);
				x = y;
			}
			else
			{
				x = x->ObtenerProximo();
			}
		}
	}
	void MostrarNodos() {
		Nodo <T>*x = inicio;
		while (x != NULL) {
			cout << "info encontrada:" << x->ObtenerClave() << endl;
			x = x->ObtenerProximo();
		}
	}
	~ListaSimple() {
		Nodo<T> *x;
		while (inicio != NULL) {
			x = inicio;
			inicio = inicio->ObtenerProximo();
			delete(x);
		}
	}
};

int main(){
	Nodo<int> *x;
	ListaSimple<int> ls;
	int opc;
	do {
		cout << "Introduzca un numero a ingresar en la lista" << endl;
		cin >> opc;
		cin.ignore();
		x = new Nodo<int>;
		x->FijarClave(opc);
		ls.Insertar(x);
		cout << "Desea ingresar mas nodos? presione 0 para salir" << endl;
		cin >> opc;
		cin.ignore();
	} while (opc != 0);
	ls.MostrarNodos();
	cout << "Ingrese Eliminar ocurrencias lista" << endl;
	cin >> opc;
	cin.ignore();
	//ls.Recortar(opc);
	ls.EliminarOcurrencias(opc);
	ls.MostrarNodos();
    
}

