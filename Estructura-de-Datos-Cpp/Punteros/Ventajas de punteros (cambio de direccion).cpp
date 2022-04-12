#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	float v1=756.423;
	float v2=900.545;
	float *p_v;
	p_v=&v1;
	cout <<"El primer valor es:"<<*p_v<<endl;

	//Se cambia la direccion a la que apunta el puntero
	p_v=&v2;
	cout <<"El segundo valor es:" <<*p_v<<endl;
	getch();
	return 0;
	}
