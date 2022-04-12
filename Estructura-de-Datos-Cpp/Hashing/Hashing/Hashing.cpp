
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
const int U = 2000;
const int alpha = 3;
const int m = 701;
template <class T>
class ListaDoble {
	Nodo<T> *inicio;
public:
	ListaDoble() {
		inicio = NULL;
	}
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
	Nodo<T> *BuscarNodo(int K) {
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
	 void InsertarNodo(Nodo<T>* x) {
		x->FijarProximo(inicio);
		if (inicio != NULL)
			inicio->FijarPrevio(x);
		inicio = x;
		x->FijarPrevio(NULL);
		return;
	}
	 void EliminarNodo(Nodo<T>*x) {
		 if (x->ObtenerPrevio() != NULL)
			 x->ObtenerPrevio()->FijarProximo(x->ObtenerProximo());
		 else
			 inicio = x->ObtenerProximo();
		 if (x->ObtenerProximo() != NULL)
			 x->ObtenerProximo()->FijarPrevio(x->ObtenerPrevio);
		 delete x;
		 return;
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
template <class Z>
class Hashing {
	ListaDoble <Z> *T[m];
public:
	Hashing() {
		for (int i = 0; i < m; i++)
			T[i] = new ListaDoble<Z>;
	}
	int h(int k) {//metodo de la division
		int hash;
		hash = k % m;
		return hash;
	}
	void Radix128(string s, Nodo<Z> *x) {
		long long val;
		int hashr;
		for (string rit = s.rbegin(); rit != s.rend(); ++rit)
			val = val + *rit;
		hashr = h((int)val);
		InsertarRadix(hashr, x);

	}
	void InsertarRadix(int hash, Nodo<Z> *x) {
		T[hash]->InsertarNodo(x);
	}
	void Insertar(Nodo<Z> *x) {
		int hash;
		hash = h(x->ObtenerClave());
		T[hash]->InsertarNodo(x);
	}
	Nodo<Z>*Buscar(int k) {
		int hash;
		Nodo <Z> *x;
		hash = h(k);
		x=T[hash]->BuscarNodo(k);
		return x;
	}
	void Eliminar(Nodo <Z>*x) {
		int hash;
		hash = h(x->ObtenerClave());
		T[hash]->EliminarNodo(x);
	}
};
int main(){
	Nodo <int> *x;
	Hashing <int> tabla;
	bool valid;
	int opc;
	do {
		valid = false;
		cout << "Introduzca el numero que quiere insertar en el nodo" << endl;
		cin >> opc;
		cin.ignore();
		x = new  Nodo <int>;
		x->FijarClave(opc);
		tabla.Insertar(x);
		cout << "Quiere insertar otro nodo? 0 para salir" << endl;
		cin >> opc;
		cin.ignore();
		if (opc == 0)
			valid = true;
	} while (valid == false);
	cout << "Introduzcaq el entero que va  a buscar en la tabla" << endl;
	cin >> opc;
	cin.ignore();
	x = new Nodo <int>;
	x= tabla.Buscar(opc);
	cout << "Coincidencia encontrada:" << x->ObtenerClave() << endl;
}

