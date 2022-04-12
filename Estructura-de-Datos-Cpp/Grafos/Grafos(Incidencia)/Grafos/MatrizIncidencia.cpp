#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const short MAX_V = 100;
const short MAX_A = 100;
class GrafoMatrizDeIncidencia {//primero se lee el numero de filas y luego columnas
	short Ac[MAX_V][MAX_A];
	int nVertices, mArcos;
public:
	GrafoMatrizDeIncidencia() {
		memset(Ac, 0, 10000);
		nVertices = 0;
		mArcos = 0;
	}
	void AgregarArco(short vs, short ve) {
		if (nVertices <=1) {
			cerr << "No existen vertices para agregar arcos";
			return;
		}
		if ((vs > nVertices&& ve > nVertices) ||(vs==ve)) {
			cerr << "Alguno de los vertices no existe o intenta introducir un lazo" << endl;
			return;
		}
		mArcos++;
		for (int i = 0; i < nVertices;i++) {
			if (vs == i) {
				Ac[i][mArcos] = 1;
			}
			if (ve == i) {
				Ac[i][mArcos] = -1;
			}
		}
		cout << "Arco agregado correctamente" << endl;
		return;
	}
	void AgregarVertice() {
		nVertices=nVertices+1;
		cout << "Vertice agregado correctamente" << endl;
		return;
	}
	void EliminarArco(short a) {
		if (a > mArcos && a<0) {
			cerr << "el arco que intentas eliminar no existe" << endl;
			return;
		}
		
		for (int i = 0; i < nVertices; i++) {
			for (int k = a; k < mArcos - 1; k++) {
					Ac[i][k] = Ac[i][k + 1];
			}
		}
			mArcos--;
		cout << "El arco ha sido eliminado correctamente" << endl;
		return;
	}
	void Eliminarvertice(short v) {
		if (v > nVertices && v<0) {
			cerr << "El vertice que intentas eliminar no existe" << endl;
		}
		for (short i = 0; i < mArcos; i++) {
			if (Ac[v][i] != 0) {
				EliminarArco(i);
			}
		}
		for (int i = 0; i < mArcos; i++) {
			for (int j = v; j < nVertices - 1; j++) {
					Ac[j][i] = Ac[j + 1][i];
			}
		}
		nVertices--;
		cout << "El vertice (Y los arcos que lo involucraban) han sido eliminados correctamente" << endl;
	}
	int ComprobarVerticesFuente() {
		int j, contador=0;
		for (int i = 0; i < nVertices; i++) {
			for (j = 0; j < mArcos; j++) {
				if (Ac[i][j] == -1) {
					break;
				}
			}
			if (j == mArcos - 1)
				contador++;
		}
		return contador;
	}
	int ComprobarVerticesSumidero() {
		int j, contador = 0;
		for (int i = 0; i < nVertices; i++) {
			for (j = 0; j < mArcos; j++) {
				if (Ac[i][j] ==1) {
					break;
				}
			}
			if (j == mArcos - 1)
				contador++;
		}
		return contador;
	}
	int ComprobarVerticesAislados() {
		int j, contador = 0;
		for (int i = 0; i < nVertices; i++) {
			for (j = 0; j < mArcos; j++) {
				if (Ac[i][j] != 0) {
					break;
				}
			}
			if (j == mArcos - 1)
				contador++;
		}
		return contador;	
	}
	bool GradoTres() {
		int contador = 0;
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j <= mArcos; j++) {
				if (Ac[i][j] != 0) {
					contador++;
				}
			}
			if (contador != 3) {
				return 0;
			}
			contador = 0;
		}
		return 1;
	}

};
void main() {
	int opc, vert;
	GrafoMatrizDeIncidencia gm;
	short ventrada, vsalida, v;
	do {
		cout << "introduzca una opcion" << endl << "1. Agregar Vertice" << endl << "2.Agregar Arco" << endl << "3.Eliminar Vertice" << endl << "4. Eliminar Arco" << endl << "5.Comprobar cantidad de vertices fuentes" << endl<<"6.Comprobar cantidad de vertices Sumideros" << endl <<"8.Salir"<<endl<< endl;
		cin >> opc;
		cin.ignore();
		switch (opc) {
			case 1:
				system("CLS");
				gm.AgregarVertice();
				break;
			case 2:
				cout << "Indique desde cual vertice sale el arco" << endl;
				cin >> vsalida;
				cin.ignore();
				cout << "Indique a que vertice se dirije el arco" << endl;
				cin >> ventrada;
				cin.ignore();
				system("CLS");
				gm.AgregarArco(vsalida, ventrada);
				break;
			case 3:
				cout << "Indique cual es el subindice del vertice que quiere eliminar" << endl;
				cin >> v;
				cin.ignore();
				system("CLS");
				gm.Eliminarvertice(v);
				break;
			case 4:
				cout << "Indique cual es el subindice del Arco que quiere eliminar" << endl;
				cin >> v;
				cin.ignore();
				system("CLS");
				gm.Eliminarvertice(v);
				break;
			case 5:
				vert = gm.ComprobarVerticesFuente();
				system("CLS");
				cout << "Existen " << vert << "Vertices fuente" << endl;
				break;
			case 6:
				vert = gm.ComprobarVerticesSumidero();
				system("CLS");
				cout << "Existen" << vert << "Vertices sumidero " << endl;
				break;
			case 7:
				vert = gm.ComprobarVerticesAislados();
				system("CLS");
				cout << "Existen" << vert << "Vertices Aislados " << endl;
				break;
			case 8:
				break;
			case 9:
				system("CLS");
				if (gm.GradoTres()) {
					cout << "todos los vertices del grafo tienen grado igual a 3" << endl;
				}
				else {
					cout << "Algunos vertices del grafo no tienen grado igual a 3 " << endl;
				}
				break;
			default:
				system("CLS");
				cout << "Introduzca una opcion correcta xfa" << endl;
				break;
		}
	} while (opc != 8);
}