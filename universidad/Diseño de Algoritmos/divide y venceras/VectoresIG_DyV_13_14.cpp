#include <iostream>

#define TAM 12  //modificar para probar otros numeros

using namespace std;
int Vectores(int v[], int w[], int inf, int sup){

 // casos base
    if (sup==inf){
        if (v[inf]==w[sup] && sup==TAM-1)
            return -1;
        if (v[inf]==w[sup] && v[inf+1]!=w[inf+1]){
            return inf+1;
        }else {
            return inf;
        }
    }else{
        int  mitad=(inf+sup)/2;
        if (v[mitad]==w[mitad]){
            return Vectores(v,w,mitad+1,sup);
        }else{
            return Vectores(v,w,inf,mitad);
        }
    }
}
/*
int Vectores(int v[], int w[], int inf, int sup){

 // casos base
    if (sup==inf){
        if (v[inf]==w[inf]  ){
            return -1;
        }else {
            if (inf!=0)
                return inf;
            else
                return 0;
        }
    }else{
        int  mitad=(inf+sup)/2;
        if (v[mitad]==w[mitad]){
            if (v[mitad+1]!=w[mitad+1])
                return mitad+1;
            return Vectores(v,w,mitad+1,sup);
        }else{
            return Vectores(v,w,inf,mitad);
        }
    }
}
*/
int main()
{
    int v[]={2,3,8,4,5,6,9,1,3,5,1,8};
    int w[]={2,3,8,4,5,6,9,1,3,5,1,8};

    int pos =Vectores(v,w,0,TAM-1);
    if (pos==-1){
        cout << " los vectores son iguales";
    } else{
        cout << "Los vectores son distintos desde la posicion: "<< pos+1<< endl;
    }

    return 0;
}
