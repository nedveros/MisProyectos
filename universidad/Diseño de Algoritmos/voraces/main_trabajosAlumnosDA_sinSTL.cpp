/*
 * File:   main_trabajosAlumnosDA.cpp
 * Author: Maria
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "time.h"

#define N 10

using namespace std;

int T[N][N];
int E[N][N];
int vecT[N];
int vecE[N];

void inicializar(){
    srand(time(0));
    for(int i=0; i<N; i++){
        vecT[i]=-1;
        vecE[i]=-1;
        for(int j=0; j<N; j++){
            T[i][j]=(rand()%10)+1;
            E[i][j]=(rand()%10)+1;
        }
    }
}

// A) Minimizar tiempos
void minimizarTiempos(){
  for(int i=0; i<N; i++){
        bool enc=false;
        int j;
        for(j=0; j<N && !enc; j++){
             bool e=false;
             for(int k=0; k<N; k++){
                if(vecT[k]==j){
                    e=true;
                }
             }
             if (!e){
                vecT[i]=j;
                enc=true;
             }
        }

        for(int k=j+1; k<N; k++){
            bool e=false;
            for(int l=0; l<N; l++){
                if(vecT[l]==k){
                    e=true;
                }
            }
            if(!e && T[i][k]<T[i][vecT[i]]){
                    vecT[i]=k;
            }
        }
    }
}

// B) Maximizar eficacia
void maximizarEficacia(){
    for(int i=0; i<N; i++){
        bool enc=false;
        int j;
        for(j=0; j<N && !enc; j++){
             bool e=false;
             for(int k=0; k<N; k++){
                if(vecE[k]==j){
                    e=true;
                }
             }
             if (!e){
                vecE[i]=j;
                enc=true;
             }
        }

        for(int k=j+1; k<N; k++){
            bool e=false;
            for(int l=0; l<N; l++){
                if(vecE[l]==k){
                    e=true;
                }
            }
            if(!e && E[i][k]>E[i][vecE[i]]){
                    vecE[i]=k;
            }
        }
    }
}

void mostrarTablaTiempos(){
    cout<<"Tabla de tiempos: "<<endl;
    for(int i=0; i<N; i++){
        cout<<endl;
        for(int j=0; j<N; j++)
            cout<<T[i][j]<<' ';
    }
    cout<<endl;
}

void mostrarTablaEficacias(){
    cout<<"Tabla de eficacias: "<<endl;
    for(int i=0; i<N; i++){
        cout<<endl;
        for(int j=0; j<N; j++)
            cout<<E[i][j]<<' ';
    }
    cout<<endl;

}

void mostrarVectorTiempos(){
    int tiempo=0;
    for(int i=0; i<N; i++){
        tiempo+=T[i][vecT[i]];
        cout<<"Alumno "<<i+1<<": asignado el trabajo "<<vecT[i]+1
            <<" y con duracion "<<T[i][vecT[i]]<<endl;
    }
    cout<<endl<<"Tiempo total: "<<tiempo<<endl;
}

void mostrarVectorEficacias(){
    int eficacia=0;
    for(int i=0; i<N; i++){
        eficacia+=E[i][vecE[i]];
        cout<<"Alumno "<<i+1<<": asignado el trabajo "<<vecE[i]+1
            <<" y con eficacia "<<E[i][vecE[i]]<<endl;
    }
    cout<<endl<<"Eficacia total: "<<eficacia<<endl;
}

int main(){
    inicializar();
    cout<<"Minimizando el tiempo total: "<<endl;
    mostrarTablaTiempos();
    minimizarTiempos();
    mostrarVectorTiempos();
    cout<<"Maximizar la eficiencia total: "<<endl;
    mostrarTablaEficacias();
    maximizarEficacia();
    mostrarVectorEficacias();
    return 0;
}

