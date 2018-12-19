/*
 * File:   main.cpp
 * Author: admin
 */

#include <cstdlib>
#include <iostream>
#include "time.h"

#define N 5

using namespace std;

void inicializar(int T[][N], int numAlumnos){
    srand(time(0));
    for(int i=0; i<numAlumnos; i++){
        for(int j=0; j<numAlumnos; j++){
            T[i][j]=(rand()%2);

        }
    }
}

// A) Minimizar reuniones
void minimizarReuniones(int T[][N], int numAlumnos, int reuniones[]){
    bool alumnosVistos[numAlumnos];

    for (int i=0; i<numAlumnos; i++)
        alumnosVistos[i]=false;

    int alumnosQuedan=numAlumnos;
    int contador;
    int reunion=1;

    while (alumnosQuedan>0){
        int max_tutoria=-1;
        int indice_tutoria=-1;

        for (int i=0; i<numAlumnos; i++){
            contador=0;
            for (int j=0; j<numAlumnos; j++){
                if (T[i][j]==1 && alumnosVistos[j]==false)
                    contador++;
            }
            if (contador>max_tutoria){
                max_tutoria=contador;
                indice_tutoria=i;
            }
        }

        for (int i=0; i<numAlumnos; i++){
            if (T[indice_tutoria][i]==1 &&alumnosVistos[i]==false){
                alumnosVistos[i]=true;
                alumnosQuedan--;
                reuniones[i]=reunion;
            }
        }
        reunion++;
    }

}


void mostrarTabla(int T[][N], int numAlumnos){
    cout<<"Tabla de Matriculas: "<<endl;
    for(int i=0; i<N; i++){
        cout<<endl;
        for(int j=0; j<N; j++)
            cout<<T[i][j]<<' ';
    }
    cout<<endl;
}


void mostrarVectorSolucion(int Sol[], int numAlumnos){

    for(int i=0; i<numAlumnos; i++){
        cout<<"Alumno "<<i+1<<": asiste a la reunion "<<Sol[i]<<endl;
    }
}


int main(){

    int T[N][N], Sol[N];

    inicializar(T,N);

    cout<<"Minimizando el tiempo total: "<<endl;
    mostrarTabla(T,N);
    minimizarReuniones(T,N,Sol);
    mostrarVectorSolucion(Sol,N);

    return 0;
}
