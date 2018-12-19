#include <iostream>
#include <stdlib.h>
#define N 4

using namespace std;

void muestra(int mat[][N]){

  cout << "  - - - -"<< endl;
  for (int i=0;i<N;i++){
    cout << "| ";
    for (int j=0;j<N-1;j++){
            cout << mat[i][j] << " ";
    }
    cout << i+1 << endl;  //diferencia respecto al del torneo
  }
  cout << endl;
}

// Función que permite verificar si un valor n es potencia de 2

int potenciaDos (int n)
{
    int potencia = 2;
    while(potencia <= n) {
        if (n == potencia)
            return true;
        potencia *= 2;
    }
    return false;
}

//FUNCION RECURSIVA C LATINO para Potencias de 2
void CLatino (int n, int t[][N])
{
    int i, j;
    /* Caso base */
    if (n==2) {
        t[0][0]=2;
        t[1][0]=1;
    }
    /** Primero analizamos el caso cuando es potencia de 2 */
    else
        if (potenciaDos(n)) {
        /* Dividimos entre 2 hasta llegar al caso base */
        CLatino (n/2,t);
        /* Una vez que el caso base ha sido llenado, se llena el cuadrante superior derecho */
        for (i=0; i<n/2; i++) {
            for (j=n/2-1; j<n-1; j++) {
                t[i][j] = i+1 + j+1;
                if (t[i][j] > n)
                    t[i][j] = t[i][j]-n/2;
            }
        }
        /* Llenado del cuadrante inferior derecho */
        for (i=n/2; i<n; i++) {
            for (j=n/2-1; j<n-1; j++) {
                t[i][j] = i+1 - (j+1);
                if (t[i][j] <= 0)
                    t[i][j] = t[i][j] + n/2;
            }
        }
        /* Llenado del cuadrante inferior izquierdo */
        for (i=n/2; i<n; i++) {
            for (j=0; j < n/2 - 1; j++) {
                t[i][j] = t[i-n/2][j] + n/2;
            }
        }
    /*    if (n==4){
         muestra(t);
         system("PAUSE");
        }*/
    } //else no seguimos
}



int main()
{
    int t[N][N];
    CLatino(N,t);
    muestra(t);

    return 0;
}
