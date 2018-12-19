#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAX 100

using namespace std;

/**Dado un conjunto de N puntos de la recta real, determinar el menor
conjunto de intervalos cerrados de longitud 1 que contenga a todos los puntos dados.*/

void muestra (float v[][MAX], int tam){

    for (int i=0;i<tam;i++)
       cout << "Rango " << i << ": Xi: " << v[0][i] << " Xi+1: " << v[1][i] << endl;

}

//PROGRAMA*****************************

void PRecta(int n, float r[],int &t, float v[][MAX]){

    t=0;
    int i=0;
    while (i<n){
        v[0][t]=r[i];
        v[1][t]=r[i]+1;
        t++;
        while (i<n && r[i]<=v[1][t-1]){

            i++;
        }
    }
}

int main()
{

   int t, n = 6;  //puntos

   float recta[]={0, 0.5, 1.4, 6.1, 7.2, 8};
   float v[2][MAX];

   PRecta(n,recta,t,v);

   muestra(v,t);

   return 0;
}

