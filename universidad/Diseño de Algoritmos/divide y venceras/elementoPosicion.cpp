/**
   @file Resolución del problema del elemento en su posicion
*/


#include <iostream>
using namespace std;


/**
   Sea a[1..n] un vector ordenado de enteros todos distintos. Nuestro problema es
implementar un algoritmo de complejidad O(logn) en el peor caso capaz de
encontrar un índice i tal que 1≤i≤n y a[i] = i, suponiendo que tal índice exista.
*/


int Localiza(int a[], int prim, int ult){
int i;

    if (prim>ult) return -1; // no existe tal indice
    i=(prim+ult)/ 2;
    if (a[i]==i)
        return i;
    else
        if (a[i]>i)
            return Localiza(a,prim,i-1);
        else
            return Localiza(a,i+1,ult);

}

int main()
{

    int a[]={-1,1,4,5,6,8};
    cout << "Posicion: " << Localiza(a, 0, 5); // -1 No lo encuentra

    return 0;
}
