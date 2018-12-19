#include <iostream>

using namespace std;

void mostrar(int sol[], int n){
    for (int i=0;i<=n;i++){
        for (int j=1;j<=sol[i];j++){
            cout << i << ",";
        }
    }
}
void ordena_voraz(int v[], int k, int n, int sol[]){

    int i;
    //v, vector conjunto inicial
    //sol, vector solucion vacio, lo inicializamos
    for (int i=0;i<=n;i++){
        sol[i]=0;
    }
    //mientras queden elementos
    for (i=0;i<k;i++){
        //siempre es factible (ordenar)
        sol[v[i]]++;
    }
    //devuelve solución siempre (pq permite elementos repetidos
}

int main()
{
    int v[]={4,5,2,3,1,4,1};
    int n=5;  //rango maximo
    int sol[n];
    int k=7;  // numero de elementos

    ordena_voraz(v,k,n,sol);

    mostrar(sol,n);

    cout << endl;

    return 0;
}
