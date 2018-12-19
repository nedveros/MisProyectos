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


int BuscBin3(int v[],int ini,int fin, int x){

int p; /* 1/3 del numero de elementos */

    if (ini>fin)
        return -1;
    else
        if(ini==fin){
			if(x==v[ini]){
				return (ini);
			}else{
				return (-1);
			}
        }
        p=(fin-ini+1)/3;//(fin-ini+1)/3;

        if (x==v[ini+p])
            return ini+p;
        else
            if (x==v[fin-p])
                return fin-p;
            else
                if (x<v[ini+p])
                    return BuscBin3(v,ini,ini+p-1,x);
                else
                    if (x<v[fin-p]){
                        return BuscBin3(v,ini+p+1,fin-p-1,x);
                    }else
                        return BuscBin3(v,fin-p+1,fin,x);
}
/*	int mitad;

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
*/
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

	pos=BuscBin3(v,0,n-1,x);

	if(pos==-1){
		cout << "El elemento no se encuentra en el vector." << endl;
	}else{
		cout << "El elemento se encuentra en la posición. " << pos+1 << endl;
            // posiciones desde 1
	}

	delete [] v;

	return 0;

}
