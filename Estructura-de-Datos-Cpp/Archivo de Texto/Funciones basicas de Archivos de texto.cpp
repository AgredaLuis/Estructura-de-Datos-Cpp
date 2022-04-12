#include <iostream>
#include <string>
#include <fstream>

//programa realizado de modo de practica

using namespace std;

void VaciarPantalla();
void writef(string g);
void LeerPal();
void LeerOra();
void CambioDeCaracter();
bool palindromo(string frase,int n);
void CambiarPalabras();
int ContadorDePalabra();
void ContadorDeCaracter();
void MostrarPrimeraLetra();
void ContarLineas();
void ContadorDeCPL();
void InvertirLineas();
void ContarPalindromos();
void QuitarEspaciosEnBlanco();
void MostrarPrimerasLineas();
void MostrarUltimasLineas();
void EliminarComentarios();
void ContarNumerosNegativos();
bool Comentario1(string linea,int longitud);
bool Comentario2(string linea, int longitud);





int main(int argc, char *argv[]) {
	//writef("Como tu mano y mi mano en la noche no sienten frío\nSin ti las horas se pasan, pero con días vacíos\n Como en Marbella las olas, tú estabas bella y a solas\n Y yo te extraño y te extraño, pero te llamo y lo olvido\nComo te quiero y te quiero, pero este amor ya no es mío\nSé que tu boca y mi boca cuando se juntan hay lío\nquisiera quedarme, pero ahora no estás conmigo\nSiempre la vida se pasa, pero no pasa contigo");
	//LeerPal();
	//LeerOra();
	//CambioDeCaracter();
	//CambiarPalabras();
	//cout<<"la palabra se repite "<< ContadorDePalabra() <<" veces";
	//ContadorDeCaracter();
	//MostrarPrimeraLetra();
	//ContadorDeCPL();
	//ContarLineas();
	//InvertirLineas();
	//QuitarEspaciosEnBlanco();
	//MostrarPrimerasLineas();
	//MostrarUltimasLineas();
	//ContarPalindromos();
	//EliminarComentarios();
	//ContarNumerosNegativos();
	
	VaciarPantalla();
	return 0;
}

//muestra la primera letra de cada palabra y las torna en mayuscula
void MostrarPrimeraLetra(){
	
	fstream myfile("x.txt");
	string parrafo;
	
	if(!myfile)
		cerr<<"no pudiste abrir para escribir las primera letra"<<endl;
	while(getline(myfile,parrafo,' ')){
		parrafo[0]= toupper(parrafo[0]);
		cout<< parrafo[0]<<" ";
	}
	myfile.flush();
}

//contador de lineas
void ContarLineas(){
	fstream myfile("x.txt");
	string parrafo; short cont=0;
	if(!myfile) cerr<<"no pudiste contar las lineas"<<endl;
	while(getline(myfile,parrafo,'\n'))
		  cont++;
	myfile.flush();
	cout<<"la cantidad de lineas es : "<<cont<<endl;
	myfile.flush();
}
	
void ContadorDeCaracter(){
	fstream myfile("x.txt");
	string linea;
	char c;
	int contador=0;
	
	cout<<"ingrse el caracter que quiere contar"<<endl;
	cin>>c;
	cout<<"gracias jalabola"<<endl;
	if(!myfile)
		cerr<<"no pudiste cambiar un caracter y piensas cambiar al mundo HDP";
	
	while(getline(myfile,linea,c))
			contador++;
		myfile.flush();
	myfile.close();
	cout<<" el caracter se repite: "<<contador<<endl;
}
int ContadorDePalabra(){
	fstream myfile("x.txt");
	string palabra1,palabra2;
	int contador=0;
	
	cout<<"ingrese la palabra que quieres contar"<<endl;
	cin>>palabra1;
	
	if(!myfile)
		cerr<<"no pudiste abrir para contar la palabra, para que cuentas los dias con ella entonces?"<<endl;
	
	while(myfile>>palabra2){
		if(palabra1.compare(palabra2)==0){
			contador++;
			myfile.flush();
		}
	}
	myfile.close();
	return contador;
}
//cambia la palabra por otra palabra en todo el recorrido 
void CambiarPalabras(){ 
	fstream myfile("x.txt");
	string palabra1,palabra2,palabra3;
	int i;
	
	cout<<"Ingresa la palabrea que quieres cambiar o sustituir \n bien escrita porfavor"<<endl;
	cin>>palabra1;
	cout<<"Ingresa la palabra por cual quieres sustituir la anterior becerro"<<endl;
	cin>>palabra2;
	if(!myfile)
		cerr<<"no pudiste abrir para cambiar palabra,enserio crees cambiarla a ella?"<<endl;
	while(myfile>>palabra3){
		i=palabra3.length(); //guarda por tamaño las palabra leidas
		if(palabra1.compare(palabra3)==0){
			myfile.seekg(-i,ios::cur); // retrocede el espacio de la palabra 
			myfile<<palabra2; //reescribimos la palabra que queremos guardar
			myfile.flush(); //vacia el buffer amiguito , tu computadora se jodera 
		}
	}
	myfile.close();
}
//cambia la letra que quieras por otro caracter en todo el recorrido del archivo
void CambioDeCaracter(){
	fstream myfile("x.txt");
	char caracter; 
	
	if(!myfile)
		cerr<<"no pudiste abrir esto para cambiar un carajo asi como no cambias nada de tu vida"<<endl;
	while(myfile){
		caracter = myfile.get();
		if(caracter==' ') {
			myfile.seekg(-1,ios::cur);
			myfile<<',';
			myfile.flush();
		}
	}
	myfile.close();
}
	
//lee el archivo tal cual con sus carateres de linea 
void LeerOra(){ 
	ifstream myfile("x.txt");
	string linea;
	
	if(!myfile)
		cout<<"no pudiste abrir una verga en modo de lectura"<<endl;
	else {
		while(getline(myfile,linea,'\n'))
			cout<<linea<<endl;
	}
	myfile.close();
	
}
//lee por palabra y las separa 
void LeerPal(){  
	string linea;
	ifstream myfile("x.txt");
	if(!myfile){
		cout<<"no pudiste abrir de modo de lectura"<<endl;
		exit(1);
	}
	else{
	   while (!myfile.eof()) {
		   myfile >> linea;
		   cout << linea << endl; // muestra lo pantalla
		   
	}
	   myfile.close();
	}
}
//escribe en el archivo de texto
void writef(string g){
	ofstream myfile("x.txt");
	if(!myfile)
		cout<<"no abriste una verga escribiendo \n";
	else {
	   myfile<<g;
	   cout<<"imprimiste con exito"<<endl;
	   myfile.close();
	}
}
	
//invierte las lineas del archivo de texto
void InvertirLineas(){ 
	fstream myfile("x.txt");
	string parrafo1,parrafo2=" ";
	
	if(!myfile) cerr<<"no pudiste abrir este archivo asi como no podras abrir sus piernas"<<endl;
	
	while(getline(myfile,parrafo1,'\n')){
		parrafo2= parrafo1 + "\n" + parrafo2;
	}
	myfile.seekg(ios::beg);
	myfile<<parrafo2;
	cout<<parrafo2;
	myfile.flush();
}
void VaciarPantalla(){
	cout<<"\n\n\ngracias por correr el programa"<<endl;
}
//Contador de caracteres, palabras y lineas	
void ContadorDeCPL(){    
	fstream myfile("x.txt");
	string parrafo,palabrita;
	int caracteres=0,palabras=0,lineas=1;
	
	if(!myfile) cerr<<"el archivo no se encontro"<<endl;
	while(getline(myfile,parrafo,' ')){
		palabras++;
		caracteres= caracteres + parrafo.length();
		if(parrafo.find('\n')!= string::npos)
		   lineas++;
	}
	
	
	cout<<"hay "<<caracteres<<" caracteres y un numero de"<<palabras<<"palabras y de lineas tiene"<<lineas;
}
	
//Eliminar los espacios en blanco dentro del archivo
void QuitarEspaciosEnBlanco(){ 
	fstream myfile("x.txt");
	string parrafo,parrafo2="";
	
	if(!myfile){ cerr<<"tu de 19 y yo de 23";}
	while(myfile>>parrafo){
		parrafo2=parrafo2 +parrafo;
	}
	cout<<parrafo2;
	myfile<<parrafo2;
	myfile.flush();
	
}
	
//muestra las primeras n lineas del archivo
void MostrarPrimerasLineas(){
	fstream myfile("x.txt");
	int imprimir,contador=0;
	string parrafo;
	
	cout<<"Por favor inserte el numero de lineas que quiere leer"<<endl;
	cin>>imprimir;
	
	if(!myfile)
	cerr<<"Ojala me atropelle sus nalgas..., ya ni se que escribir"<<"ladilla"<<"Rosalia"<<"TUsae"<<endl;

	
		while(getline(myfile,parrafo,'\n')){
		if(contador<imprimir)
		cout<<parrafo<<endl;
		contador++;
		}
	
}

//muestras las ultimas n lineas del archivo
void MostrarUltimasLineas(){
	fstream myfile("x.txt");
	string parrafo1,parrafo2="";
	int imprimir,Linea=0,Longitud=0,contadordelineas=0;
	
	cout<<"porfavor ingrese un numero(necesariamente valido) para imprimir las lineas"<<endl;
	cin>>imprimir;
	if(!myfile)
		cerr<<"no pudiste abrir esta mamaguevada"<<endl;
	while(getline(myfile,parrafo1,'\n')){
		Linea++;
		parrafo2=parrafo2+parrafo1+'\n';
	}
	Longitud=parrafo2.length();
	for(int i=0;i<Longitud;i++){
		if(parrafo2[i]=='\n')
		contadordelineas++;
		if(Linea-contadordelineas==imprimir||Linea-contadordelineas<imprimir)
			cout<<parrafo2[i];
	}
	}
	
//recorre el archivo contando las palabras palindromas
void ContarPalindromos(){
	fstream myfile("x.txt");
	string parrafo;
	int contador=0,longitud;
	
	if(!myfile)
		cerr<<"No pudo abrir en modo palindromo, osea como piensas cogerteela palindromamente te pica ese klo?"<<endl;
	
	while(myfile>>parrafo){
		longitud=parrafo.length();
		if(palindromo(parrafo,longitud)==true){
			contador++;
		}else cout<<"no existen palabras palindromos en este archivo"<<endl;
	}
	cout<<"hay exactamente"<<contador<<"palabras palindromas en el archivo"<<endl;
	myfile.flush();
}
//bool para verificar si es palindroma la palabra
bool palindromo(string frase,int n){
	for(int i=0;i<n/2;i++){
		if(frase[i]!=frase[n-1-i])
			return false;
	}
	return true;
}
//Programa para borrar los comentarios dentro de un archivo .cpp
void EliminarComentarios(){
	ifstream ArchivoCPP("Source.cpp");
	ofstream ArchivoCPPsin("Source2.txt");
	string linea;
	int longitud;
	
	if(!ArchivoCPP)
		cerr<<"no pudiste abrir este archivo nigga"<<endl;
	if(!ArchivoCPPsin)
		cerr<<"no pudiste abrir el archivo punto txt"<<endl;
		
	while(getline(ArchivoCPP,linea,'\n')){
		longitud=linea.length();
		if(Comentario1(linea,longitud)==false&&Comentario2(linea,longitud)==false){
			ArchivoCPPsin<<linea<<endl;
		}
		}
}
//bool para verificar si hay comentarios comenzado con "//"
bool Comentario1(string linea,int longitud){
	int i;
	for(i=0;i<longitud;i++){
		if(linea[i]=='/'&&linea[i+1]=='/')
			return true;
	}
	return false;
}
	
//bool para verificar si existen comentarios comenzados en /* y terminados en */
bool Comentario2(string linea, int longitud){
	bool flag;
	for(int i=0;i<longitud;i++){
		if(linea[i]=='/'&&linea[i+1]=='*'){
			flag=true;
			return true;
		}
		while(i<longitud&&flag==true){
		if(linea[i]=='*'&&linea[i+1]=='/')
		flag=false;
		}
	}
	return flag;
}

//programa para contar cuantos numeros negativos existen dentro del archivo
void ContarNumerosNegativos(){ 
	fstream Archivo("x.txt");
	string lectura;
	int contador=0;
	
	if(!Archivo)
		cerr<<"no pudiste abrir el archivo"<<endl;
	
	while(getline(Archivo,lectura,'-')){
		contador++;
	}
		cout<<"la cantidad de numeros negativos es: "<<contador<<endl;
	
}
	
