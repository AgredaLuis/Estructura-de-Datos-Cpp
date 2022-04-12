#include <iostream>
#include <string>
#include "NodoDobles.h"
using namespace std;

template<class T>
class ListaDoble {
	Nodo<T> *inicio;
public:
	ListaDoble() {
		inicio = NULL;
	}
	
	Nodo<T> *ObtenerInicio() {
		return inicio;
	}
	void Insertar(Nodo<T> *x) {
		x->FijarProximo(inicio);
		if (inicio != NULL) {
			inicio->FijarPrevio(x);
		}
		inicio = x;
		x->FijarPrevio(NULL);
	}
	Nodo <T> *Buscar(T k) {//Sino Encuentra la clave, retorna un valor NULL
		Nodo<T> *x = inicio;
		while (x != NULL && k != x->ObtenerClave()) {
			x = x->ObtenerProximo();
		}
		return x;
	}
	
	void Eliminar(Nodo<T> *x) {
		if (x->ObtenerPrevio() != NULL) {
			x->ObtenerPrevio()->FijarProximo(x->ObtenerProximo());
		}
		else {
			inicio = x->ObtenerProximo();
		}
		if (x->ObtenerProximo() != NULL) {
			x->ObtenerProximo()->FijarPrevio(x->ObtenerPrevio());
		}
	}
	void MostrarLista() {
		Nodo<T> *x = inicio;
		cout << endl;
		do {
			cout << x->ObtenerClave() << endl;
			x = x->ObtenerProximo();
		} while (x!= NULL);
		
		
	}
	~ListaDoble() { //destructor
		Nodo<T>*y;
		while (inicio != NULL) {
			y = inicio;
			inicio = inicio->ObtenerProximo();
			delete y;
		}
	}
};
