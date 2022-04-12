#include <iostream>
#include <string>


using namespace std;
const int max_element=15;


template<class T>
class Pila{
	T S[max_element];
	int tope;
	
public:
	Pila(){
		tope=-1;
	}
	
	void Push(T x){
		tope++;
		S[tope]=x;
	}
	T Pop(){
			if(PilaVacia()==true)
				cerr<<"la pila esta vacia"<<endl;
			tope--;
			return S[tope+1];
	}
	bool PilaVacia(){
		if(tope==-1)
			return true;
		else 
			return false;
			}
	bool PilaLLena(){
		if(tope==max_element)
			return true;
		else 
			return false;
	}
	int tamanioPila(){
		return tope + 1;
	}
	T cimaPila(){
		if(PilaVacia()==true)
			cerr<<"la pila esta vacia"<<endl;
		return S[tope];
	}
	
	void limpiarPila(){
		tope=-1;
	}
		
	T Cimapila(){
		return S[tope];
	}
};


int main(int argc, char *argv[]) {
	Pila<int> pila;
	int numero;
	
	
	cout<<"se creo una pila"<<endl;
	cout<<"ingrese 5 numeros distintos"<<endl;
	for(int i=0;i<5;i++){
		cout<<"ingrese numero"<<"chance: "<<i+1<<endl;
		cin>>numero;
		pila.Push(numero);
	}
	cout<<"probando pila Vacia"<<endl;
	if(pila.PilaVacia()){
		cout<<"pila llena"<<endl;
	}else{
		cout<<"la pila aun tiene espacio"<<endl;
	}
	cout<<"el tamano de la pila es de :"<<pila.tamanioPila()<<endl;
	
	cout<<"Hacemos pop y el elemento a salir es el: "<<pila.Pop()<<endl;
	
	cout<<"ahora en la cima de la pila esta: "<<pila.cimaPila()<<endl;
	
	cout<<"ahora limpiamos la pila "<<endl;
	pila.limpiarPila();
	
	if(pila.PilaVacia()){
		cout<<"la pila esta vacia"<<endl;
	}
	
	
	return 0;
}

