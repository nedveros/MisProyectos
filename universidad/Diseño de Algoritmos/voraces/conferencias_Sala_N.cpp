#include<iostream>
#include<stdlib.h>

#define MAX 50
using namespace std;


/*                         Insertamos datos
------------------------------------------------------------------------*/
void leer_conferencias(int c[], int f[], int n)
{
     for(int i=1; i<=n; i++){
            do{
                 cout << "  Conferencia " << i << endl<< endl ;
                 cout << "\tinicio : " ; cin >> c[i] ;
                 cout << "\tfinal  : " ; cin >> f[i] ;
                 cout << endl ;
            }while( c[i] > f[i] ) ;  // el inicio no puede ser mayor que el final
     }
}
//MOSTRAR SOLUCION

void mostrar_datos(int c[], int f[], int n)
{
     cout<<" conferencias insertadas ordenadas por inicio. "<<endl<<endl ;
     cout<<"\t Ci     :  " ;
     for(int i=1; i<=n; i++)
         cout<< i <<' ';

     cout<<endl<<"\t-------------------------"<<endl ;

     cout<<"\t inicio :  " ;
     for(int i=1; i<=n; i++)
         cout<< c[i] <<' ';

     cout<<endl ;
     cout<<"\t fin    :  " ;
     for(int i=1; i<=n; i++)
         cout<< f[i] <<' ';

}
//Ordenar Conferencias

void Ordenar_BMejorado (int c[], int f[], int n)
{
     int aux1, aux2, cambio = 1 ;

     for(int i=n; i>1 && cambio==1; i--){
          cambio = 0;
          for(int j=1; j<i; j++){
                 if( c[j] > c[j+1])
                 {
                      aux1   = f[j]   ;
                      f[j]   = f[j+1] ;
                      f[j+1] = aux1   ;

                      aux2   = c[j]   ;
                      c[j]   = c[j+1] ;
                      c[j+1] = aux2   ;

                      cambio = 1 ;
                 }
          }
     }
}
/*                         Devolviendo solucion
------------------------------------------------------------------------*/

void devolver_solucion(int S[], int k)
{
     for (int i=1;i<=k;i++)
            cout<<"Conferencia " << i << " en la sala " << S[i]<< endl;

}
/*                         Algoritmo de solucion
------------------------------------------------------------------------*/

void Conferencias_VorazN( int c[], int f[], int n){
     int tiempo[MAX];
    int sala[MAX],k;

     k=0;
     Ordenar_BMejorado(c,f,n) ;
     mostrar_datos(c,f,n) ;

     for(int i=1; i<=n; i++ ){
        //se busca una sala libre
        int j=1;
        while (j<=k && tiempo[j]>c[i]){
            j++;
        }
        if (j<=k){    //usar una sala ya utilizada
            sala[i]=j;
            tiempo[j]=f[i];

        }else{   //usar una nueva sala
             k++;
            sala[i]=k;
            tiempo[k]=f[i];
        }
     }

     cout<<endl<<"\n Solucion voraz: \n" ;
     cout << "Se usaron un total de " << k << " Salas: \n" ;
     devolver_solucion(sala, n) ;

}



int main()
{
    cout<<"\t              ALGORITMO SELECCION DE SALAS       "<< endl ;
    cout<<"\t           ---------------------------------- "<< endl ;

    int N  ;  //  numero de conferencias

    cout<<"  Inserta el numero de conferencias: ";
    cin>> N ;

    cout<<endl ;

    int c[MAX]  ; // comienzo de cada conferencia
    int f[MAX] ; //  final de cada conferencia

    leer_conferencias( c,f,N );

    Conferencias_VorazN( c,f,N ) ;

   cout<<endl;

   return 0 ;
}
