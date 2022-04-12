#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
/*pila de la asignacion anterior*/
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
		//sencillo siempre sera mejor xD
	void suma(){
			int a = topePila(); Pop();
			int b = topePila(); Pop();
			Push(a+b);
		}
	void resta(){
			int a = topePila(); Pop();
			int b = topePila(); Pop();
			Push(b-a);
		}
	void multiplica(){
			int a = topePila(); Pop();
			int b = topePila(); Pop();
			Push(a*b);
		}
	void divide(){
			int a = topePila(); Pop();
			int b = topePila(); Pop();
			Push(b/a);
		}
	void potencia(){
			int a = topePila(); Pop();
			int b = topePila(); Pop();
			Push(pow(b, a));
		}
//Destructor que automaticamente elimina los nodos que aun andan en la memoria
	~Pila(){
	limpiarPila();
	}
};

int precedence(char c){ //ternario para saber el operador mas impotante
	return (c == '+' || c == '-') ? 1 :(c == '*' || c == '/') ? 2 :(c == '^')? 3 : 0;//condicional
}
bool isOperator(char c){ // para saber si es operador o no
		return precedence(c) != 0;
	}
class Postfijo {
public:
	Postfijo() = default;
	
string infijoAPostfijo(string cadena){
	string postfijo;
	Pila<char> operadores;
	char operador;
	
	for(char c : cadena){
		if(isOperator(c)){
			while( !operadores.pilaVacia() && (operador = operadores.topePila()) != '(' && precedence(c) <= precedence(operador)){// si parentesis ( no es ta en la cima , mete todo
				postfijo += operador;
				operadores.Pop();
			}
			operadores.Push(c);
		}else if(c == '('){
			operadores.Push(c);
		}else if(c == ')'){
			while((operador = operadores.topePila()) != '('){
				postfijo+=operador;
				operadores.Pop();
			}
			operadores.Pop();
		}else{
			postfijo += c;
			}
		}
		/* vacia la pila y lo lleva al arreglo*/
		while(!operadores.pilaVacia())
		{
			postfijo += operadores.topePila();
			operadores.Pop();
		}
		return postfijo;
	}

};


int main(int argc, char *argv[]) {
	string operacion,ecuacion,ejercicio="";
	Postfijo postfijo;
	Pila <int> pila1;
	int n;
	char numero;

	cout << "Ingrese la expresion infija a convertir en postfija: ";
	getline(cin,operacion);
	
	cout << "Postifjo es: " << postfijo.infijoAPostfijo(operacion) << endl;
	
	ecuacion=postfijo.infijoAPostfijo(operacion);
	cout<<ecuacion<<endl;
	
	for (char c : ecuacion){
		if(!isOperator(c)){
			cout<<"Porfavor ingrese el valor de "<<c<<": "<<endl;
			cin>>numero;
			ejercicio+=numero;
		}else {
			ejercicio+=c;
		}
	}
	cout<<"\n espere su resultado porfavor"<<endl;
	
	for(char c : ejercicio){
		if(c == '+') 
			pila1.suma();
		else if(c == '-')
			pila1.resta();
		else if(c == '*')
			pila1.multiplica();
		else if(c == '/')
			pila1.divide();
		else if(c == '^')
			pila1.potencia();
		else{
			n = c - '0'; //convierte un char a un int 
			pila1.Push(n);
		}
	}
	
	cout<< pila1.Pop()<<endl;

	return 0;
}



