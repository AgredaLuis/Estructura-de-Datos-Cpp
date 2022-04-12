#include<iostream>
#include<conio.h>
using namespace std;
char c;
int main(){
	char *pc;
	pc=&c;
	for(c='A';c<='Z';c++)
	    cout <<*pc;
	getch();
	return 0;
	}
