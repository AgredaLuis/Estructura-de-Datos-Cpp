// ContarPilaCola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int Max_Elementos = 25;
template <class T>
class Pila {
	int tope;
	T S[Max_Elementos];
public:
	Pila() {
		tope = -1;
	}
	void Push(T x) {
		if (PilaLlena() == true) {
			cerr << "ETA PILA TA LLENA Q CREES TU" << endl;
			return;
		}
		tope++;
		S[tope] = x;
		return;
	}
	T Pop() {
		T dato;
		if (PilaVacia() == true) {
			cerr << "ETA PILA TA VACIA Q CREES TU" << endl;
			return -2;
		}
		dato = S[tope];
		tope--;
		return dato;
	}
	bool PilaLlena() {
		if (tope == Max_Elementos - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool PilaVacia() {
		if (tope == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};
template <class T>
class Cola {
	int primero, ultimo;
	T Q[Max_Elementos];
public:
	Cola() {
		primero = ultimo = 0;
	}
	void EnQueue(T x) {
		if (ColaLlena() == true) {
			cerr << "ESTA COLA ESTA LLENA NO HAY PRODUCTO" << endl;
			return;
		}
		if (ultimo == Max_Elementos - 1) {
			Q[ultimo] = x;
			ultimo = 0;
			return;
		}
		Q[ultimo] = x;
		ultimo++;
		return;
	}
	T DeQueue() {
		T dato;
		if (ColaVacia() == true) {
			cerr << "ESTA COLA TA VACIA NO HAY PRODUCTO" << endl;
			return -1;
		}
		dato = Q[primero];
		if (primero == Max_Elementos - 1) {
			primero = 0;
		}
		else {
			primero++;
		}
		return dato;
	}
	bool ColaLlena() {
		if ((primero == ultimo + 1) || ((ultimo == Max_Elementos - 1) && (primero == 0))) {
			return true;
		}
		else {
			return false;
		}
	}
	bool ColaVacia() {
		if (primero == ultimo) {
			return true;
		}
		else {
			return false;
		}
	}
	int GetUltimo() {
		return ultimo;
	}
};

int main(){
	Cola <int> queue, queueAux;
	Pila <int> stack, stackAux;
	int contador=0, n,i;
	bool valid;
	cout << "introduzca el numero de elementos que quiere añadir a la estructura de datos" << endl;
	cin >> n;
	/*EJERCICIO EN COLAS.
	for ( i = 0; i < n; i++)
		queue.EnQueue(i);
	for (i = 0; i < queue.GetUltimo(); i++) {
		n = queue.DeQueue();
		queueAux.EnQueue(n);
		contador++;
	}
	valid = queueAux.ColaVacia();
	while (!valid) {
		n = queueAux.DeQueue();
		queue.EnQueue(n);
		valid = queueAux.ColaVacia();
	}
	cout << "La cola tiene " << contador << " Elementos" << endl;
	valid = queue.ColaVacia();
	while (!valid) {
		n = queue.DeQueue();
		cout << "Elemento:" << n << endl;
		valid = queue.ColaVacia();
	}*/
	

	//EJERCICIO EN PILAS
	for (i = 0; i < n; i++) {
		stack.Push(i);
	}
	valid = stack.PilaVacia();
	while (!valid) {
		n = stack.Pop();
		stackAux.Push(n);
		contador++;
		valid = stack.PilaVacia();
	}
	cout << "La Pila tiene " << contador << " Elementos" << endl;
	valid = stackAux.PilaVacia();
	while (!valid) {
		n = stackAux.Pop();
		stack.Push(n);
		valid = stackAux.PilaVacia();
	}
	valid = stack.PilaVacia();
	while (!valid) {
		n = stack.Pop();
		cout << "Elemento: " << n << endl;
		valid = stack.PilaVacia();
	}

  
}

