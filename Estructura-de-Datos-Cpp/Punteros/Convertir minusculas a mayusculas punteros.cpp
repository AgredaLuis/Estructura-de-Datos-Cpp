#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	char *p;
	char CadenaTexto[80];
	cout <<"Introduzca cadena a convertir:";
	cin.getline(CadenaTexto, sizeof(CadenaTexto));
	p=&CadenaTexto[0];//p apunta al primer caracter de la cadena
	while(*p){//Mientras que p apunte a un caracter que no sea nulo
	    if((*p>='a') && (*p<='z'))
	        *p++=*p-32;//el contenido de p sera igual al contenido de p menos 32 posiciones en ascii
	        
		else p++;
	}
	cout <<"La cadena convertida es:"<< endl;
	cout <<CadenaTexto <<endl;
	getch();
}
