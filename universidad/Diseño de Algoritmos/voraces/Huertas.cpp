#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAX 100

using namespace std;

/**El tio Facundo posee N huertas, cada una con un tipo diferente de árboles frutales.
Las frutas ya han madurado y es hora de recolectarlas.
La recolección de una huerta exige un dia completo. El tio Facundo conoce, para cada una de
las huertas, el beneficio (bi) que obtendrá por la venta de lo recolectado.
Tambien sabe los días que tardan en pudrirse los frutos de cada huerta (pi).
Ayudar al tio Facundo a decidir que huertas debe recolectar y cuando debe hacerlo,
para maximizar el beneficio obtenido.*/


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

void muestra (int v[], int b[], int tam){
    int total=0;
    cout << "\nRecolectara estas Huertas:" << endl;
    for (int i=1;i<=tam;i++){
        total+=b[v[i]];
        cout << "Huerta: " << v[i] << " en el dia: " << i << " con Benef.: " << b[v[i]] << endl;
    }
    cout << "\n total beneficio: " << total << endl;
}

void mostrar_datos(int n, int p[], int b[])
{
     cout<<" Huertas. "<<endl<<endl ;
     cout<<"\t Hi        :  " ;
     for(int i=1; i<=n; i++)
         cout<< i <<"  ";

     cout<<endl<<"\t-------------------------"<<endl ;

     cout<<"\t Plazo :      " ;
     for(int i=1; i<=n; i++)
         cout<< p[i] << "  ";

     cout<<endl ;
     cout<<"\t Beneficio :  " ;
     for(int i=1; i<=n; i++)
         cout<< b[i] <<' ';

}

//PROGRAMA*****************************
//ordenadas de mayor a menor beneficio
//No hace falta pasar el vector de beneficios pq se suponen ordenados
void Huertas(int n, int p[], int b[], int aux[], int &k){
    //int aux[MAX];
    int d;
    k=1;
    aux[1]=1;
    for (int i=2; i<=n ; i++){
        //buscar hueco lo mas tarde posible
        d=k;
        while(d>0 && p[aux[d]]>p[i] && p[aux[d]]>d){
            d--;
        }

        // si sale del bucle anterior
        if (p[i]>d){   //puede recolectarse
            //se desplazan un dia las huertas posteriores
            for (int j=k; j>=d+1; j--){
                aux[j+1]=aux[j];
            }
            //guardo la huerta recolectada y espero la siguiente
            aux[d+1]=i;
            k++;
        }
    }
    //las copio en la salida
   /* for (int i=1; i<=k; i++){
        huerta[i]=aux[i];
    }
*/
}

int main()
{

   int k,n = 6;  //puntos

   int beneficio[]={0, 30, 25, 15, 10, 6, 2};
   int plazo[]=    {0,  4,  3,  1,  1, 4, 1};
   int s[MAX];

   mostrar_datos(n,plazo,beneficio);

   Huertas(n,plazo,beneficio,s,k);

   muestra(s,beneficio,k);

   return 0;
}

