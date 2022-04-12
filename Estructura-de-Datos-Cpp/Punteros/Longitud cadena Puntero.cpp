#include<iostream>
#include<conio.h>
using namespace std;
int strlen(const register char *cad){
	int cuenta =0;
	while(*cad++)
	    cuenta++;
	return cuenta;
	}
int main(){
	static char cad[]= "Universidad Pontificia";
	cout<<"La longitud de" <<cad<< " es "<< strlen(cad) <<"caracteres"<<endl;
	getch();
	return 0;
}
