#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAX 100

using namespace std;

/**Tenemos un maraton de cine en 24 horas, del cual sabemos su programación:
cual es la hora de comienzo, la duración y sala de proyección
(todas las peliculas son distintas. Se desea conocer cual es la secuencia de
 peliculas a ver para ver el maximo numero posible*/


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

void muestra (bool v[], int tam){

    cout << "\nVera las peliculas:" << endl;
    for (int i=0;i<tam;i++){
        if (v[i])
            cout << "Pelicula: " << i+1 << endl;
    }
}

void mostrar_datos(int n, int c[], int f[])
{
     cout<<" Peliculas Maraton. "<<endl<<endl ;
     cout<<"\t Pi     :  " ;
     for(int i=0; i<n; i++)
         cout<< i+1 <<' ';

     cout<<endl<<"\t-------------------------"<<endl ;

     cout<<"\t inicio :  " ;
     for(int i=0; i<n; i++)
         cout<< c[i] <<' ';

     cout<<endl ;
     cout<<"\t fin    :  " ;
     for(int i=0; i<n; i++)
         cout<< f[i] <<' ';

}

//PROGRAMA*****************************

void MaratonCine(int n, int c[], int d[], bool s[]){

    int f[MAX];
    for (int i=0; i<n ; i++){
        f[i]=c[i]+d[i];
        s[i]= false;
    }

    Quicksort(0,n-1,f);  //voraz: creciente por orden de finalizacion

    mostrar_datos(n,c,f);

    s[0]=true;  //la primera siempre se ve
    int final=f[0];   //final de la ultima
    for (int i=1; i<n; i++){
        if (c[i]>=final){
            s[i]=true;
            final=f[i];
        }
    }
}

int main()
{

   int n = 6;  //puntos

   int comienzo[]={0, 1, 2, 5, 6, 8};
   int duracion[]={1, 2, 2, 2, 1, 2};
   bool s[MAX];

   MaratonCine(n,comienzo,duracion,s);

   muestra(s,n);

   return 0;
}

