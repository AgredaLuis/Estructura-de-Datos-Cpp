// SacarElementoNPilaCola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "SacarElementoNPilaCola.h"
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
	Pila <int> stack, stackAux;
	Cola <int> queue, queueAux;
	int n, contador = 0, elemento,i;
	bool valid;
	cout << "introduzca la cantidad de elementos que quiere que existan en la cola" << endl;
	cin >> n;
	cout << " Introduzca el elemento que quiere sacar de la lista, va a ser remplazado por un -1" << endl;
	cin >> elemento;
	/*for (i = 0; i < n; i++) {
		queue.EnQueue(i);
	}
	valid = queue.ColaVacia();
	while (!valid) {
		n = queue.DeQueue();
		if (contador==elemento-1){
			queueAux.EnQueue(-1);
		}
		else {
			queueAux.EnQueue(n);
		}
		contador++;
		valid = queue.ColaVacia();
	}
	valid = queueAux.ColaVacia();
	while (!valid) {
		n = queueAux.DeQueue();
		queue.EnQueue(n);
		valid = queueAux.ColaVacia();
	}
	//comprobar
	valid = queue.ColaVacia();
	while (!valid) {
		n = queue.DeQueue();
		cout << "Elemento de la cola " << n << endl;
		valid = queue.ColaVacia();
	}*/
	for (i = 0; i < n; i++)
		stack.Push(i);
	valid = stack.PilaVacia();
	while (!valid) {
		n = stack.Pop();
		if (contador == elemento - 1){
			stackAux.Push(-1);
		}
		else{
			stackAux.Push(n);
		}
		contador++;
		valid = stack.PilaVacia();
	}
	valid = stackAux.PilaVacia();
	while (!valid) {
		n = stackAux.Pop();
		stack.Push(n);
		valid = stackAux.PilaVacia();
	}
	valid = stack.PilaVacia();
	while (!valid) {
		n = stack.Pop();
		cout << "Elemento de la pila " << n << endl;
		valid = stack.PilaVacia();
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
