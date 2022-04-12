#include<iostream>
#include<conio.h>
using namespace std;
int strlen(const char cad[]){
	int posicion=0;
	while (cad[posicion]!='\0'){
		posicion++;
	}
	return posicion;
	}
int main (){
	char alfa[]="abcdefghijklmnopqrstuvwxyz";
	char *p=&alfa[0];
	while (*p)
		cout<<*p++<<endl;
	getch();
	return 0;
}
