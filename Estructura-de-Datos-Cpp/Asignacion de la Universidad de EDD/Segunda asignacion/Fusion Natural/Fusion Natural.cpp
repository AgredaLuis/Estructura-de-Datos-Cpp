// Fusion Natural.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

using namespace std;

void Mezcla(int*, int, int, int);
void Mezcla_orden(int* arr, int low, int high);
void fusion_natural();

int main()
{
    fusion_natural();
    system("pause");
    return 0;

}

void Mezcla_orden(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        //Dividir el arreglo en mitades y ordenar con fusion
        mid = (low + high) / 2;
        Mezcla_orden(arr, low, mid);
        Mezcla_orden(arr, mid + 1, high);
        //Une los arreglos ordenados
        Mezcla(arr, low, high, mid);
    }
}

void Mezcla(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}

void fusion_natural(){
    ofstream archivo;
    archivo.open("Fusion_N.txt", ios::out | ios::app); 
    if (!archivo) {
        cerr << "error";
        exit(1);
    }

    int A[10], num;
    cout << "Ingrese los elementos a ser ordenados: ";
    cin >> num;
    cout << "Ingrese " << num << " elementos a ser ordenados: "<<endl;
    for (int i = 0; i < num; i++) {
        cout << "nro " <<(i+1)<<": ";
        cin >> A[i];
    }
    Mezcla_orden(A, 0, num - 1);
   
    for (int i = 0; i < num; i++)
    {
        archivo << A[i] << "\t";
    }
    archivo << endl;
    cout << "Elementos Ordenados han sido enviados a un archivo de texto" <<endl;
    archivo.close();
}