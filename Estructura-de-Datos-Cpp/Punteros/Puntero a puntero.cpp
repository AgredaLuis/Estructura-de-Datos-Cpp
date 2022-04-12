#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	char c='z';
	char *pc=&c;
	char **ppc= &pc;
	char ***pppc= &ppc;
	***pppc='m';
	cout << c<<endl;
	getch();
	return 0;}
