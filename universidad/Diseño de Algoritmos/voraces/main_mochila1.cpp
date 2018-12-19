#include <iostream>

using namespace std;

void Mochila (int valor[], int peso[], int n, int total, float sol[],float &benef){
    int j,i=0, peso_ac=0;

    for (j=0;j<n;j++){
        sol[j]= 0;
    }
    benef=0.0;
    while (peso_ac<total){
        if (peso[i] + peso_ac < total) {
            benef=benef + valor [i];
            sol[i]=1;
            peso_ac+=peso [i];
        }else{
            sol[i]=(float)(total-peso_ac)/peso[i];
            peso_ac=total;
            benef= benef +(valor[i] * sol[i]);
        }
        i++;
    }
}

int main()
{
    float solucion[]={0.0,0.0,0.0,0.0};
    int ganancia[]={50,40,30,1};
    int peso[]={40,10,20,40};
    int n=4;
    int total=100;
    float ben;

    Mochila (ganancia,peso,n,total,solucion, ben);

    cout << "Beneficio obtenido:" << ben << endl;

    for (int i=0; i<n; i++){
        cout << "Objeto seleccionados: " << solucion[i] << endl;
    }
    return 0;
}
