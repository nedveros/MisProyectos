/**Prim
**/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAX 100  //maximo numero de Nodos
#define MAXINT 99999999L
using namespace std;


//ESTRUCTURA Arista
struct Arista{
    int orig;     //Nodo orig
    int dest;    //Nodo dest
    int peso;    //Peso entre el Nodo orig y dest

   /* //Compara el peso de los Nodos en orden ascendente
    //Cambiar signo a > para obtener el arbol de expansion maxima
    bool operator<( const Arista &e ) const {
        return peso < e.peso;
    } */
};

/*void mostrar(int v[], int Nnodos){

    for (int i=1; i<=Nnodos; i++){
        cout << v[i] << " ";
    }
cout << endl;
}
*/
void Prim(int L[][MAX], int Nnodos, Arista AGM[], int &nAristas, int &total){

    int k, min;
    int mascerca[MAX];
    int mindist[MAX];
    Arista arista;

    nAristas=0;

    for(int i=2;i<=Nnodos;i++){
        mascerca[i]=1;
        mindist[i]=L[i][1];
    }

     for (int i=2; i<=Nnodos; i++){
        min=MAXINT;
        for (int j=2;j<=Nnodos;j++){
            if (mindist[j]>=0 && mindist[j]<min){
                min=mindist[j];
                k=j;
            }
        }
        total += min;
        arista.peso=L[k][mascerca[k]];
        arista.orig=k;
        arista.dest=mascerca[k];
        AGM[nAristas++] = arista;
        mindist[k]=-1;
        for (int j=2;j<=Nnodos;j++){
            if (L[k][j]<mindist[j]){
                    mindist[j]=L[k][j];
                    mascerca[j]=k;
            }
        }
    }

}


int main(){
    //matriz de aristas del AGM encontrado
    Arista AGM[MAX];
    //matriz de aristas para el uso en kruskal
    int L[MAX][MAX]={{-1,-1,-1,-1,-1,-1,-1,-1},
                     {-1, 0, 1,MAXINT, 4,MAXINT,MAXINT,MAXINT},  //1
                     {-1, 1, 0, 2, 6, 4,MAXINT,MAXINT},  //2
                     {-1,MAXINT, 2, 0,MAXINT, 5, 5,MAXINT},  //3
                     {-1, 4, 6,MAXINT, 0, 3,MAXINT, 4}, //4
                     {-1,MAXINT, 4, 5, 3, 0, 8, 7},  //5
                     {-1,MAXINT,MAXINT, 5,MAXINT, 8, 0, 3}, //6
                     {-1,MAXINT,MAXINT,MAXINT, 4, 7, 3, 0} //7
                    };

    //Numero de Aristas del AGM
    int nAristas=0;

    //total suma aristas
    int total=0;

    int Nnodos=7;      //numero de Nodoss y aristas
    //Probar con 9 y 11

  /** PARA CREARLO MANUALMENTE

    printf("Introduce el nº de Nodos y Aristas\n");
    scanf("%d %d" , &Nnodos , &E );

    Creamos el grafo, almacenando las aristas en un Nnodosector
    for( int i = 0 ; i <Naristas; ++i )
        scanf("%d %d %d" , &arista[ i ].orig , &arista[ i ].dest , &arista[ i ].peso );
*/

    Prim(L,Nnodos,AGM,nAristas,total);


        printf( "-----El AGM encontrado contiene las siguientes aristas-----\n");
        for( int i = 0 ; i < nAristas ; ++i )
            printf("( %d , %d ): %d\n" , AGM[ i ].orig , AGM[ i ].dest , AGM[ i ].peso ); //( Nnodosertice u , Nnodosertice Nnodos ) : peso
        printf( "Coste minimo de las aristas del AGM es : %d\n" , total );

    return 0;
}
