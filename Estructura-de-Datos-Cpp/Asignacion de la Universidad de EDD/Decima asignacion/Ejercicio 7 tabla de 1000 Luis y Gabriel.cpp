// Ejercicio 7 
// 
//
// Luis Agreda C.I 26.886.935
// Gabriel Trujillo C.I 25.244.508

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int m = 1000;


template <class T>
class Nodo {
	T clave;
	Nodo<T> *previo;
	Nodo<T> *proximo;
public:
	Nodo() {
		previo = proximo = NULL;
	}
	void FijarClave(T c) {
		clave = c;
	}
	T ObtenerClave() {
		return clave;
	}
	void FijarPrevio(Nodo <T>*x) {
		previo = x;
	}
	Nodo<T> *ObtenerPrevio() {
		return previo;
	}
	void FijarProximo(Nodo <T>*x) {
		proximo = x;
	}
	Nodo<T> *ObtenerProximo() {
		return proximo;
	}
};
template <class T>
class ListaSimple{
	Nodo<T> *inicio;
public:
	ListaSimple(){
		inicio=NULL;
	}	
	//este metodo es insertar normal
	void InsertarInicio(Nodo<T>* x){     
		x->FijarProximo(inicio);
		if (inicio != NULL)
			inicio->FijarPrevio(x);
		inicio = x;
		return;
	}

	int ContarElementos(){
		Nodo<T> *temp=inicio;
			int elementos=0;
			while(temp){
				temp=temp->ObtenerProximo();
				elementos++;
			}
		return elementos;
	}

	void buscar(T dato){
	Nodo<T> *temp =  inicio;
	short cont=0;//es para verificar que mensaje enviar
	while(temp){ //mientras temporal no sea NULL bueno
		if(temp->ObtenerClave()==dato){   // mientras no sea igual dato que buscamos nada salta sino imprime
			cout<<"se encontro el nodo y es:"<< temp->ObtenerClave()<<endl;
				cont++;
		}
		temp = temp->ObtenerProximo(); //aqui avanzamos en la lista 
	}
		if(cont==0)
			cout<<"no se encontro el dato a buscar"<<endl; 
	}

	void Imprimir(){
		Nodo<T> *temp=inicio;
		while(temp){
			if(temp!=NULL)
				cout<<temp->ObtenerClave()<<", ";
				temp=temp->ObtenerProximo();
		}
		cout<<endl;
	}
	~ListaSimple(){
	Nodo<T> *y;
	while(inicio!=NULL){
		y=inicio;
		inicio=inicio->ObtenerProximo();
		delete y;
	}
	}
};


template <class H>
class Hashing {
	ListaSimple <H> *T[m];
public:
	Hashing() {
		for (int i = 0; i < m; i++)
			T[i] = new ListaSimple<H>;
	}
	int h(int k) {//metodo de la division
		int hash;
		hash = k % m;
		return hash;
	}
	void Insertar(Nodo<H> *x) {
		int hash;
		hash = h(x->ObtenerClave());
		T[hash]->InsertarInicio(x);
	}
	void ContadorMayor(){
		int mayor=0, indice;
		for(int i = 0;i<m;i++){
			if(mayor < T[i]->ContarElementos()){
				mayor = T[i]->ContarElementos();
				indice = i;
			}
		}
		cout<<"la mayor lista de elemtos es la posicion: "<<indice<<"con : "<<mayor<<"elementos"<<endl;
		T[indice]->Imprimir();
	}
	Nodo<H>*Buscar(int k) {
		int hash;
		Nodo <H> *x;
		hash = h(k);
		x=T[hash]->BuscarNodo(k);
		return x;
	}
};
int main(int argc, char *argv[]) {
	Nodo <int> *a;
	Hashing <int> tabla;
	int num;
	cout<<"agregando 1000 elementos aleatorios a la lista"<<endl;
	for(int i=0; i < m ; i++){
		num=rand();
		a = new Nodo <int>;
		a->FijarClave(num);
		tabla.Insertar(a);
	}
	cout<<"la lista mas larga es: "<<endl;
	tabla.ContadorMayor();
	
	return 0;
}

