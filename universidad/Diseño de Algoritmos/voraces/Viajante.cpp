#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAXINT 10000

#define MAX 100

using namespace std;

/**Se conocen las distancias entre un cierto número de ciudades. Un viajante debe, a
partir de una de ellas, visitar cada ciudad exactamente una vez y regresar al punto
de partida habiendo recorrido en total la menor distancia posible.
Este problema también puede ser enunciado más formalmente como sigue: dado
un grafo g conexo y ponderado y dado uno de sus vértices v0, encontrar el ciclo
Hamiltoniano de coste mínimo que comienza y termina en v0.
Para intentar solucionarlo mediante un algoritmo voraz, plantear la
siguiente estrategia:
-- Sea (C,v) el camino construido hasta el momento que comienza en v0 y termina
en v. Inicialmente C es vacío y v = v0. Si C contiene todos los vértices de g, el
algoritmo incluye el arco (v,v0) y termina. Si no, incluye el arco (v,w) de
longitud mínima entre todos los arcos desde v a los vértices w que no están en el
camino C..*/

void muestra (bool v[][MAX], int tam){
    //int k=1;
     for (int i=0; i<=tam; i++){
         for (int j=0; j<=tam; j++){
            if (v[i][j])
                cout << "X ";
            else
                cout <<  "   ";
            //k++;
        }
        cout << endl;
    }
}


void InicSol(bool v[][MAX], int tam){
    for (int i=0; i<=tam; i++){
         for (int j=0; j<=tam; j++){
                v[i][j]=false;
         }
    }
}


int Busca(int g[][MAX], int vertice, bool yaesta[MAX], int n){
    int mejorvertice,i,min;

    mejorvertice=1; min=MAXINT;
    for (int i=1; i<=n; i++){
        if (i!=vertice && !yaesta[i] && g[vertice][i]<min){
            min=g[vertice][i];
            mejorvertice=i;
        }
    }
    return mejorvertice;
}


//PROGRAMA*****************************

void Viajante( int g[][MAX], int n, bool sol[][MAX]){
    // supone que el recorrido comienza en el vertice 1
    bool yaesta[MAX];
    int i,verticeencurso,verticeanterior;

    InicSol(sol,n);
    for (int i=1; i<=n; i++)
        yaesta[i]=false;
    verticeencurso=1;
    for (int i=1; i<=n; i++) {
        verticeanterior=verticeencurso;
        yaesta[verticeanterior]=true;
        verticeencurso=Busca(g,verticeencurso,yaesta,n);
        cout << verticeanterior << "-" << verticeencurso << endl;
        sol[verticeanterior][verticeencurso]=true;
    }
}

int main()
{

   int n=6;  //puntos

   bool sol[MAX][MAX];

    //matriz del GRAFO         2   3   4  5  6
int grafo[MAX][MAX]={{-1, -1, -1, -1, -1,-1, -1},
                     {-1,  0, 3, 10, 11, 7, 25}, //1
                     {-1,  0, 0,  6, 12, 8, 26}, //2
                     {-1,  10, 0, 0,  9,  4, 20},  //3
                     {-1,  11, 8, 0,  0,  5, 15},  //4
                     {-1,  7, 26, 20,  0,  0, 18}   //5

                    };


   Viajante( grafo, n, sol);

   muestra(sol,n);

   return 0;
}
