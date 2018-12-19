/*
    Supongamos que tenemos n archivos A1, A2, … An cada uno con un tamaño
    de ti Megabytes y los queremos almacenar en un dispositivo de almacenamiento
    secundario con capacidad M Megabytes.
    Si la capacidad del dispositivo de almacenamiento secundario es
    insuficiente para contener todos los archivos, resolver los siguientes problemas
    utilizando una estrategia voraz:

    a) Se desea maximizar el número de archivos almacenados en el disco.
    b) Se desea maximizar el espacio utilizado del disco.
    Para cada uno de ellos demostrar o dar un contraejemplo de si con la
    estrategia elegida se alcanza siempre la solución óptima.
 */

#include <cstdlib>
#include <iostream>
#include "time.h"

using namespace std;

//Imprime el vector de tamaños.
void imprimirTam(int vector[],int archivos){
    for(int i=0;i<archivos;i++){
         cout << vector[i] << " ";
    }
}

//Ordena el vector de tamaños de menor a mayor.
void ordenarVector(int vector[],int archivos){
    int aux;
    for(int i=0;i<archivos;i++)
        for(int j=0;j<archivos-1;j++)
            if(vector[j]>vector[j+1]){
                aux=vector[j];
                vector[j]=vector[j+1];
                vector[j+1]=aux;
            }
   // return *vector;
}

//Intenta almacenar el mayor numero de archivos.
int maximizarArchivos(int vector[],int archivos, int tamDisco){
    cout << endl << "a) Maximizando el numero de archivos"<< endl;
    int ocupado=0;//Tamaño que va a ir ocupando en el disco.
    int i=0;
    while(i<archivos && ocupado+vector[i]<=tamDisco ){
        cout << "   - "<<vector[i] << " Mb" << endl;
        ocupado = ocupado + vector[i];
        i++;
    }
    cout << "Archivos guardados: "<< i << " de " << archivos << " Espacio ocupado: " << ocupado << " Mb" << endl;
}

//Intenta ocupar el mayor espacio disponible en disco.
int maximizarDisco(int vector[],int archivos, int tamDisco){
    cout << endl << "b) Maximizando el espacio en disco"<< endl;
    int ocupado=0;//Tamaño que va a ir ocupando en el disco.
    int i=archivos,j=0;
    while(i>0){
        if(ocupado+vector[i-1]<=tamDisco){
            ocupado = ocupado + vector[i-1];
            cout << "   - "<<vector[i-1] << " Mb" << endl;
            j++;
        }
        i--;
    }
    cout << "Archivos guardados: "<< j << " de " << archivos << " Espacio ocupado: " << ocupado << " Mb" << endl;
}



int main(int argc, char** argv) {
    srand(time(0));
    int i,j,aux;
    int n = (rand()%10)+1; //Numero de archivos, (aleatorio entre 1 y 10)
    int m = (rand()%30)+1; //Capacidad del disco, (aleatorio entre 1 y 30)
    int vectTam[n]; // Vector de tamaños de N archivos.

    //Generamos el tamaño de los N archivos.
    cout << endl << "Espacio disponible en disco: " <<  m << " Mb" << endl;
    cout << endl << n << " archivos con tam: ";
    int tamTotal=0;
    for(i=0;i<n;i++){
          vectTam[i] = (rand()%9)+1; //Generamos al archivo i, un tamaño entre 1 y 9.
          tamTotal = tamTotal + vectTam[i]; //Almacenamos el tamaño total que van a tener todos nuestros archivos juntos.
    }

    //Imprimimos los N archivos con su tamaño.
    imprimirTam(vectTam,n);
    cout << endl << "Tam total: " <<  tamTotal << " Mb" << endl;
    //Ordenamos el vector
    ordenarVector(vectTam,n);
    //Comparamos los resultaos
    maximizarArchivos(vectTam,n,m);
    maximizarDisco(vectTam,n,m);

    return 0;
}

