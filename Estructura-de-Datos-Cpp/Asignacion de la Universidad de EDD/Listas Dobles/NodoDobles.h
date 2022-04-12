#include <iostream>
template<class T>
class Nodo {
	T clave;
	Nodo <T> *previo;
	Nodo <T> *proximo;
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
	void FijarPrevio(Nodo<T> *x) {
		previo = x;
	}
	Nodo<T> *ObtenerPrevio() {
		return previo;
	}
	void FijarProximo(Nodo<T> *x) {
		proximo = x;
	}
	Nodo <T> *ObtenerProximo() {
		return proximo;
	}
};

//la h significa header 

