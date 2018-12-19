#include <iostream>

#define TAM 10

using namespace std;

void Mochila (int valor[], int peso[], int n, int total, float sol[],float &benef){
    int j,i=0, peso_ac=0;

    for (j=0;j<n;j++){
        sol[j]= 0.0;
    }
    benef=0.0;
    while (peso_ac<total && i<n){
        if (peso[i] + peso_ac <= total) {
            benef=benef + valor [i];
            sol[i]=1.0;
            peso_ac+=peso [i];
        }else{
            sol[i]=(float)(total-peso_ac)/peso[i];
            peso_ac+= (peso [i] * sol[i]);
            //tb peso_ac=total,  pq va a finalizar ya que no cabe más !!
            benef= benef +(valor[i] * sol[i]);
        }
        i++;
    }
}

int main()
{
    float solucion[TAM];
    //la proporcion gan/peso ya esta ordenada decrecientemente
    int ganancia[]={50,40,30,1};
    int peso[]={10,20,30,40};
    int n=4;
    int total=80;
    float ben;

    Mochila (ganancia,peso,n,total,solucion, ben);

    cout << "Beneficio obtenido:" << ben << endl;

    for (int i=0; i<n; i++){
        cout << "Objeto seleccionado: " << solucion[i] << endl;
    }
    return 0;
}
