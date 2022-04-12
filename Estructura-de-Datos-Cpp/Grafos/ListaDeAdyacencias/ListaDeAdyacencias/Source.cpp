#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Vertice {
	string clave;
	Vertice *proximoVertice;
	Arco *proximoArco;
public:
	Vertice() {
		proximoVertice = NULL;
		proximoArco = NULL;
	}
	void FijarClave(string s) {
		clave = s;
	}
	string ObtenerClave() {
		return clave;
	}
	void FijarProximoVertice(Vertice *v) {
		proximoVertice = v;
	}
	Vertice *ObtenerProximoVertice() {
		return proximoVertice;
	}
	void FijarProximoArco(Arco *a) {
		proximoArco = a;
	}
	Arco *ObtenerProximoArco() {
		return proximoArco;
	}
};
class Arco{
	string nombreArco, nombreVertice;
	int peso;
	Arco *proximoArco;
public:
	Arco() {
		proximoArco = NULL;
	}
	void FijarNombreArco(string s) {
		nombreArco = s;
	}
	string ObtenerNombreArco() {
		return nombreArco;
	}
	void FijarNombreVertice(string s) {
		nombreVertice = s;
	}
	string ObtenerNombreVertice() {
		return nombreVertice;
	}
	void FijarProximoArco(Arco *a) {
		proximoArco = a;
	}
	Arco *ObtenerProximoArco() {
		return proximoArco;
	}
	void FijarPeso(int p) {
		peso = p;
	}
	int ObtenerPeso() {
		return peso;
	}
};
class Grafo {
	Vertice *inicio;
public:
	Grafo() {
		inicio = NULL;
	}
	void AgregarVertice(Vertice*v) {
		v->FijarProximoVertice(inicio);
		inicio = v;
	}
	Vertice *BuscarVertice(string clave) {
		Vertice *v = inicio;
		while (v != NULL && v->ObtenerClave()!=clave) {
			v = v->ObtenerProximoVertice();
		}
		return v;
	}
	void AgregarArco(Vertice *vsalida, Vertice *ventrada, string NombreArco, int Peso) {
		Arco *arco = new Arco;
		arco->FijarNombreArco(NombreArco);
		arco->FijarNombreVertice(ventrada->ObtenerClave());
		arco->FijarProximoArco(vsalida->ObtenerProximoArco());
		vsalida->FijarProximoArco(arco);
		arco->FijarPeso(Peso);
	}
	int CantidadArcosParalelos() {
		Vertice *x = inicio;
		Arco *a = NULL;
		Arco *acomparar = NULL;
		int contAP = 0;
		while (x != NULL) {
			a = x->ObtenerProximoArco();
			while (a != NULL) {
				acomparar = a->ObtenerProximoArco();
				while (acomparar != NULL) {
					if (a->ObtenerNombreVertice() == acomparar->ObtenerNombreVertice())
						contAP++;
					acomparar = acomparar->ObtenerProximoArco();
				}
				a = a->ObtenerProximoArco();
			}
			x = x->ObtenerProximoVertice();
		}
		return contAP;
	}
	int VerticesGradoUno() {
		Vertice *x = inicio;
		Arco *a = NULL;
		int contGU=0;
		while (x != NULL) {
			a = x->ObtenerProximoArco();
			if (a->ObtenerProximoArco() == NULL) {
				contGU++;
			}
		}
		return contGU;
	}
	bool GrafoRegularNoDirigido() {
		Vertice *x = inicio;
		Arco *a = NULL;
		int contador = 0, contadorcomp = 0;
		while (x != NULL) {
			a = x->ObtenerProximoArco();
			while (a != NULL) {
				a = a->ObtenerProximoArco();
					contadorcomp++;
			}
			if (contador == 0) {
				contador = contadorcomp;
			}
			if (contadorcomp != contador) {
				return false;
			}
			contadorcomp = 0;
			x->ObtenerProximoVertice();
		}
		return true;
	}
	bool ArcoParaleloVerticeAislado() { //No dirigido
		Vertice *x = inicio;
		Arco*a = NULL;
		Arco *acomparar = NULL;
		string vert;
		int contadorParalelo = 0, contadorAislado = 0;
		while (x != NULL) {
			a = x->ObtenerProximoArco();
			if (a == NULL) {
				contadorAislado++;
			}
			else {
				while(a!=NULL){
					vert = a->ObtenerNombreVertice();
					acomparar = a->ObtenerProximoArco();
					while (acomparar != NULL) {
						if (vert == acomparar->ObtenerNombreVertice()) {
							contadorParalelo++;
						}
						acomparar = acomparar->ObtenerProximoArco();
					}
					a = a->ObtenerProximoArco();
				}
			}
			x = x->ObtenerProximoVertice();
		}
		if (contadorAislado == contadorParalelo) {
			return true;
		}
		else {
			return false;
		}
	}
	bool GrafoCompleto() {
		Vertice *v = inicio;
		Arco *a = NULL;
		Arco *acomparar = NULL;
		string vert;
		int contadorArcos = 0, contadorVertices = 1;
		while (v != NULL) {
			a = v->ObtenerProximoArco();
			while (a != NULL) {
				contadorArcos++;
				vert = a->ObtenerNombreVertice();
				acomparar = a->ObtenerProximoArco();
				while (acomparar != NULL) {
					if (vert == acomparar->ObtenerNombreVertice() || vert == v->ObtenerClave()) {
						return false;
					}

					acomparar = acomparar->ObtenerProximoArco();
				}
				a = a->ObtenerProximoArco();
			}
			contadorVertices++;
			v = v->ObtenerProximoVertice();
		}
		if (contadorArcos == ((contadorVertices*(contadorVertices - 1)) / 2)) {
			return true;
		}
		else {
			return false;
		}

	}
};