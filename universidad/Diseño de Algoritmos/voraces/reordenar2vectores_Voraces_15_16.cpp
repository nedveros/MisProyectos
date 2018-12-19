/*
 * File:   main.cpp
 * Author: tekyl
 *
 * Created on 5 de abril de 2016, 16:56
 */

#include <iostream>
#include <stdio.h>

#define N 8


//MEJOR SOLUCION COJER EL MAS PEQUEÑO DE V1 y SE ASOCIA AL MAS PEQUQÑO DE V2,  INTERCAMBIANDO POSICIONES.
using namespace std;

void ordenar(int v[]) {

    int aux;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }

}
/*
void voraz(int v1[], int v2[]) {

    int i=0, j=0;
    int sol[] = {-1, -1, -1, -1, -1, -1, -1, -1};

    while (j != N) {
        if (i >= N) {
            j++;
        } else {
            if (v1[i] <= v2[j] && v1[i] != -1) {
                sol[j] = v1[i];
                v1[i] = -1;
                i = 0;

                j++;
            } else
                i++;
        }
    }
    // falta localizar el último y meterlo al final  sol[N-1]=
    for (int i = 0; i < N; i++) {
        cout << sol[i] << " ";
    }

}
*/

int buscaMenor(int v[], bool w[]){

    int menor=999999;
    int pmenor=-1;
    for (int i=0; i<N; i++){
        if (v[i]<menor && v[i]==0){
            menor=v[i];
            pmenor=i;
        }
    }
    return pmenor;

}

void intercambia(int v[], int p1, int p2, bool visto[]){
    int aux1;
    bool aux2;

    aux1=v[p1];
    v[p1]=v[p2];
    v[p2]=aux1;

    aux2=visto[p1];
    visto[p1]=visto[p2];
    visto[p2]=aux2;

}

void voraz(int v1[], int v2[]) {

    int i, j;
    bool visto1[] = {0,0,0,0,0,0,0,0};
    bool visto2[] = {0,0,0,0,0,0,0,0};

    for (i=0; i<N; i++) {
        int m1=buscaMenor(v1,visto1);
        int m2=buscaMenor(v2,visto2);
        intercambia (v1,m1,m2,visto1);
    }
    // falta localizar el último y meterlo al final  sol[N-1]=
    for (int i = 0; i < N; i++) {
        cout << v1[i] << " ";
    }

}


int main() {

    int v1[] = {11, 21, 1, 5, 7, 3, 12, 2}, v2[] = {7, 2, 20, 14, 11, 4, 6, 6};
    cout << endl;
    ordenar(v2);
    voraz(v1, v2);

    cout << endl;


}
