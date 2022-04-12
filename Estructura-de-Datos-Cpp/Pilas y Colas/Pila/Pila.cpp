// Pila.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
const int MaxElementos = 100;
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
};
int main(){
	int x, y;
	Pila stack;
	for (int i = 0; i <= 101; i++) {
		stack.Push(i);
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
