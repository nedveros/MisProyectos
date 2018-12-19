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


int BusquedaBinariaRecursivaNoCentrada(int x,int v[],int ini,int fin){
	int tercio;

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
			tercio=ini+(fin-ini+1)/3;
			if(x==v[tercio]){
				return(tercio);
			}else{
				if(x<v[tercio]){
					return (BusquedaBinariaRecursivaNoCentrada(x,v,ini,tercio-1));
				}else{
					return(BusquedaBinariaRecursivaNoCentrada(x,v,tercio+1,fin));
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

	cout << "Introduzca el elemento a buscar." << endl;
	cin >> x;

	pos=BusquedaBinariaRecursivaNoCentrada(x,v,0,n-1);

	if(pos==-1){
		cout << "El elemento no se encuentra en el vector." << endl;
	}else{
		cout << "El elemento se encuentra en la posición. " << pos+1 << endl;
            // posiciones desde 1
	}

	delete [] v;

	return 0;

}
