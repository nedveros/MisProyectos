#include <iostream>
#define N 6
using namespace std;

int Maximo(int a, int b){
    return (a>b?a:b);
}


int Sumamax(int a[], int prim, int ult){
 int mitad,i,max_izq,max_der,suma,max_aux;

 // casos base
    if (prim>ult) return 0;
    if (prim==ult) return Maximo(0,a[prim]);
    mitad=(prim+ult)/ 2;
 // casos 1 y 2
    max_aux=Maximo(Sumamax(a,prim,mitad),Sumamax(a,mitad+1,ult));
 // caso 3: parte izquierda
    max_izq=0;
    suma=0;
    cout << prim <<";" << mitad <<  ";" << ult << endl;
    for (i=mitad;i>=prim;i--){
        suma=suma+a[i];
        max_izq=Maximo(max_izq,suma);
    }
 // caso 3: parte derecha
    max_der=0;
    suma=0;
    for (i=mitad+1;i<=ult;i++){
        suma=suma+a[i];
        max_der=Maximo(max_der,suma);
    }
    cout << max_izq << "," << max_der << "," << max_aux << endl;
 //combinacion de resultados
    return Maximo(max_der+max_izq,max_aux);
}


int main()
{
    int v[]={-2,11,-4,13,-5,-2};

    cout << "Secuencia Suma Maxima:" << Sumamax(v,0,N-1) << endl;

    return 0;
}
