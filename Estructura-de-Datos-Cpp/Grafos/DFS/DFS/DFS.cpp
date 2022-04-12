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
	string color;
	Vertice *pi;
	int d, f;
public:
	Vertice() {
		proximoArco = NULL;
		proximoVertice = NULL;
	}

	Vertice(string nv) {
		clave = nv;
		proximoArco = NULL;
		proximoVertice = NULL;
		pi = NULL;
		color=" ";
		
		d = 0;
		f = 0;
	}
	void setPi(Vertice *p) {
		pi = p;
	}
	Vertice *getPi() {
		return pi;
	}
	void setColor(string s) {
		color = s;
	}
	string getColor() {
		return color;
	}
	void setD(int t) {
		d = t;
	}
	int getD() {
		return d;
	}
	void setF(int t) {
		f = t;
	}
	int getF() {
		return f;
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
	void setInicio(Vertice*v) {
		inicio = v;
	}
	Vertice* getInicio() {
		return inicio;
	}
};
class DFS {
	int tiempo;
	bool grafoConexo;
public:
	DFS(){
		tiempo = 0;
		grafoConexo = 1;
	}
	void DFSproceso(GrafoDirigido &G) {
		Vertice *vertice = G.getInicio();
		int tiempo, contador = 0;
		for (; vertice != NULL; vertice = vertice->getProximoVertice()) {
			vertice->setColor("blanco");
			vertice->setPi(NULL);
		}
		tiempo = 0;
		for (vertice = G.getInicio(); vertice != NULL; vertice->getProximoVertice()) {
			if (vertice->getColor() == "blanco") {
				Visitar(G,vertice);
				contador++;
			}
		}
		if (contador > 1)
			grafoConexo = 0;
		return;
	}
	void Visitar(GrafoDirigido &G,Vertice *v) {
		Arco *a = NULL;
		Vertice *vaux = NULL;
		v->setColor("gris");
		tiempo++;
		v->setD(tiempo);
		for (a = v->getProximoArco(); a != NULL; a = a->getProximoArco()) {
			vaux = G.BuscarVertice(a->getNombreVertice());
			if (vaux->getColor() == "blanco") {
				vaux->setPi(v);
				Visitar(G, vaux);
			}
		}
		v->setColor("negro");
		tiempo++;
		v->setD(tiempo);
		return;
	}
};