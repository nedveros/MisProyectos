#include <iostream>
#define MAX 10000

/** Ejemplo de ejecucion para 3 Monedas(1,4,6) y Un Cambio de 8
 	    0	MAX MAX MAX MAX MAX MAX MAX
m1=1 	0 	2 	3 	4 	5 	6 	7 	8
m2=4 	0 	2 	3 	1 	2 	3 	4 	2
m3=6 	0 	2 	3 	1 	2 	1 	2 	2
*/

using namespace std;

void mostrar(int T[][100]){
    int i,j;
    for (i=0; i<=3; i++){
            for (j=0; j<=8; j++){
                    cout << T[i][j] << "  ";
            }
            cout << endl;
    }

}


int cambio (int C, int n, int M[]){
    int i,j;
    int T[n+1][C+1];
    int seleccion[n+1];

       for (i=1; i<=C; i++) {T[0][i]= MAX;};
       for (i=0; i<=n; i++) {T[i][0]= 0;};
       for (i=1; i<=n; i++){
            for (j=1; j<=C; j++){
                if (M[i] > j) {
                        T[i][j] = T[i-1][j];
                }else{
                        if (T[i-1][j]< T[i][j-M[i]]+1){
                            T[i][j]= T[i-1][j];
                        }else{
                            T[i][j]= T[i][j-M[i]]+1;
                        }
                }
            }
       }
//MOSTRAR
   for (i=0; i<=3; i++){
            for (j=0; j<=17; j++){
                    cout << T[i][j] << "  ";
            }
            cout << endl;
    }

       for(i = 0; i<=n; i++)
            seleccion[i]=0;
        i= n;
        j= C;
        while(j>0){
            if(i>1 && T[i][j]==T[i-1][j]){
                i--;
            }else{
                seleccion[i]++;
                j-=M[i];
            }
        }
       for (int i=1; i<=n;i++){
            if (seleccion[i]!=0)
                cout << "\nMonedas de Cantidad: " << M[i] << " --> " << seleccion[i] << endl;
       }
       cout << "\nNumero de monedas: " << T[n][C] << endl;
       cout << "\nCambio devuelto: " << C << endl;

}



int main(){

    int Cant=17;
    int nMod=3;
    int M[]={0,1,4,6};

    cambio ( Cant, nMod, M);

    return 0;
}
