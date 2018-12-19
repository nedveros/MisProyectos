#include <iostream>

using namespace std;

void OrdenacionSeleccion (int v[],int tamanno){

    int i,j,posmin,min;

    for(i=0;i<=tamanno-2;i++){
        min=v[i];
        posmin=i;
        for(j=i+1;j<=tamanno-1;j++){
            if(v[j]<min){
               min=v[j];
               posmin=j;
            }
        }
        v[posmin]=v[i];
        v[i]=min;
    }
}


int BusquedaBinariaRecursiva(int x,int v[],int ini,int fin){

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
			//cout << mitad << endl;
			if(x==v[mitad]){
				return (mitad);
			}else{
				if(x<v[mitad]){
					return (BusquedaBinariaRecursiva(x,v,ini,mitad-1));
				}else{
					return (BusquedaBinariaRecursiva(x,v,mitad+1,fin));
				}
			}
		}
	}
}

int main(){

	int *v,n,x,pos,i;

    cout << "Introduzca tamaño del vector." << endl;
	cin >> n;
	v=new int [n];

	for(i=0;i<=n-1;i++){

		cout << "Introduzca el elemento " << i+1 << " del vector." << endl;
		cin >> v[i];

	}

	OrdenacionSeleccion (v,n);

    for(i=0;i<=n-1;i++){
		cout << v[i] << ", ";
	}

	cout << endl << "Introduzca el elemento a buscar." << endl;
	cin >> x;

	pos=BusquedaBinariaRecursiva(x,v,0,n-1);

	if(pos==-1){
		cout << "El elemento no se encuentra en el vector." << endl;
	}else{
		cout << "El elemento se encuentra en la posición. " << pos+1 << endl;
            // posiciones desde 1
	}

	delete [] v;

	return 0;

}
