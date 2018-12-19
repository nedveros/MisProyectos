#include <iostream>
#define MAX 10000


/** Ejemplo de ejecucion para 3 sellos(1,4,6) y Un Cambio de 8
        1 	2 	3 	4 	5 	6 	7 	8
        0   0   0   0   0   0   0   0
m1=1 1	1 	1 	1 	1 	1 	1 	1 	1
m2=4 1	1 	1 	1 	2 	2 	2 	2 	3
m3=6 1	1 	1 	1 	2 	2 	3 	3 	4
*/

using namespace std;

int S[]={0,1,4,6};


void mostrar(int T[4][9]){
    int i,j;
    for (i=0; i<=3; i++){
            for (j=0; j<=8; j++){
                    cout << T[i][j] << "  ";
            }
            cout << endl;
    }

}


int sellos ( int n, int T ){
    int i,j;
    int F[4][9];
    //int seleccion[n+1];
    //int F[4][9];


       for (j=1; j<=T; j++) {F[0][j]= 0;};
       for (i=0; i<=n; i++) {F[i][0]= 1;};
       for (i=1; i<=n; i++){
            for (j=1; j<=T; j++){

                    if (S[i] <= j){
                        F[i][j] = F[i-1][j]+ F[i][j-S[i]];
                    }else
                        F[i][j] = F[i-1][j];
            }
       }
       mostrar(F);
       return (F[n][T]);

}



int main(){

    int Franqueo=8;
    int nMod=3;

    cout << "\nCombinaciones de sellos: " << sellos (nMod,Franqueo) << endl;

    return 0;
}
