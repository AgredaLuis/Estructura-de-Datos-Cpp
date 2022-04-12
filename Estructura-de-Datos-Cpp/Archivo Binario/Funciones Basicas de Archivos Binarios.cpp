#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

struct Persona{// simple structura que se usara como un objeto
	char nombre[10];
	char apellido[10];
	char carrera[12];
	char cualidad[20];
};
class GestorPersona{
	char buffer[4096];
public:
	void EscribirPersona(Persona p);
	void LeerPersona(long registro, Persona &p);
	void LeerArchivo();
	void AgregarEnPosicion(long registro ,Persona &p);
	int LeerPagina(int NroPagina);
	void MostrarRegistroEnBuffer();
	void IngresarEnOrden(long registro, Persona &p);
};

/*void GestorPersona::MostrarRegistroEnBuffer(){
	Persona p;
	
	for(int j=0;j<4096;j+=sizeof(Persona)){
		memcpy(&p,&buffer[j],sizeof(Persona));
		cout<<p.nombre<<" "<<p.apellido<<" "<<p.carrera<<" "<<p.cualidad<<endl;
	}
}*/
void GestorPersona::IngresarEnOrden(long registro, Persona &p){
	fstream ArchivoBinario("datos.bin",ios::binary|ios::in);
	fstream ArchivoBinarioCopia("datos2.bin",ios::binary|ios::out);
	Persona j;
	long contados=0;

	if(!ArchivoBinario&&!ArchivoBinarioCopia)
		cerr<<"no se pudo abrir el archivo para ingresar en orden";
	
	//long desplazamiento=(long) registro *sizeof(Persona);
	
	while(!ArchivoBinario.eof()){
		if(contados==registro)
			ArchivoBinarioCopia.write((char *)&p,sizeof(Persona));
		ArchivoBinario.read((char*)&j,sizeof(Persona));
		if(!ArchivoBinario.eof()){
		ArchivoBinarioCopia.write((char*)&j,sizeof(Persona));
		contados++;
		}
	}
	ArchivoBinario.close();
	ArchivoBinarioCopia.close();
	remove("datos.bin");
	rename("datos2.bin","datos.bin");
}
int GestorPersona::LeerPagina(int NroPagina){
	fstream ArchivoBinaro("datos.bin",ios::in|ios::binary);
	
	if(!ArchivoBinaro)
		cerr<<"no abrio asi que quedate quieto"<<endl;
	return -1;
	
	long desplazamiento= (long) 4096*NroPagina;
	ArchivoBinaro.seekg(desplazamiento,ios::beg);
	ArchivoBinaro.read((char*)&buffer,4096);
	return 0;
}

void GestorPersona::AgregarEnPosicion(long registro, Persona &p){
	ofstream ArchivoBinario("datos.bin",ios::app|ios::binary);
	long dezplazamiento= (long)registro*sizeof(Persona);
	
	if(!ArchivoBinario)
		cerr<<"no pudiste abrir en modo de agregar al alguien";
	ArchivoBinario.seekp(dezplazamiento,ios::beg);
	ArchivoBinario.write((char*)&p,sizeof(Persona));
	ArchivoBinario.close();
}
void GestorPersona::EscribirPersona(Persona p){
	ofstream ArchivoBinario("datos.bin",ios::app|ios::binary);

	if(!ArchivoBinario)
		cerr<<"no te creas que abrio tan facilmente webon"<<'\n'<<"gafo"<<endl;
	
	ArchivoBinario.write((char *)(&p),sizeof(Persona));
	ArchivoBinario.close();
}
void GestorPersona::LeerPersona(long registro, Persona &p){
	ifstream ArchivoBinario("datos.bin",ios::binary);
	if(!ArchivoBinario)
		cerr<<"No puedes leer lo que te dice piazo de verga";
	
	long desplazamiento=(long) registro*sizeof(Persona);
	
	ArchivoBinario.seekg(desplazamiento,ios::beg);
	ArchivoBinario.read((char *)&p, sizeof(Persona));
	cout<<"Nombre    "<<"apellido  "<<"carrera    "<<"cualidad  "<<endl;
	cout<<p.nombre<<" "<<p.apellido<<" "<<p.carrera<<" "<<p.cualidad;
	ArchivoBinario.close();
}
void GestorPersona::LeerArchivo(){
	ifstream ArchivoBinario("datos.bin",ios::binary);
	Persona p;
	
	if(!ArchivoBinario)
		cerr<<"no pudiste abrir en modo para leer todo el archivo"<<endl;
	cout<<"Nombre    "<<"apellido  "<<"carrera    "<<"cualidad  "<<endl;
	while(!ArchivoBinario.eof()){
		ArchivoBinario.read((char *)&p, sizeof(Persona));
		if(!ArchivoBinario.eof())
		cout<<p.nombre<<" "<<p.apellido<<" "<<p.carrera<<" "<<p.cualidad<<endl;
	}
	ArchivoBinario.close();
}
int main(int argc, char *argv[]) {
	GestorPersona gp;
	int respuesta;
	long registro;
	do{
		cout<<"\n\n\nbienvenido a mi primer registro binario"<<endl;
		cout<<"ingrese 1 para escribir e añadir en el archivo una persona"<<endl;
		cout<<"ingrese 2 para leer alguna persona ingresada"<<endl;
		cout<<"ingrese 3 para leer todo el archivo"<<endl;
		cout<<"ingrese 4 para agregar una persona en una posicion expesifica"<<endl;
		cout<<"ingrese 5 salir del programa "<<endl;
		cin>>respuesta;
	switch(respuesta){
	case 1:
		cout<<"añadir persona"<<endl;
		Persona p;
		
		cout<<"ingrese nombre de la persona corto pls"<<endl;
		cin>>p.nombre;
		cout<<"ingrese apellido de la persona corto pls"<<endl;
		cin>>p.apellido;
		cout<<"ingrese su carrera"<<endl;
		cin>>p.carrera;
		cout<<"ingerse cualidad"<<endl;
		cin>>p.cualidad;
		
		gp.EscribirPersona(p);
		break;
	case 2:
		cout<<"leer persona"<<endl;
		cout<<"ingrese que numero de la persona que quiere leer"<<endl;
		cin>>registro;
		
		gp.LeerPersona(registro,p);
		break;
	case 3: 
		cout<<"Leer todos los registros"<<'\n'<<endl;
		gp.LeerArchivo();
		break;
	case 4:
		cout<<"agregar en la posicion deseada"<<endl;
		Persona j;
		long registro;
		cout<<"ingrese en que posicion desea agregarlo"<<endl;
		cin>>registro;
		cout<<"ingrese nombre de la persona corto pls"<<endl;
		cin>>j.nombre;
		cout<<"ingrese apellido de la persona corto pls"<<endl;
		cin>>j.apellido;
		cout<<"ingrese su carrera"<<endl;
		cin>>j.carrera;
		cout<<"ingerse cualidad"<<endl;
		cin>>j.cualidad;
		
		gp.IngresarEnOrden(registro,j);
		break;
	case 5:
		cout<<"gracias por correr el programa"<<endl;
		break;
	default:
	cout<<"opcion no valida"<<endl;
	break;
	}
	}while(respuesta!=5);
	return 0;
}


