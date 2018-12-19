#include <iostream>
#define umbral 2

using namespace std;

 void burbuja(int *T, int primero, int ultimo){
 int i, j;
 int aux;
 for (i = primero; i <ultimo; i++)
	 for (j = primero; j <=i; j++)
		 if (T[j] >T[j+1]){
            aux = T[j];
            T[j] = T[j+1];
            T[j+1] = aux;
         }
 }

 void muestra (int *v, int tam){

    for (int i=0;i<tam;i++)
        cout << v[i] << ", ";
    cout <<endl;
}


void Mezcla ( int primero, int ultimo, int centro, int *v ) {

    int x, y, z;
    int *aux;
    x = primero;
    y = centro+1;
    z = x;
    //aux = (int *) malloc (((ultimo+1)*8) * sizeof( int ));
    aux=new int[(ultimo+1)];
    while (( x <= centro ) && ( y <= ultimo )) {

       if ( v[x] <= v[y] ) {
          aux[z] = v[x];
          x++;
       } else {
              aux[z] = v[y];
              y++;
       }
       z++;

    }

    while ( x <= centro ) {
       aux[z] = v[x];
       x++;
       z++;
    }

    while ( y <= ultimo ) {
       aux[z] = v[y];
       y++;
       z++;
    }

    for ( x = primero; x <= ultimo; x++ ) {
        v[x] = aux[x];
    }

    //free ( aux );
    delete [] aux;

}

/*----------------------------------------------------------*/

void Mergesort ( int primero, int ultimo, int *v ) {

    int centro;


    if ( ultimo-primero+1 <= umbral ) {
            burbuja(v, primero, ultimo);
    }else{
       centro = ( primero + ultimo ) / 2;

       Mergesort ( primero, centro, v );
       Mergesort ( centro+1, ultimo, v );
       Mezcla ( primero, ultimo, centro, v );

    }

}

int main(){

    int v[]={3, 8, 1, 9, 5, 4, 3, 8, 10};

    cout<<"original: ";
    muestra (v,9);

    Mergesort(0,8,v);

    muestra (v,9);


    return 0;

}




