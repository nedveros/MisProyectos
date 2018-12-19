#include <iostream>

using namespace std;

void muestra (int *v, int ini, int fin){

    for (int i=ini; i<=fin; i++){
        cout << v[i] << ",";
    }
    cout << endl;
}


int Maximo(int a, int b){
    return (a>b?a:b);
}

int Minimo(int a, int b){
    return (a<b?a:b);
}


int Mediana2v(int *X, int *Y, int primX, int ultX, int primY, int ultY){

    int posX,posY,nitems;

    if (primX>=ultX && primY>=ultY) // caso base
        return Minimo(X[ultX],Y[ultY]);

    nitems=ultX-primX+1;
    if (nitems==2){           // 2 vectores de 2 elementos cada uno
        if (X[ultX]<Y[primY])
            return X[ultX];
        else
            if (Y[ultY]<X[primX])
                return Y[ultY];
            else
                return Maximo(X[primX],Y[primY]);
    }

    nitems=(nitems-1)/2; // caso general
    posX=primX+nitems;
    posY=primY+nitems;
    muestra(X,ultX-nitems,ultX);
    muestra(Y,primY,primY+nitems);
    if (X[posX]==Y[posY])
        return X[posX];
    else{

        if (X[posX]<Y[posY])
            return Mediana2v(X,Y,ultX-nitems,ultX,primY,primY+nitems);
       else
            return Mediana2v(X,Y,primX,primX+nitems,ultY-nitems,ultY);
    }
}

int main(){

    int N=4;
    int v[]={1,2,3,9};
    int w[]={0,6,7,8};

    cout << "Elemento Mediana de 2 vectores: " << Mediana2v(v, w, 0, N-1, 0, N-1) << endl;

return 0;
}
