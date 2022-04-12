#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const short MAX_V = 100;
class GrafoMatrizDeIncidencia {//[filas][columnas]
	short M[MAX_V][MAX_V];
	int nVertices;
public:
	GrafoMatrizDeIncidencia() {
		memset(M, 0, MAX_V);
		nVertices = 0;
	}
	void AgregarVertice() {
		nVertices++;
		cout << "vertice Agregado correctamente" << endl;
	}
	void AgregarArco(short vsalida, short ventrada) {
		if (M[vsalida][ventrada] == 1) {
			cerr << "El arco que intenta ingresar ya existe, no se pueden ingresar arcos paralelos en esta clases de grafos" << endl;
			return;
		}
		else {
			M[vsalida][ventrada] = 1;
			cerr << "Arco ingresado correctamente" << endl;
			return;
		}

	}
	void EliminarVertice(short v) {
		if (v<0 || v>nVertices) {
			cerr << "El vertice que intenta eliminar no existe" << endl;
			return;
		}
		//elimina la fila
		for (short i = 0; i < nVertices-1; i++) {
			M[i][v] = M[i][v + 1];
		}
		//elimina la columa
		for (short j = 0; j < nVertices - 1; j++) {
			M[v][j] = M[v + 1][j];
		}
		nVertices--;
		cout << "El vertice fue eliminado correctamente" << endl;
		return;
	}
	void EliminarArco(short vsalida, short ventrada) {
		if (M[vsalida][ventrada] == 0) {
			cerr << "El arco que intenta eliminar no existe" << endl;
			return;
		}
		else {
			M[vsalida][ventrada] = 0;
			cerr << "Arco eliminado correctamente" << endl;
			return;
		}
	}
};