#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;
//3.- Escribir un programa que permita crear un archivo inventario de los libros de una librería,
//	así como calcular e imprimir el valor total del inventario. Los campos de cada libro deben ser,
//	como mínimo, título, autor, ISBN, precio, cantidad, editorial.

struct libro{
	char Titulo[20];
	char Autor[20];
	char ISBN[13];
	int precio;
	int cantidad;
	char editorial[20];
	
};

class GestorDeLibros{
public:
	void IngresarLibro(libro l);
	void LeerArchivo();
	
};

void GestorDeLibros::IngresarLibro(libro l){
	ofstream ArchivoBinario("Inventario.bin",ios::app|ios::binary);
	
	if(!ArchivoBinario)
		cerr<<"error"<<endl;
	
	ArchivoBinario.write((char *)(&l),sizeof(libro));
	ArchivoBinario.close();
}
void GestorDeLibros::LeerArchivo(){
	ifstream ArchivoBinario("Inventario.bin",ios::binary);
	libro l;
	int sumatoria=0,total=0;
	
	if(!ArchivoBinario)
		cerr<<"no pudiste abrir en modo para leer todo el archivo"<<endl;
	cout<<"Titulo    "<<"Autor     "<<"ISBN         "<<"precio  "<<"cantidad  "<<"editorial     "<<endl;
	while(!ArchivoBinario.eof()){
		ArchivoBinario.read((char *)&l, sizeof(libro));
		if(!ArchivoBinario.eof()){
			cout<<l.Titulo<<" "<<l.Autor<<" "<<l.ISBN<<" "<<l.precio<<" "<<l.cantidad<<" "<<l.editorial<<" "<<endl;
			sumatoria=l.cantidad*l.precio;
			total+=sumatoria;
		}
	}
	cout << "el precio actual en el inventario es: "<<total<<endl;
	ArchivoBinario.close();
}

int main(int argc, char *argv[]) {
	GestorDeLibros gl;
	int respuesta;
	do{
		cout<<"ingrese 1 para ingresar un libro"<<endl;
		cout<<"ingrese 2 para leer todo el archivo"<<endl;
		cout<<"ingrese 3 salir del programa "<<endl;
		cin>>respuesta;
		switch(respuesta){
		case 1:
			cout<<"agregar libro"<<endl;
			libro l;
			cin.ignore();
			cout<<"ingrese titulo del libro"<<endl;
			cin.getline(l.Titulo,20);
			cout<<"ingrese autor del libro"<<endl;
			cin.getline(l.Autor,20);
			cout<<"ingrese su ISBN"<<endl;
			cin.getline(l.ISBN,20);
			cout<<"ingrese editorial"<<endl;
			cin.getline(l.editorial,20);
			cout<<"ingrese el precio"<<endl;
			cin>>l.precio;
			cout<<"ingrese la cantidad actual"<<endl;
			cin>>l.cantidad;
			
			
			gl.IngresarLibro(l);
			break;
		case 2:
			cout<<"Leer todos los registros"<<'\n'<<endl;
			gl.LeerArchivo();
			break;
		case 3:
			cout<<"gracias por correr el programa"<<endl;
			break;
		default:
			cout<<"opcion no valida"<<endl;
			break;
		}
	}while(respuesta!=3);
	return 0;
}

