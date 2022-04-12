#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

//2.- La información acerca de un conjunto de personas se ha almacenado en un archivo binario
//	para propósitos estadísticos. La información almacenada de cada persona es el nombre, altura,
//	tamaño del zapato, edad y estado civil. Con el objeto de procesar los datos, el sexo de cada
//	persona tiene que conocerse, aunque esta información no se incluye en el archivo. Escribir un
//	programa que lea el archivo y crea dos archivos nuevos, uno que contiene sólo mujeres y otro
//	con sólo hombres. Por cada persona del archivo, el programa debe pedir al operador si una
//	persona es un hombre o una mujer.


using namespace std;

struct persona{
	char nombre[20];
	char altura[4];
	char zapato[8];
	char edad[4];
	char civil[12];
	
};
class ManejadorDePersonas{
public:
	
	void IngresarPersona(persona p);
	void IngresarHombre(persona p);
	void IngresarMujer(persona p);
	void LeerArchivo();
};
void ManejadorDePersonas::IngresarPersona(persona p){
	ofstream ArchivoBinario("Lista.bin",ios::app|ios::binary);
	
	if(!ArchivoBinario)
		cerr<<"no te creas que abrio tan facilmente webon"<<'\n'<<"gafo"<<endl;
	
	ArchivoBinario.write((char *)(&p),sizeof(persona));
	ArchivoBinario.close();
}
void ManejadorDePersonas::LeerArchivo(){
	ifstream ArchivoBinario("Lista.bin",ios::binary);
	persona p;
	char opc;
	
	if(!ArchivoBinario)
		cerr<<"no pudiste abrir en modo para leer todo el archivo"<<endl;
	
	while(ArchivoBinario.read(reinterpret_cast<char*>(&p),sizeof(persona))){
			cout<<p.nombre<<" "<<p.altura<<" "<<p.zapato<<" "<<p.edad<<" "<<p.civil<<endl;
			cout<<"Podria indicarnos si es hombre o mujer?"<<endl;
			cout<<"ingrese 'h' si es hombre 'm' si es mujer"<<endl;
			cin>>opc;
			if(opc=='h'){
				ofstream ArchivoBinario("ListaHombre.bin",ios::app|ios::binary);
				
				if(!ArchivoBinario)
					cerr<<"no te creas que abrio tan facilmente webon"<<'\n'<<"gafo"<<endl;
				
				ArchivoBinario.write((char *)(&p),sizeof(persona));
				ArchivoBinario.close();
				
			}else if(opc=='m'){
				ofstream ArchivoBinario("ListaMujeres.bin",ios::app|ios::binary);
				
				if(!ArchivoBinario)
					cerr<<"no te creas que abrio tan facilmente webon"<<'\n'<<"gafo"<<endl;
				
				ArchivoBinario.write((char *)(&p),sizeof(persona));
				ArchivoBinario.close();
			}else{
				cout<<"caracter no valido"<<endl;
			}
	}
	ArchivoBinario.close();
}

void ManejadorDePersonas::IngresarMujer(persona p){
	ofstream ArchivoBinario("ListaMujeres.bin",ios::app|ios::binary);
	
	if(!ArchivoBinario)
		cerr<<"no te creas que abrio tan facilmente webon"<<'\n'<<"gafo"<<endl;
	
	ArchivoBinario.write((char *)(&p),sizeof(persona));
	ArchivoBinario.close();
}


int main(int argc, char *argv[]) {
	ManejadorDePersonas mp;
	int respuesta;
	do{
		cout<<"ingrese 1 para ingresar un persona"<<endl;
		cout<<"ingrese 2 para leer todo el archivo"<<endl;
		cout<<"ingrese 3 salir del programa "<<endl;
		cin>>respuesta;
		switch(respuesta){
		case 1:
			persona p;
			cout<<"ingrese nombre"<<endl;
			cin>>p.nombre;
			cout<<"ingrese altura"<<endl;
			cin>>p.altura;
			cout<<"ingrese talla de zapato"<<endl;
			cin>>p.zapato;
			cout<<"ingrese edad"<<endl;
			cin>>p.edad;
			cout<<"ingrese estado civil"<<endl;
			cin>>p.civil;
			
			mp.IngresarPersona(p);
			break;
		case 2:
			cout<<"Leer todos los registros"<<'\n'<<endl;
			mp.LeerArchivo();
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
	return 0;
}

