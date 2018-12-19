#include <iostream>
#include <algorithm>
#include <vector>

/*Dado un vector V de n enteros distintos, y un nº S, determinar si existen y
cuales son 2 numeros en el vector que sumados, den el valor S
solución: 1º se ordena por quicksort y despues se aplica BusBinaria.
Evidentemente nos tendrían que facilitar el quicksort por cuestion de tiempo!!
o llamamos a sort de C++ q hace lo mismo.
Y el BusqBinaria podríamos hacerlo "nosotros". :)
*/

#define umbral 2  //umbral de Quicksort

using namespace std;





int BusquedaBinariaRecursiva(int x,vector<int> v,int ini,int fin){

	int mitad;
	if(ini>fin){
		return (-1);
	}else{
		if(ini==fin){
			if(x==v[ini]){
				return (ini);
			}else{
				return (-1);
			}
		}else{

			mitad=(ini+fin)/2;
			if(x==v[mitad]){
				return(mitad);
			}else{
				if(x<v[mitad]){
					return (BusquedaBinariaRecursiva(x,v,ini,mitad-1));
				}else{
					return(BusquedaBinariaRecursiva(x,v,mitad+1,fin));
				}
			}
		}
	}
}


//Este módulo no es recursivo pero es una aplicación
//muy buena del busqueda binaria. ;)
bool BuscaSuma2(vector<int> v, int S, int &x1, int &x2){
 int res;

 sort(v.begin() ,v.end()); //ordenamos vector
 int j=0;
 bool existe=false;
 while (j<v.size() && !existe){
     x1=v[j];
     x2=S-x1;  //buscamos x2 en v, que es el que nos falta para cumlpir objetivo

     res=BusquedaBinariaRecursiva(x2,v,0,v.size()-1 );

     if (res!=-1 && res!=j) //si lo encuentra y no es el mismo repetido
        existe=true;
     j++;
 }
 return existe;
}

int main()
{
    int S=15;
    int x1,x2;
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    v.push_back(12);
    v.push_back(6);

    cout << "valor buscado: " << S << endl;
    if (BuscaSuma2(v,S,x1,x2))
        cout << "Numero encontrados:" << x1 << ", " << x2 << endl;
    else
        cout << "No existen dichos numeros" << endl;
    return 0;
}
