// Voltear Pila.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MaxElementos = 100;
class Cola {
	int primero;
	int ultimo;
	int Q[MaxElementos];
public:
	Cola() {
		primero = 0;
		ultimo = 0;
	}
	void Push(int n) {
		if (ColaLlena() == true) {
			cerr << "La cola esta llena, por favor saque numeros." << endl;
			return;
		}
		Q[ultimo] = n;
		ultimo++;
		return;
	}
	int Pop() {
		if (ColaVacia() == true) {
			cerr << "La cola esta vacia, por favor introduzca numeros, o datos" << endl;
			return -32000;
		}
		primero++;
		return Q[primero - 1];
	}
	bool ColaLlena() {
		if ((ultimo + 1 == MaxElementos) || (primero == ultimo + 1)) {
			return true;
		}
		return false;
	}
	bool ColaVacia() {
		if (primero == ultimo) {
			return true;
		}
		return false;
	}
};
class Pila {
	int s[MaxElementos];
	int tope;
public:
	Pila() {
		tope = -1;
	}
	int Pop() {
		if (PilaVacia() == true) {
			cerr << "Error, Underflow en la pila" << endl;
			return -32000;
		}
		tope--;
		return s[tope + 1];
	}
	void Push(int x) {
		if (PilaLlena() == true) {
			cerr << "Error, Overflow en la pila" << endl;
			return;
		}
		tope++;
		s[tope] = x;
		return;
	}
	bool PilaLlena() {
		if (tope >= MaxElementos) {
			return true;
		}
		return false;
	}
	bool PilaVacia() {
		if (tope == -1) {
			return true;
		}
		return false;
	}
	int getTope() {
		return tope;
	}
};
int main(){
	int numero,i, aux;
	Cola queue;
	Pila stack;
	cout << "Introduzca la cantidad de numeros que va a colocar en la pila" << endl;
	cin >> numero;
	cout << "Los numeros deberan estar en este orden, al meterlos en una pila" << endl;
	for (i = 0; i < numero; i++) {
		cout << "Numero introducido=" << i << endl;
		stack.Push(i);
	}
	cout << stack.getTope() << endl;
	for (i = 0; i < numero; i++) {
		aux = stack.Pop();
		queue.Push(aux);
	}
	cout << stack.getTope() << endl;
	for (i = 0; i < numero; i++) {
		aux = queue.Pop();
		cout << "numero introducido en la pila al reves:" << aux << endl;;
		stack.Push(aux);
	}
	for (i = 0; i < numero; i++) {
		aux = stack.Pop();
		cout << "Doble check " << aux << endl;

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
