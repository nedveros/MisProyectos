#include <iostream>

using namespace std;

bool Solucion (int v[], int n, int total){
    int s=0, i;

    for (i=0;i<n;i++){
        s+=v[i];
    }
    return s==total;
}

int Seleccion (int v[], int p){
    return (v[p]);
}

bool Factible (int v[], int n, int nueva, int total){
    int s=nueva, i;

    for (i=0;i<n;i++){
        s+=v[i];
    }
    return s<=total;
}

bool Monedas_voraz (int monedas[], int n, int total, int cambio[], int &t){
    int i,x,m=0;

    t=0;
    for (i=0;i<n;i++){
        cambio[i]=0;
    }

    while (!Solucion(cambio,t,total) && m!=n){
        x=Seleccion(monedas,m);
        m++;

        if (Factible(cambio,t,x,total)){
            cambio[t]=x;
        }
        t++;
    }
    if (Solucion(cambio,t,total))
        return true;
    else
        return false;
}

int main()
{
    int cambio[4];
    int monedas[]={50,25,5,1};
    int n=4;
    int total=31;
    int t;

    bool res = Monedas_voraz (monedas, n, total, cambio, t);
    if (res){
        cout << "Cambio justo" << endl;

    }else {
        cout << "Cambio aproximado:" << endl;
    }
    for (int i=0; i<t; i++)
       cout << "1 Moneda de " << cambio[i] << endl;
    return 0;
}
