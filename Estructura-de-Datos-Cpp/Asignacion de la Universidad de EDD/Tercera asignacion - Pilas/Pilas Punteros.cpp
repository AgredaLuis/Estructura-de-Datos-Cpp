#include <iostream>
using namespace std;


template <class T>
class Pila{
	class NodoPila{
	public:
		NodoPila* siguiente;
		T elemento;
		NodoPila(T x)
		{
			elemento = x;
			siguiente = NULL;
		}
	};
	NodoPila* tope;
public:
	Pila(){
		tope = NULL;
	}
	void Push(T elemento){
		NodoPila* nuevo;
		nuevo = new NodoPila(elemento);
		nuevo -> siguiente = tope;
		tope = nuevo;
	}
	T Pop(){
			if (pilaVacia())
				cout<< "Pila vacía, no se puede extraer.";
			T aux = tope -> elemento;
			tope = tope -> siguiente;
			return aux;
	}
	T topePila(){
		if (pilaVacia())
			cout<< "Pila vacía";
		return tope -> elemento;
	}
	bool pilaVacia(){
		return tope == NULL;
	}
	void limpiarPila(){
		NodoPila* n;
		while(!pilaVacia()){
			n = tope;
			tope = tope -> siguiente;
			delete n;
		}
	}
	
	//Destructor que automaticamente elimina los nodos que aun andan en la memoria
	~Pila(){
		limpiarPila();
	}
};


int main(int argc, char *argv[]) {
	Pila<int> pila1;
	int numero;
	
	for(int i=0;i<5;i++){
	cout<<"inserte un numero"<<endl;
	cin>>numero;
	pila1.Push(numero);
	}
	
	cout<<"sacando el ultimo elemento de la pila"<<endl;
	cout<<pila1.Pop()<<endl;
	
	cout<<"ahora la cima de la pila es :"<<endl;
	cout<<pila1.topePila()<<endl;
	
	return 0;
}

