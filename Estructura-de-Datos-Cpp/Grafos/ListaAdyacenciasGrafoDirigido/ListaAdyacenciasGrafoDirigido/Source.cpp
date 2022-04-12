#include <string>
#include <iostream>
using namespace std;

class Arco {
	string nombreArco;
	string nombreVertice;
	Arco* proximoArco;
	int peso;
public:
	Arco() {
		proximoArco = NULL;
	}

	void setNombreArco(string s) {
		nombreArco = s;
	}
	string getNombreArco() {
		return nombreArco;
	}

	void setNombreVertice(string s) {
		nombreVertice = s;
	}
	string getNombreVertice() {
		return nombreVertice;
	}

	void setProximoArco(Arco *a) {
		proximoArco = a;
	}
	Arco * getProximoArco() {
		return proximoArco;
	}

	void setPeso(int p) {
		peso = p;
	}
	int getPeso() {
		return peso;
	}
};

class Vertice {
	string clave;
	Arco* proximoArco;
	Vertice* proximoVertice;
public:
	Vertice() {
		proximoArco = NULL;
		proximoVertice = NULL;
	}

	Vertice(string nv) {
		clave = nv;
		proximoArco = NULL;
		proximoVertice = NULL;
	}

	void setClave(string s) {
		clave = s;
	}
	string getClave() {
		return clave;
	}

	void setProximoArco(Arco *a) {
		proximoArco = a;
	}
	Arco* getProximoArco() {
		return proximoArco;
	}

	void setProximoVertice(Vertice* v) {
		proximoVertice = v;
	}
	Vertice* getProximoVertice() {
		return proximoVertice;
	}
};

class GrafoDirigido {
	Vertice *inicio;
public:
	GrafoDirigido() {
		inicio = NULL;
	}
	void AgregarVertice(Vertice *v) {
		v->setProximoVertice(inicio);
		inicio = v;
	}
	Vertice* BuscarVertice(string clave) {
		Vertice *x;
		x = inicio;
		while (x != NULL && x->getClave() != clave) {
			x = x->getProximoVertice();
		}
		return x;
	}
	void AgregarArco(Vertice *vs, Vertice *ve, string nombreArco) {
		Arco *arco = new Arco;
		arco->setNombreArco(nombreArco);
		arco->setNombreVertice(ve->getClave());
		arco->setProximoArco(vs->getProximoArco());
		vs->setProximoArco(arco);
	}
	void GradoDelVerticeDirigido() {
		string ver = " ";
		Vertice *vertice, *aux;
		vertice = inicio;
		Arco *arco;
		int cont = 0;
		while (vertice != NULL) {
			aux = inicio;
			cont = 0;
			while (aux != NULL) {
				arco = aux->getProximoArco();
				while (arco != NULL) {
					if ((vertice != aux && vertice->getClave() == arco->getNombreVertice()) || vertice == aux) {
						cont++;
					}
					arco = arco->getProximoArco();
				}
				aux = aux->getProximoVertice();
			}
			cout << "Grado del vertice " << vertice->getClave() << "=" << cont << endl;
			vertice = vertice->getProximoVertice();
		}
	}

	void GradoUno() {
		Vertice *vertice;
		vertice = inicio;
		Arco *arco;
		int cont = 0;
		while (vertice != NULL) {
			arco = vertice->getProximoArco();
			if (arco != NULL && arco->getProximoArco() == NULL) {
				cont++;
			}
			vertice = vertice->getProximoVertice();
		}
		cout << "La cantidad de vertices con grado igual a 1 es: " << cont << endl;
	}

	void MostrarGrafo() {
		Vertice *vertice = inicio;
		Arco *arco;
		while (vertice != NULL) {
			arco = vertice->getProximoArco();
			while (arco != NULL) {
				cout << "Vertice de salida: " << vertice->getClave() << endl;
				cout << "Vertice de entrada: " << arco->getNombreVertice() << endl;
				cout << "Arco entre ambos grafos: " << arco->getNombreArco() << endl << endl;
				arco = arco->getProximoArco();
			}
			vertice = vertice->getProximoVertice();
		}
	}

	void ArcosParalelos() {
		Vertice *vertice;
		vertice = inicio;
		Arco *arco;
		while (vertice != NULL) {
			arco = vertice->getProximoArco();
		}
	}
};

int main() {
	GrafoDirigido gd;
	Vertice *vertice;
	string clave, vs, ve, a;
	int opc;

	gd.AgregarVertice(new Vertice("V5"));
	gd.AgregarVertice(new Vertice("V4"));
	gd.AgregarVertice(new Vertice("V3"));
	gd.AgregarVertice(new Vertice("V2"));
	gd.AgregarVertice(new Vertice("V1"));

	gd.AgregarArco(gd.BuscarVertice("V1"), gd.BuscarVertice("V2"), "A1");
	gd.AgregarArco(gd.BuscarVertice("V1"), gd.BuscarVertice("V3"), "A2");
	gd.AgregarArco(gd.BuscarVertice("V2"), gd.BuscarVertice("V3"), "A3");
	gd.AgregarArco(gd.BuscarVertice("V3"), gd.BuscarVertice("V4"), "A4");
	gd.AgregarArco(gd.BuscarVertice("V4"), gd.BuscarVertice("V2"), "A5");

	do {
		cout << "1-Ingresar Vetice" << endl << "2-Ingresar arco" << endl << "3-verificar grado de vertices" << endl << "4-Grado uno" << endl << "5-Mostrar Grafo" << endl << "6-Salir" << endl;
		cin >> opc;
		system("cls");
		switch (opc) {
		case 1:
			vertice = new Vertice;
			cout << "ingrese nombre vertice: ";
			cin >> clave;
			vertice->setClave(clave);
			gd.AgregarVertice(vertice);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Ingrese vertice de salida: ";
			cin >> vs;
			cout << "Ingrese vertice de entrada: ";
			cin >> ve;
			cout << "Ingrese arco: ";
			cin >> a;
			gd.AgregarArco(gd.BuscarVertice(vs), gd.BuscarVertice(ve), a);
			system("pause");
			system("cls");
			break;
		case 3:
			gd.GradoDelVerticeDirigido();
			system("pause");
			system("cls");
			break;
		case 4:
			gd.GradoUno();
			system("pause");
			system("cls");
			break;
		case 5:
			gd.MostrarGrafo();
			system("pause");
			system("cls");
			break;
		case 6:
			break;
		default:
			cout << "Ingrese una opcion valida";
				}
	}while (opc != 6);
}