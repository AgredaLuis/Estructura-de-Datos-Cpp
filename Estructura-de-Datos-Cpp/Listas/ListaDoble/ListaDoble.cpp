#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class T>
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
class ListaDoble {
	Nodo<T> *inicio;
public:
	ListaDoble() {
		inicio = NULL;
	}
	void Insertar(Nodo<T> *x);
	void Eliminar(Nodo<T> *x);
	void InvertirLista() {
		Nodo <T> *primero, *resto;
		primero = inicio;
		while (1) {
			resto = primero->ObtenerProximo();
			primero->FijarProximo(primero->ObtenerPrevio());
			primero->FijarPrevio(resto);
			if (resto->ObtenerProximo() == NULL) {
				resto->FijarPrevio(NULL);
				resto->FijarProximo(primero);
				inicio = resto;
				break;
			}
			else {
				primero = primero->ObtenerPrevio();
			}
		}
	}
	Nodo<T> *Buscar(T K) {
		Nodo <T>*x = inicio;

		while (x != NULL && x->ObtenerClave() != K)
			x = x->ObtenerProximo();
		return x;
	}
	void MostrarNodos() {
		Nodo<T> *x = inicio;
		cout << endl;
		do {
			cout << x->ObtenerClave() << endl;
			x = x->ObtenerProximo();
			
		} while (x != NULL);

	}
	void MostrarNodosConPrevio() {
		Nodo<T>*x = inicio;
		while (x->ObtenerProximo() != NULL) {
			x = x->ObtenerProximo();
		}
		while (x != NULL) {
			cout << "Coincidencia encontrada al reves:" << x->ObtenerClave() << endl;
			x = x->ObtenerPrevio();
		}
	}
	
	
	void InsertarOrdenado(Nodo<T> *x) {
		Nodo<T> *y = inicio;
			if (y != NULL) {
				while (x->ObtenerClave() >= y->ObtenerClave()) {
					if (y->ObtenerProximo() == NULL) {
						break;
					}
					y = y->ObtenerProximo();
				}
				if (y == inicio && y->ObtenerClave() > x->ObtenerClave()) {
					//caso para cuando ingresas un valor menor al del primer nodo de la lista
					//Acá, el valor ingresado pasa a ser el inicio de la lista
					y->FijarPrevio(x);
					x->FijarProximo(y);
					x->FijarPrevio(NULL);
					inicio = x;
				}
				else {
					if (y->ObtenerProximo() != NULL) {
						//caso para nodos intermedios. Se inserta el nodo
						y->ObtenerPrevio()->FijarProximo(x);
						x->FijarPrevio(y->ObtenerPrevio());
						x->FijarProximo(y);
						y->FijarPrevio(x);
					}
					else {
						if (y->ObtenerClave() > x->ObtenerClave()) {
							//caso para cuando se esta en el ultimo nodo y el ultimo valor ingresado
							//es menor al ultimo nodo
							y->ObtenerPrevio()->FijarProximo(x);
							x->FijarPrevio(y->ObtenerPrevio());
							y->FijarPrevio(x);
							x->FijarProximo(y);
						}
						else {
							//caso para ingresar un nodo al final de la lista
							y->FijarProximo(x);
							x->FijarPrevio(y);
							x->FijarProximo(NULL);
						}

					}
				}

			}
			else {
				Insertar(x);
			}
		}
	~ListaDoble() {
		Nodo<T> *x;
		while (inicio != NULL) {
			x = inicio;
			inicio = inicio->ObtenerProximo();
			delete x;
		}
	}
};
template <class T>
void ListaDoble<T>::Insertar(Nodo<T>* x) {
	x->FijarProximo(inicio);
	if (inicio != NULL)
		inicio->FijarPrevio(x);
	inicio = x;
	x->FijarPrevio(NULL);
	return;
}
template <class T>
void ListaDoble<T>::Eliminar(Nodo<T>*x) {
	if (x->ObtenerPrevio() != NULL)
		x->ObtenerPrevio()->FijarProximo(x->ObtenerProximo());
	else
		inicio = x->ObtenerProximo();
	if (x->ObtenerProximo() != NULL)
		x->ObtenerProximo()->FijarPrevio(x->ObtenerPrevio);
	delete x;
	return;
}
int main() {
	ListaDoble <int> l;
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
		l.InsertarOrdenado(x);
		cout << "Quiere insertar otro nodo? 0 para salir" << endl;
		cin >> opc;
		cin.ignore();
		if (opc == 0)
			valid = true;
	} while (valid == false);
	l.MostrarNodos();
	l.InvertirLista();
	l.MostrarNodosConPrevio();
	l.~ListaDoble();
}
