
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MaxElementos = 25;
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
		if (ColaLlena()==true) {
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
int main(){
	Cola queue;
	int n, k;
	n = 5;
	queue.Push(n);
	k = queue.Pop();
	cout << k;
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
