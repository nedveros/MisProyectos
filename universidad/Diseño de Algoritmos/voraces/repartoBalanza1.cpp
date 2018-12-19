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

int Suma(int v[], int n){
    int total=0;

    for (int i=0; i<n; i++){
        total+=v[i];
    }
    return total;
}

void permuta(int &x, int &y){
    int aux=x; x=y; y=aux;
}

int main()
{
   //srand(time(0));
   int n = 8;

   int enteros[]={1,1,2,2,4,4,95,101};
/* 1,1,3,4,6,7,7,11
1,2,3,4,6,7,7,10
1,2,5,5,6,7,7,11  no es posible
1,1,1,1,1,1,100,100
1,1,1,2,2,2,97,100
1,1,1,2,2,3,98,100
1,1,2,2,4,4,95,101
//meter del mayor al menor todos siempre q cumplan las condiciones

  */
   int b1[MAX/2];
   int b2[MAX/2];
   int n1=0, n2=0;

    int s1=0, s2=0;

   Quicksort(0,7,enteros);
   int Smitad= Suma(enteros,n)/2;
   int j=0;
   for (int i = n-1; i>=0; i--){

        if (s1+enteros[i]<=Smitad && s1<=s2 && n1<n/2){
                b1[n1]=enteros[i];
                n1++;
                s1+=enteros[i];
        }else{
                if (n2<n/2){
                    b2[n2]=enteros[i];
                    n2++;
                    s2+=enteros[i];
                }else{
                    b1[n1]=enteros[i];
                    n1++;
                    s1+=enteros[i];
                }
        }

    }

    cout << "Tamaño balanzas: " << Smitad;
    cout << "\nSuma de b1: " << Suma(b1,n1);
    cout << "\nSuma de b2: " << Suma(b2,n2);
    cout << "\nElementos de b1:\n";
    muestra(b1,n1);
    cout << "Elementos de b2:\n";
    muestra(b2,n2);


    return 0;
}

