/*
 * main.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//tb serviría para calcular la moda estadística
int mayoritario(const int v[], int ini, int fin, int& mayor){

	if(ini==fin){
		mayor=v[ini];
		return 1;
	}else{
		int m=(fin+ini)/2, may1, may2;
		int cont1=mayoritario(v, ini, m, may1);
		int cont2=mayoritario(v, m+1, fin, may2);
		cout << cont1 << "," << cont2 << "--" << may1 << "," << may2 << endl;
		if(may1==may2){
			mayor=may1;
			return cont1+cont2;
		}else
            if(cont1 > cont2){
                mayor=may1;
                return cont1-cont2;
            }else{
                mayor=may2;
                return cont2-cont1;
            }
	}

	return 1;
}

bool comprueba(const int v[], const int tam, const int mayor){
	int cont=0;
	for(int i=0;i<=tam;i++){
		if(v[i]==mayor)
			cont++;
	}
	return(cont>(tam/2));
}

int main(){

	int v[]={2,1,2,2,2,3,3};
	int mayor;
    mayoritario(v,0,6,mayor);

	if(comprueba(v,4,mayor))
		cout<<"El mayoritario es: "<<mayor <<endl;
	else
		cout<<"No existe mayoritario."<<endl;
	return 0;
}
