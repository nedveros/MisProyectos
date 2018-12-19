#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAX 10

using namespace std;

//Quicksort *************************
void burbuja(int *T, int primero, int ultimo){
 int i, j;
 int aux;
 for (i = primero; i <ultimo; i++)
	 for (j = primero; j <=i; j++)
		 if (T[j] >T[j+1]){
            aux = T[j];
            T[j] = T[j+1];
            T[j+1] = aux;
         }
 }

void muestra (int *v, int tam){

    for (int i=0;i<tam;i++)
        cout << v[i] << ", ";
    cout <<endl;
}

void Cambiar ( int i, int j, int *v ) {

    int x;

    x = v[i];
    v[i] = v[j];
    v[j] = x;

}

/*-------------------------------------------*/

int Encontrar_pivote ( int i, int j, int *v ) {

    int primera_clave, k;

    primera_clave = v[i];
    k = i+1;

    while (( v[k] == primera_clave ) && ( k <= j )) {
        k++;
    }

    if ( k <= j ) {

       if ( v[k] <= primera_clave ) {
          return i;
       } else {
                return k;
         }

    } else {
           return -1;
      }

}

/*--------------------------------------------*/

int Reordenar ( int i, int j, int pivote, int *v ) {

    int inf, sup;

    inf = i;
    sup = j;

    do {

        Cambiar ( inf, sup, v );
        while ( v[inf] < pivote ) {
            inf++;
        }
        while ( v[sup] >= pivote ) {
            sup--;
        }

    } while ( inf <= sup );

    return inf;

}

/*---------------------------------------------*/

void Quicksort ( int i, int j, int *v ) {

    int indice_pivote;
    int pivote;
    int k;

    if ( j-i+1 <= 2 ) {
            burbuja(v, i, j);
    }else{
        indice_pivote = Encontrar_pivote ( i, j, v );

        if ( indice_pivote != -1 ) {
            pivote = v[indice_pivote];

            k = Reordenar ( i, j, pivote, v );

            Quicksort ( i, k-1, v );
            Quicksort ( k, j, v );
        }
    }

}

int Busca(int x,int v[],int n){

	 for (int i = 0; i < n; i++){
        if (x==v[i])
            return i;
	 }
	 return -1;
}

//PROGRAMA*****************************

int main()
{
   srand(time(0));
   int n = (rand()%MAX)+1;

   int procesos[MAX];
   int pos[MAX];
   for (int i = 0; i < n; i++){
            procesos[i]= (rand()%300)+1;
            pos[i]=procesos[i];
    }
    cout << "Tiempos desordenados: \n";
    muestra(procesos,n);
    cout << "Tiempos crecientes: \n";
    Quicksort(0,n-1,procesos);
    muestra(procesos,n);
    int esperaParcial = 0;
    int tiempoProcesos = 0;
    int i;

    for ( i = 0; i<n ; i++) {

        cout << "proceso " << Busca(procesos[i],pos,n)
                << ": Ti (ejecucion) -> " << procesos[i] << " ms."
                << "\tEi (espera) parcial: " << esperaParcial << " ms."<< endl;
        tiempoProcesos += procesos[i];
        esperaParcial += procesos[i];
    }
    //tiempo final el total menos el de la última reparación
    int E = esperaParcial - procesos[i-1] ;
    cout << endl << "Numero total de procesos: " << n << endl;
    cout << "Tiempo total de espera: " << E << " ms." << endl;
    cout << "Tiempo total de ejecucion: " << tiempoProcesos << " ms." << endl;
    cout << "Tiempo Toal minimizado: " << E+tiempoProcesos << " ms." << endl;

    return 0;
}

