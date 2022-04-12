#include <iostream>
#include <string>
using namespace std;
const int max_element=15;

//pila de las asignaciones pasadas 
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
};


template<class T>
class Cola{
	T Q[max_element];
	int primero,ultimo;
	
public:
	Cola(){
		primero=ultimo=0;
	}
	void EnQueue(T x){
		Q[ultimo]=x;
		if(ultimo==(max_element-1))
			ultimo=0;
		else 
			ultimo++;
	}
	T DeQueue(){
		T x = Q[primero];
		if(primero==(max_element-1))
			primero =0;
		else
			primero++;
		return x;
	}
			
	bool ColaVacia(){
		if(primero==ultimo)
			return true;
		return false;
		}
	bool Colallena(){
	return(primero=ultimo+1);
	}
};


int main(int argc, char *argv[]) {
	Pila<char> pila1;
	Cola<char> cola1;
	string elemento;
	bool capicua = true;
	

	cout<<"Porfavor introduzca un elemento"<<endl;
	cin>>elemento;
	
	for(char c : elemento){
		cola1.EnQueue(c);
		pila1.Push(c);
	}
	
	for(int i=0;i<elemento.size();i++){
		if(cola1.DeQueue()!=pila1.Pop()){
			capicua = false;
		}
	}
	
	if(capicua == true){
		cout<<"la cadena introducida es capicua"<<endl;
	}else if (capicua == false)
	   cout<<"la cadena introducida no es capicua"<<endl;

	return 0;
}

