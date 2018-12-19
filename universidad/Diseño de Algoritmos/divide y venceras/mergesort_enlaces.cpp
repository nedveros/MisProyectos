#include <iostream>
#define umbral 2

using namespace std;



 void muestra (int *v, int tam){

    for (int i=0;i<tam;i++)
        cout << v[i] << ", ";
    cout <<endl;
}


void Mezcla_enlaces( int *V, int *enlaces, int p1, int p2, int &p) {

    int i, j, k;
    int *aux;
    i = p1;
    j = p2;
    k = 0;

    while (( i != 0 ) && ( j != 0 )) {

       if ( V[i] <= V[j] ) {
          enlaces[k] = i;
          k=i;
          i=enlaces[i];
       } else {
          enlaces[k] = j;
          k=j;
          j=enlaces[j];
       }
    }
    if (i==0)
        enlaces[k]=j;
    else
        enlaces[k]=i;
    p=enlaces[0];

}

/*----------------------------------------------------------*/

void Mergesort_enlaces( int *V, int *Enlaces, int c, int f, int &p) {

    int m,p1,p2;

    if ( c==f ) {
            p=c;
    }else{
        if (c<f){
           m = ( c + f ) / 2;

           Mergesort_enlaces ( V, Enlaces, c, m, p1 );
           Mergesort_enlaces ( V, Enlaces, m+1, f, p2 );
           Mezcla_enlaces ( V, Enlaces, p1, p2, p );

        }
    }
}

int main(){

    int v[]={0, 8, 1, 9, 5, 4, 3, 8, 10};
    int e[]={0, 0, 0, 0, 0, 0, 0, 0, 0};
    int p;

    Mergesort_enlaces(v,e,1,8, p);

    cout << "primero:" << p << endl;
    cout << "Posic:    0  1  2  3  4  5  6  7  8"<<endl;
    cout << "vector e: ";
    muestra (e,9);
    cout << "original: ";
    muestra (v,9);

    return 0;

}




