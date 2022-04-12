#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;


void leerArchivo();
void MostrarPrimerasLineas();
void Agregar();


int main(int argc, char const* argv[]) {

	int opcion;
	bool repetir = true;
	do {
		cout << "\n\nMenu de Opciones" << endl;
		cout << "1. Leer contactos" << endl;
		cout << "2. Leer primeros N contactos" << endl;
		cout << "3. Agregar contacto" << endl;
		cout << "0. SALIR" << endl;

		cout << "\nIngrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerArchivo();
			break;

		case 2:
			MostrarPrimerasLineas();
			break;

		case 3:
			Agregar();
			break;
		case 0:
			repetir = false;
			break;
		}
	} while (repetir);


	return 0;
}

void leerArchivo() {
	ifstream myfile("telefono.txt");
	string linea;

	if (!myfile)
		cout << "no pudiste abrir el archivo en modo de lectura" << endl;
	else {
		while (getline(myfile, linea, '\n'))
			cout << linea << endl;
	}
	myfile.close();
}

void MostrarPrimerasLineas() {
	fstream myfile("telefono.txt", ios::out | ios::beg);
	int imprimir, contador = 0;
	string parrafo;
	cout << "Por favor inserte el numero de lineas que quiere leer" << endl;
	cin >> imprimir;

	if (!myfile)
		cerr << "el archivo no se puedo abrir" << endl;


	while (getline(myfile, parrafo, '\n')) {
		if (contador < imprimir)
			cout << parrafo << endl;
		contador++;
	}
	myfile.close();
}

void Agregar() {
	vector <string> personas;
	string linea;

	cin.ignore();
	cout << "ingrese nombre seguido de su telefono porfavor" << endl;
	getline(cin, linea);
	personas.push_back(linea);


	fstream myfile("telefono.txt");
	ofstream temp("temp.txt", ios::out);
	if (!myfile) {
		cout << "no pudiste abrir el archivo en modo de lectura" << endl;
	}
	else {
		while (getline(myfile, linea, '\n'))
			personas.push_back(linea);
	}

	sort(personas.begin(), personas.end());
	
	cout<<endl;
	cout<<"tu lista de contactos se ha actualizado"<<endl;
	for(int i=0; i<personas.size();i++){
		cout<<personas[i]<<endl;
	}
	
	myfile.seekp(0);
	for (int i = 0; i < personas.size(); i++) {
		myfile << personas[i];	
	}

	for (int i = 0; i < personas.size(); i++) { //Archivo temporal utilizado.
		temp << personas[i] << endl;
	}

	myfile.close();
	temp.close();

	personas.empty();
}

