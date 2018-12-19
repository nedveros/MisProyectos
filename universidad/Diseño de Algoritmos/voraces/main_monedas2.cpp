#include <iostream>

using namespace std;

bool Monedas_voraz2 (int valor[], int monedas[], int n, int total, int cambio[]){
   int i=0;
   //inicializamos el cambio
   for (int j=0;j<n;j++){
        cambio[j]=0;
   }
   //Comprobamos si es solución y factible
   while (total > 0 && i < n) {
        //comprobamos factibilidad y objetivo
       if (valor[i] <= total && monedas[i]>0){
           //cojemos moneda seleccionada
              monedas[i] =monedas[i]-1;
              cambio[i] =cambio[i]+1;
              total =total-valor[i];
       }else{
           //intentamos con siguiente moneda
              i++;
       }
   }
   //Si es solución
   if (total>0) return false; else return true;
}

int main()
{
    int cambio[4];
    int monedas[]={50,25,5,1};
    int cantidad[]={3,4,0,6};
    int n=4;
    int total=30;

    bool res = Monedas_voraz2 (monedas,cantidad,n,total,cambio);
    if (res){
        cout << "Cambio justo" << endl;

    }else {
        cout << "Cambio erroneo" << endl;
    }
    for (int i=0; i<4; i++){
        cout << "Monedas de " << monedas[i] << ":" << cambio[i] << endl;
    }
    return 0;
}
