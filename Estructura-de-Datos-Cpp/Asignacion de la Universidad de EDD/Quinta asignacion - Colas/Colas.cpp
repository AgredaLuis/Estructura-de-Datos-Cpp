#include <iostream>
using namespace std;
const int max_element=10;


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
			primero = 0;
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
	Cola<int> cola1;
	int numero;
	
	for(int i =0 ; i<6;i++){
		cout<<"porfavor ingrese un numero a la cola"<<endl;
		cin>>numero;
		cola1.EnQueue(numero);
	}
	
	
	cout<<"ahora sacando elemento de la cola: "<<endl;
	for(int i =0 ; i<6;i++){
		
		cout<<cola1.DeQueue()<<endl;
	}

	return 0;
}

