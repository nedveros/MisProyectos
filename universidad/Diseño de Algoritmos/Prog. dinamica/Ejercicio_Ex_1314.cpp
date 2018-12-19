/*
 * File:   main.cpp
 * Author: admin
 *
 * Created on 27 de abril de 2015, 9:56
 */

#include <cstdlib>
#include <iostream>
#define N 100

using namespace std;

int examen(int v[], int tam){
    int a,b;
    v[0]=0;
    v[1]=1;

    for(int n=2;n<=tam;n++){
        a=b=0;
        for(int i=0;i<n-1;i++){
            a+=v[i]*v[n-i-1];
            b+=v[i]*v[i+1];
            //cout <<a <<"," << b << endl;
        }

        v[n]=a+b;
        /*for(int k=0;k<=n;k++)
            cout << v[k] << "," ;
        cout << endl;*/
    }


    return v[tam];
}

int main(int argc, char** argv) {

    int v[N];
    int numero;

    cout<<"Introduzca valor N-esimo " <<endl;
    cin>>numero;

    cout<<"Resultado: " << examen(v, numero) << endl;
    return 0;
}

