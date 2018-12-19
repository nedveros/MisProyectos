/*
 * main.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
/*
1) En primer lugar, el caso base de la recursión ocurre cuando disponemos de un
vector con uno o dos elementos. En este caso existe elemento mayoritario si los
elementos del vector son iguales.
2) Si el número de elementos n del vector es impar y mayor que 2, aplicaremos la
idea anterior para el subvector compuesto por sus primeros n–1 elementos.
Como resultado puede que obtengamos que dicho subvector contiene un
candidato a elemento mayoritario, con lo cual éste lo será también para el vector
completo. Pero si la búsqueda de candidato para el subvector de n–1 elementos
no encuentra ninguno, escogeremos como candidato el n-ésimo elemento.
//La función BuscaCandidato intenta encontrar un elemento mayoritario:*/

bool BuscaCandidato(int a[],int prim,int ult,int &candidato){
int i,j;

    candidato=a[prim];
    if (ult<prim) return false; // casos base
    if (ult==prim) return true;
    if (prim+1==ult){
        candidato=a[ult];
        return (a[prim]==a[ult]);
    }
    j=prim; // caso general
    if (((ult-prim+1)% 2)==0){ // n par
        for (i=prim+1;i<ult;i=i+2){
            if (a[i-1]==a[i]){
                a[j]=a[i];
                j++;
            }
        }
        return BuscaCandidato(a,prim,j-1,candidato);
    }else{   // n impar
        for (i=prim;i<ult-1;i=i+2){
            if (a[i]==a[i+1]) {
                    a[j]=a[i];
                    j++;
            }
        }
        if (!BuscaCandidato(a,prim,j-1,candidato)){
            candidato=a[ult];
        }
        return true;
    }
}


//tb serviría para calcular la moda estadística
bool Mayoritario2(int a[], int prim, int ult, int &candidato){


/* comprueba si a[prim..ult] contiene un elemento mayoritario */
int suma,i;

    suma =0;
    if (BuscaCandidato(a,prim,ult,candidato)){
    // comprobacion de si el candidato es o no mayoritario
    for(i=prim;i<ult;i++){
      if (a[i]==candidato){
                suma++;

        }
    }
    return (suma>((ult-prim+1)/2));
    }
}



int main(){

	int v[]={1,1,2,7,2,2,3};
	int mayor;

	if(Mayoritario2(v,0,6,mayor))
		cout<<"El mayoritario es: "<<mayor <<endl;
	else
		cout<<"No existe mayoritario."<<endl;
	return 0;
}
