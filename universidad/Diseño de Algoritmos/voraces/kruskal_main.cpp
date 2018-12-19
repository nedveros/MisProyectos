/**Kruskal
**/

#include <stdio.h>
#include <algorithm>
#include <cstring>

#define MAX 100  //maximo numero de Nodos

using namespace std;

///CONJUNTOS - DISJUNTOS

//Inicialización
void Crea_ConjDisjunto( int repre[MAX],int n ){
    for(int i=1;i<=n;++i ) repre[i]=i;
}

//Busca el representante
int Find( int repre[MAX], int x ){
    return (x==repre[x]) ? x : repre[x]=Find(repre,repre[x]);
}

//Método para unir 2 componentes conexas
void Union(int repre[MAX], int x , int y ){
    repre[Find(repre,x)] = Find(repre,y);
}

//Método que determina si 2 Nodos estan o no en la misma componente conexa
bool IgualComponente( int repre[MAX], int x , int y ){
    if( Find(repre,x) == Find(repre,y) )
            return true;
    return false;
}

//ESTRUCTURA Arista
struct Arista{
    int orig;     //Nodo orig
    int dest;    //Nodo dest
    int peso;    //Peso entre el Nodo orig y dest

    //Compara el peso de los Nodos en orden ascendente
    //Cambiar signo a > para obtener el arbol de expansion maxima
    bool operator<( const Arista &e ) const {
        return peso < e.peso;
    }
};


bool Kruskal(Arista arista[], int Nnodos, int Naristas, Arista AGM[], int &numAristas, int &total){

    //VECTOR con representantes de los nodos
    int repre[MAX];

    int orig , dest , peso;

    Crea_ConjDisjunto(repre, Nnodos );     //Inicializamos cada componente
    sort( arista , arista+Naristas);    //Ordenamos las aristas por su comparador

    for( int i=0 ; i<Naristas; i++ ){     //Recorremos las aristas ya ordenadas por peso
        orig = arista[ i ].orig;    //Nodo orig de la arista actual
        dest = arista[ i ].dest;  //Nodo dest de la arista actual
        peso = arista[ i ].peso;        //Peso de la arista actual

        //Verificamos si estan o no en la misma componente conexa
        if( !IgualComponente( repre, orig , dest ) ){  //Evito ciclos en el grafo
            total += peso;              //Incremento el peso total del AGM
            AGM[numAristas++] = arista[i];  //Agrego al AGM la arista actual
            Union( repre, orig , dest );  //Union de ambas componentes en una sola
        }
    }

    //Si el AGM encontrado no posee todos los Nodos devolvemos FALSO
    //Para saber si contiene o no todos los Nodos basta con que el numero
    //de aristas sea igual al numero de Nodos - 1
    if( Nnodos-1 != numAristas )return false; else return true;
}

int main(){
    //matriz de aristas del AGM encontrado
    Arista AGM[MAX];
    //matriz de aristas para el uso en kruskal OTRO EJEMPLO
   /* Arista arista[]={   {1, 2, 4},
                        {1, 8, 9},
                        {2, 3, 9},
                        {2, 8, 11},
                        {3, 4, 7},
                        {3, 9, 2},
                        {3, 6, 4},
                        {4, 5, 10},
                        {4, 6, 15},
                        {5, 6, 11},
                        {6, 7, 2},
                        {7, 8, 1},
                        {7, 9, 6},
                        {8, 9, 7}};
                        //matriz de aristas para el uso en kruskal */
    Arista arista[]={   {1, 2, 1},
                        {1, 4, 4},
                        {2, 3, 2},
                        {2, 4, 6},
                        {2, 5, 4},
                        {3, 5, 5},
                        {3, 6, 5},
                        {4, 5, 3},
                        {4, 7, 4},
                        {5, 7, 7},
                        {5, 6, 8},
                        {6, 7, 3}};

    //Numero de Aristas del AGM
    int numAristas=0;

    //total suma aristas
    int total=0;

    int Nnodos=7 , E=12;      //numero de Nodoss y aristas
    //Probar con 9 y 14

  /** PARA CREARLO MANUALMENTE

    printf("Introduce el nº de Nodos y Aristas\n");
    scanf("%d %d" , &Nnodos , &E );

    Creamos el grafo, almacenando las aristas en un Nnodosector
    for( int i = 0 ; i <Naristas; ++i )
        scanf("%d %d %d" , &arista[ i ].orig , &arista[ i ].dest , &arista[ i ].peso );
*/

    bool res=Kruskal(arista, Nnodos, E, AGM, numAristas, total);

    if( !res ){
        printf("No existe AGM valido para el grafo, pq no es CONEXO.\n");
    }else{
        printf( "-----El AGM encontrado contiene las siguientes aristas-----\n");
        for( int i = 0 ; i < numAristas ; ++i )
            printf("( %d , %d ): %d\n" , AGM[ i ].orig , AGM[ i ].dest , AGM[ i ].peso ); //( Nnodosertice u , Nnodosertice Nnodos ) : peso
        printf( "Coste minimo de las aristas del AGM es : %d\n" , total );
    }
    return 0;
}
