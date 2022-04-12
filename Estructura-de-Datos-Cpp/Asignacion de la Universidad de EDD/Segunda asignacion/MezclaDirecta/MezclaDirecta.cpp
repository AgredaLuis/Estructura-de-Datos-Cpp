#include <iostream>
#include <fstream>

//34 23 12 59 72 44 8 19 28 51


using namespace std;

int cuentaNum();
void mezclar(int& lonSec, int numReg);
void Separar(int lonSec, int numReg);
void mezclaDirecta();

int main(int argc, char *argv[]) {
	
	mezclaDirecta();
	return 0;
}

void mezclaDirecta()
{
	int longSec;
	int numReg;
	numReg = cuentaNum();
	longSec = 1;
	
	while (longSec < numReg)
	{
		Separar(longSec, numReg);
		mezclar(longSec, numReg);
		cout<<"Vuelta finalizada"<<endl;
	}
	cout<<"proceso finalizado"<<endl;
}

void Separar(int lonSec, int numReg)
{
	ifstream f("O.txt");
	ofstream f1("F1.txt");
	ofstream f2("F2.txt");
	
	int numSec, resto, i;
	numSec = numReg /(2*lonSec);
	resto = numReg %(2*lonSec);	
	for (i = 1; i <= numSec; i++)
	{
		for (int j = 1; j <= lonSec; j++)
		{
			int reg;
			f >> reg;
			f1 << reg <<" ";
		}
		for (int j = 1; j <= lonSec; j++)
		{
			int reg;
			f >> reg;
			f2 << reg <<" ";
		}
	}
	if (resto > lonSec)
		resto -= lonSec;
	else
	{
		lonSec = resto;
		resto = 0;
	}
	
	for (int j = 1; j <= lonSec; j++)
	{
		int reg;
		f >> reg;
		f1 << reg <<" ";
	}
	for ( int j = 1; j <= lonSec; j++)
	{
		int reg;
		f >> reg;
		f2 << reg <<" ";
	}
	
	f.close();
	f1.close();
	f2.close();
}

void mezclar(int& lonSec, int numReg)
{
	int numSec, resto, i, j, k;
	int reg1, reg2;
	numSec = numReg /(2 * lonSec);
	resto = numReg %(2 * lonSec);
	ofstream f("O.txt");
	ifstream f1("F1.txt");
	ifstream f2("F2.txt");
	f1 >> reg1;
	f2 >> reg2;
	for (int s = 1; s <= numSec + 1; s++)
	{
		int n1, n2;
		n1 = n2 = lonSec;
		if (s == numSec+1)
		{
			if (resto > lonSec)
				n2 = resto - lonSec;
			else
			{
				n1 = resto;
				n2 = 0;
			}
		}
		i = j = 1;
		while (i <= n1 && j <= n2)
		{
			int actual;
			if (reg1 < reg2)
			{
				actual = reg1;
				f1 >> reg1;
				i++;
			}
			else
			{
				actual = reg2;
				f2 >> reg2;
				j++;
			}
			f << actual <<" ";
		}
		for (k = i; k <= n1; k++)
		{
			f << reg1 <<" ";
			f1 >> reg1;
		}
		for (k = j; k <= n2; k++)
		{
			f << reg2 <<" ";
			f2 >> reg2;
		}
	}
	lonSec *= 2;
	f.close();
	f1.close();
	f2.close();
}

int cuentaNum(){
	ifstream myfile("O.txt");
	int k = 0;
	int registro;
	while (!myfile.eof())
	{
		myfile >> registro;
		k++;
	}
	myfile.close();
	return k;
}
