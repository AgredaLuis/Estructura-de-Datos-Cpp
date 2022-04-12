

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class Nodo {
	T clave;
	Nodo<T> *previo;
	Nodo<T> *proximo;
public:
	Nodo() {
		previo = proximo = NULL;
	}
	void FijarClave(T c) {
		clave = c;
	}
	T ObtenerClave() {
		return clave;
	}
	void FijarPrevio(Nodo <T>*x) {
		previo = x;
	}
	Nodo<T> *ObtenerPrevio() {
		return previo;
	}
	void FijarProximo(Nodo <T>*x) {
		proximo = x;
	}
	Nodo<T> *ObtenerProximo() {
		return proximo;
	}
};

template <class T>
class ListaDobleCircular{
	Nodo<T> *S;
public:
	ListaDobleCircular() {
		S = new Nodo <T>;
		S->FijarProximo(S);
		S->FijarPrevio(S);
	}
	void Insertar(Nodo<T> *x) {
		x->FijarProximo(S->ObtenerProximo());
		S->ObtenerProximo()->FijarPrevio(x);
		S->FijarProximo(x);
		x->FijarPrevio(S);
	}
	Nodo<T> *Buscar(T K) {
		Nodo<T> *x = S->ObtenerProximo();
		while (x != S && x->ObtenerClave != K)
			x = x->ObtenerProximo();
		return x;
	}
	void Eliminar(Nodo<T>*x) {
		x->ObtenerPrevio()->FijarProximo(x->ObtenerProximo());
		x->ObtenerProximo()->FijarPrevio(x->ObtenerPrevio());
	}
	void InvertirLista() {//ListaDobleCircular
		Nodo<T> *aux=S->ObtenerProximo();
		while (aux!=S) {
			Nodo<T>*siguiente = aux->ObtenerProximo();
			aux->FijarProximo(aux->ObtenerPrevio());
			aux->FijarPrevio(siguiente);
			aux = siguiente;
		}
		aux = S->ObtenerPrevio();
		S->FijarPrevio(S->ObtenerProximo());
		S->FijarProximo(aux);
	}
	void InvertirListaDobleRecursivo(Nodo<T> *x) {
		Nodo<T> *primero, *resto, *aux;
		if (x == S && S->ObtenerProximo() == S) {
			return;
		}
		if (x == S) {
			x = x->ObtenerProximo();
		}
		primero = x;
		resto = x->ObtenerProximo();
		if (resto == S) {
			S->FijarPrevio(S->ObtenerProximo());
			S->FijarProximo(primero);
			return;
		}
		InvertirListaDobleRecursivo(resto);
		resto->FijarPrevio(resto->ObtenerProximo());
		resto->FijarProximo(primero);
		if (x==S->ObtenerPrevio()) {
			x->FijarProximo(S);
			x->FijarPrevio(resto);
		}
	}
	void BuscarOcurrencias(ListaDobleCircular &listaocurrencia,T var) {
		Nodo<T> *x = S->ObtenerProximo(), *ocurrencia;
		while (x != S) {
			if (x->ObtenerClave() == var) {
				ocurrencia = new Nodo<T>;
				ocurrencia->FijarClave(x->ObtenerClave());
				listaocurrencia.Insertar(ocurrencia);
			}
			x = x->ObtenerProximo();
		}
	}
	Nodo<T> *ObtenerS() {
		return S;
	}
	void MostrarNodos() {
		Nodo<T> *x = S->ObtenerProximo();
		while (x != S) {
			cout<<"Informacion encontrada: "<< x->ObtenerClave()<<endl;
			x = x->ObtenerProximo();
		}
	}
	~ListaDobleCircular() {
		Nodo<T> *x = S->ObtenerProximo();
		while (x != S) {
			Nodo<T> *y = x->ObtenerProximo();
			delete x;
			x = y;
		}
		delete(S);
	}
};

int main(){
	ListaDobleCircular <int> ldc, loc;
	Nodo <int> *x;
	bool valid;
	int opc;
	do {
		valid = false;
		cout << "Introduzca el numero que quiere insertar en el nodo" << endl;
		cin >> opc;
		cin.ignore();
		x = new  Nodo <int>;
		x->FijarClave(opc);
		ldc.Insertar(x);
		cout << "Quiere insertar otro nodo? 0 para salir" << endl;
		cin >> opc;
		cin.ignore();
		if (opc == 0)
			valid = true;
	} while (valid == false);
	ldc.MostrarNodos();
	cout << "Introduzca un numero a buscar como ocurrencia" << endl;
	cin >> opc;
	cin.ignore();
	ldc.BuscarOcurrencias(loc, opc);
	loc.MostrarNodos();
	ldc.MostrarNodos();
	system("pause");
}


