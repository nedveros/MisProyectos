#include <iostream>
#include "time.h"
#include "stdlib.h"

#define MAX 10

using namespace std;

/**Un camionero conduce desde Bilbao a Málaga siguiendo una ruta dada y llevando
un camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin
parar. El camionero dispone de un mapa de carreteras que le indica las distancias
entre las gasolineras que hay en su ruta. Como va con prisa, el camionero desea
pararse a repostar el menor número de veces posible.
Deseamos diseñar un algoritmo ávido para determinar en qué gasolineras tiene
que parar y demostrar que el algoritmo encuentra siempre la solución óptima.*/

void muestra (bool *v, int tam){

    for (int i=0;i<tam;i++)
        if (v[i])
            cout << "Para en: " << i << endl;

}

//PROGRAMA*****************************

void Gasofa(int n, int d[],int t, bool s[]){
int i,numkilometros;

for (i=0; i<t ; i++)
    s[i]=false;
i=0;
numkilometros=0;
do{
    do{
        i++;
        numkilometros=numkilometros+d[i];
    }while (numkilometros<=n && i!=t);

    if (numkilometros>n){ // si nos hemos pasado...
        i--; // volvemos atras una gasolinera
        s[i]=true;  // y repostamos en ella.
        numkilometros=0;  //reset contador
    }
}while (i!=t);
}

int main()
{
   //srand(time(0));
   int n = 60;  //km sin repostar

   int km_ciudades[]={0,50,40,60,10,40};
   bool sol[MAX];
   int n_ciu=6;

   Gasofa(n, km_ciudades, n_ciu, sol);

   muestra(sol,n_ciu);


    return 0;
}

