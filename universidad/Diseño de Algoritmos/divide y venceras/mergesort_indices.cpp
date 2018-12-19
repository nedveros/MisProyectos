#include <iostream>

using namespace std;



 void muestra (int *v, int tam){

    for (int i=0;i<tam;i++)
        cout << v[i] << ", ";
    cout <<endl;
}


void Mezcla_indices( int *V, int *I, int c, int m, int f) {

    int i, j, k;
    int *aux;
    i = c;
    j = m+1;
    k = c;
    //aux = (int *) malloc (((ultimo+1)*8) * sizeof( int ));
    aux=new int[(f+1)];
    while (( i <= m ) && ( j <= f )) {

       if ( V[I[i]] <= V[I[j]] ) {
          aux[k] = I[i];
          i++;
       } else {
          aux[k] = I[j];
          j++;
       }
       k++;
    }

    while ( i <= m ) {
       aux[k] = I[i];
       i++;
       k++;
    }

    while ( j <= f ) {
       aux[k] = I[j];
       j++;
       k++;
    }

    for ( i = c; i <= f; i++ ) {
        I[i] = aux[i];
    }

    //free ( aux );
    delete [] aux;

}

/*----------------------------------------------------------*/

void Mergesort_indices( int *V, int *Indices, int c, int f) {

    int m;

    if ( c==f ) {
            Indices[c]=c;
    }else{
        if (c<f){
           m = ( c + f ) / 2;

           Mergesort_indices ( V, Indices, c, m );
           Mergesort_indices ( V, Indices, m+1, f );
           Mezcla_indices ( V, Indices, c, m, f );

        }
    }
}

int main(){

    int v[]={3, 8, 1, 9, 5, 4, 3, 8, 10};
    int i[9];
    cout<<"original: ";
    muestra (v,9);

    Mergesort_indices(v,i,0,8);

    cout << "vector indices: ";
    //muestra (v,9);
    muestra (i,9);


    return 0;

}




