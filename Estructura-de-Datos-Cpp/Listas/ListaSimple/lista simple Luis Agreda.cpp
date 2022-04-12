#include <iostream>
using namespace std;

template <class T>
class Nodo{
	
	T clave; //informacion satelite
	Nodo<T> *proximo,*previo;
	
public:
	Nodo(){previo=proximo=NULL;}
	
T ObtenerClave(){
		return clave;
	}
void FijarClave(T x){
	clave=x;
}
void FijarPrevio(Nodo<T> *x){
	previo=x;
}
Nodo<T> *obtenerPrevio(){
	return previo;
}
void FijarProximo(Nodo<T> *x){
	proximo=x;
}
Nodo<T> *ObtenerProximo(){
	return proximo;
}

};
template <class T>
class ListaSimple{
	Nodo<char> *inicio;
	
public:
	ListaSimple(){
		inicio=NULL;
	}
	
	//este metodo es insertar normal
	void InsertarInicio(T dato){
		Nodo<T> *aux = new Nodo<T>;    //simple crea un nodo,ponle la clave
		aux->FijarClave(dato);        //verifica que hayan nodos o no

		if(!inicio){                  //recuerda que inicio quiere decir el inicio
			aux->FijarProximo(NULL);  //de la lista por ende cada vez que ingreses
			inicio = aux;             //ese sera el inicio sabiendo que siempre es el lado izquierdo de la lista 
		}else {                       //para que el metodo buscar sea desde inicio hasta el null
			aux->FijarProximo(inicio);
			inicio=aux;
		}
		cout<<"Dato ingresado"<<endl;
	}
	void EliminarEnCantidad(int m){
		int n=0;
		Nodo<T> *temp=inicio;
		
		while(temp!=NULL&&n<m-1){
				temp=temp->ObtenerProximo();
				n++;
			}
			inicio=temp;
		cout<<"se ha disminuido la lista"<<endl;
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

	void InvertirLista(){
		Nodo<T> *despues=NULL;
		Nodo<T> *prev=NULL;
		Nodo<T> *temp= inicio;
		
		while(temp){
			despues=temp->ObtenerProximo();
			temp->FijarProximo(prev);
			prev=temp;
			temp= despues;
		}
		inicio=prev;
	}
		
	void InsertarFinal(T dato){
		Nodo<T> *aux=new Nodo<T>;
		aux->FijarClave(dato);
		Nodo<T> *temp=inicio;
		
		
		if(!inicio){                      //verificar si no es el primero como siempre
			aux->FijarProximo(NULL);      //y si es el primero ponerlo como primero pues
			inicio=aux;
		}else {
			while(temp->ObtenerProximo()!=NULL){ //con un nodo temporal iremos avanzando hasta llegar al nodo que sea igual a NULL
				temp=temp->ObtenerProximo(); 
			}
			temp->FijarProximo(aux);          //llegara un momento que sera el ultimo y haremos que el siguiente sea el nodo que queremos ingresar 
		}                                     // de por si ya el nodo siempre apunta a siguiente como null
		cout<<"se ha insertado el dato"<<endl;
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

		//digamos que siempre para hacer algo buscar o recorrer la lista , debe crear un nodo guia
		// e igualarlo al nodo inicial de la lista para que lo recorra.
	void Imprimir(){
		Nodo<T> *temp=inicio;
		while(temp){
			if(temp!=NULL)
				cout<<temp->ObtenerClave()<<", ";
			temp=temp->ObtenerProximo();
		}
		cout<<endl;
		
	}
	
	void Eliminar(T dato){  //aqui eliminaremos por dato no por posicion
		Nodo<T> *temp=inicio;          // creamos un nodo para que vaya arreglando la lista
		Nodo<T> *temp1=inicio->ObtenerProximo();  // creamos otro nodo que verificara si hay datos iguales
		short mensaje=0;
		
		if(inicio->ObtenerClave()==dato){ //en este if verificamos si el primero de la lista es igual al dato
			inicio=temp->ObtenerProximo();
		}else {
			while(temp1){ //aqui comienza lo bueno bebe
				if(temp1->ObtenerClave()==dato){          //verificamos si el nodo que recorre la lista se verifica
					Nodo<T> *aux=temp1;                   //si es asi , se crea un nodo y se iguala 
					temp1=temp1->ObtenerProximo();        //luego el nodo de verificar se adelanta
					temp->FijarProximo(temp1);            // y adjuntamos el siguiente del nodo arreglar lista al proximo del nodo de verificar
					delete aux;                           // eliminamos el nodo que ya tenemos 
					mensaje++;                            // que salga mensaje que eliminamos el nodo
					cout<<"el dato ha sido eliminado"<<endl;
				}
				
				temp=temp->ObtenerProximo();       //avanzamos 
				temp1=temp1->ObtenerProximo();     // avanzamos recuerda que este eliminar elimina todas las repetidas
			}
			Imprimir();
			if(mensaje==0)
				  cout<<"no se encontro el dato a eliminar"<<endl;
		}
		
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
int main(int argc, char *argv[]) {
	ListaSimple<char> Ls;
	int respuesta,numero;
	char dato;
	
	do{
		cout<<"ingrese 1 para AGREGAR elementos a inicio de la lista"<<endl;
		cout<<"ingrese 2 para AGREGAR elementos a al final de  lista"<<endl;
		cout<<"ingrese 3 para BUSCAR elementos a la lista"<<endl;
		cout<<"ingrese 4 para ELIMINAR un dato de la lista"<<endl;
		cout<<"ingrese 5 para IMPRIMIR los elementos dentro de la lista"<<endl;
		cout<<"ingrese 6 para ELIMINAR VARIOS ELEMENTOS de la lista enlazada"<<endl;
		cout<<"ingrese 7 para INVERTIR LA LISTA de los elementos dentro la lista enlazada"<<endl;
		cout<<"ingrese 8 para SAlir del menu"<<endl;
		cin>>respuesta;
		switch(respuesta){
		case 1:
		{
			cout<<"ingrese el dato a guardar a la ListaSimple"<<endl;
			cin>>dato;
			
			Ls.InsertarInicio(dato);
			break;
		}
		case 2:
		{
			cout<<"ingrese el dato para guardar al final de la ListaSimple"<<endl;
			cin>>dato;
			
			Ls.InsertarFinal(dato);
			break;
		}
		case 3:
		{
			 cout<<"ingrese la dato que quiere buscar en la lista"<<endl;
			 cin>>dato;
			 Ls.buscar(dato);
			break;
		}
		case 4:
		{
			cout<<" ingrese el dato que quiere eliminar en la lsita enlazada"<<endl;
			cin>>dato;
			
			Ls.Eliminar(dato);
			cout<<"volviendo al menu"<<endl;
			break;
		}
		case 5:
		{
			cout<<"en las lista hay: ";
			Ls.Imprimir();
			break;
		}
		case 6:
			{
			cout<<"eliminar por cantidad"<<endl;
			cout<<"porfavor ingrese lacantidad que quiere eliminar"<<endl;
			cin>>numero;
			
			Ls.EliminarEnCantidad(numero);
			Ls.Imprimir();
		}
		case 7:
		{
				cout<<"estas apunto de invertir la lista"<<endl;
				cout<<"asi que agarrate"<<endl;
				
				Ls.InvertirLista();
				Ls.Imprimir();
			}
		default:
		{
			
			break;
		
		}
		}
	}while(respuesta!=8);
	return 0;
}
