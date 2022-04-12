#include <iostream>
#include <string>
using namespace std;


template<class T>
class Nodo {
	Nodo<T> *previo;
	Nodo<T> *proximo;
	T clave;
public:
	Nodo() {
		previo = proximo = NULL;
	}
	void setPrevio(Nodo<T> *x) {
		previo = x;
	}
	Nodo<T> *getPrevio() {
		return previo;
	}
	void setProximo(Nodo<T> *x) {
		proximo = x;
	}
	Nodo<T> *getProximo() {
		return proximo;
	}
	void setClave(T x) {
		clave = x;
	}
	T getClave() {
		return clave;
	}
};

template<class T>
class ListaDobleCircular {
	Nodo<T> *s;
	int num=0;

public:
	ListaDobleCircular() {
		s = new Nodo<T>;
		s->setProximo(s);
		s->setPrevio(s);
	}

	void Insertar(Nodo<T> *x) {
		x->setProximo(s->getProximo());
		s->getProximo()->setPrevio(x);
		s->setProximo(x);
		x->setPrevio(s);
		num++;
		
	}
	void Mostrar() {
		Nodo<T> *x = s->getProximo();
		while (x != s) {
			cout << x->getClave();
			x = x->getProximo();
		}
	}
	void sumar(ListaDobleCircular<int> &lc1 , ListaDobleCircular<int> &lc2){
		ListaDobleCircular<int> L1=lc1 , L2=lc2 , L3;
		Nodo<int> *nodo1 , *nodo2, *node;
		int suma,menor,i;
		
		if(L1.num-L2.num<0){
			menor=L1.num;
		}else {
			menor = L2.num;
		}
		
		
		nodo1=L1.s->getProximo();
		nodo2=L2.s->getProximo();
		
		int lleva =0;
		
		for(i=1;i <=menor;i++){
			node = new Nodo<int>;
			suma= nodo1->getClave() + nodo2->getClave() + lleva;
			if(suma>=10){
				suma = suma%10;
				node->setClave(suma);
				L3.Insertar(node);
				lleva=1;
			}else{
				node->setClave(suma);
				L3.Insertar(node);
				lleva=0;
			}
			nodo1 = nodo1->getProximo();
			nodo2 = nodo2->getProximo();
		}
		
		if((L1.num-L2.num)>0)
		{
			for(i=1;i<=(L1.num-L2.num);i++)
			{
				node = new Nodo<int>;
				suma = nodo1->getClave() + lleva;
					if(suma>=10)
					{
						suma = suma%10;
						node->setClave(suma);
						L3.Insertar(node);
						lleva=1;
					}else{
						node->setClave(suma);
						L3.Insertar(node);
						lleva=0;
					}
				nodo1 = nodo1->getProximo();
			}
		}
		if((L2.num-L1.num)>0)
		{
			for(i=1;i<=(L2.num-L1.num);i++)
			{
				node = new Nodo<int>;
				suma = nodo2->getClave() + lleva;
				if(suma>=10)
				{
					suma = suma%10;
					node->setClave(suma);
					L3.Insertar(node);
					lleva=1;
				}else{
					node->setClave(suma);
					L3.Insertar(node);
					lleva=0;
				}
				nodo2 = nodo2->getProximo();
			}
		}
		if(lleva==1){
			node = new Nodo<int>;
			node->setClave(lleva);
			L3.Insertar(node);
		}
		
		L3.Mostrar();
		cout<<endl;
	}
		
	~ListaDobleCircular() {
		Nodo <T> *y = s->getProximo();
		Nodo<T> *borrar;
		while (y != s) {
			borrar = y;
			y = y->getProximo();
			delete borrar;
		}
		delete s;
	}
};




int main(int argc, char *argv[]) {
	system("color B");
	int op,veamos;
	string numeros;
	Nodo<int> *node;
	ListaDobleCircular<int> lc1;
	ListaDobleCircular<int> lc2;
	
	cout << "Bienvenido a la calculadora extraDigitos" << endl;
	cout << "******" << endl;
	do {
		do {
			cout << "Ingrese una opcion: \n 1) Añadir elemento a la primera lista, \n 2) Agregar valor a la segunda lista, \n 3) Sumar las listas" << endl;
			cin >> op;
		} while (op < 1 || op>4);
		
		switch (op) {
		case 1:
			cout << "Ingresa el valor a ingresar en la lista"<<endl;
			cin>>numeros;
	
			for(char c : numeros){
				node = new Nodo<int>;
				veamos = c - '0';
				node->setClave(veamos);
				lc1.Insertar(node);
			}
			cout << "Agregado Correctamente!" << endl;
			break;
		case 2:
			cout << "Ingrese el valor a ingresar de la segunda lista" << endl;
			cin >> numeros;
			for(char c : numeros){
				node = new Nodo<int>;
				veamos = c - '0';
				node->setClave(veamos);
				lc2.Insertar(node);
			}
			cout << "Agregado Correctamente!" << endl;
			break;
		case 3:
			lc1.sumar(lc1,lc2);
			cout<<endl;
			cout<<"gracias por usar nuestra calculadora"<<endl;
			break;
		}
	} while (op != 3);
	system("pause");
	return 0;
}


