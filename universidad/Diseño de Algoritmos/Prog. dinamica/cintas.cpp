#include <iostream>
#define MAX 100



using namespace std;


/**
void mostrar(int T[4][9]){
    int i,j;
    for (i=0; i<=3; i++){
            for (j=0; j<=8; j++){
                    cout << T[i][j] << "  ";
            }
            cout << endl;
    }

}
*/
int mayor(int a, int b){
    if (a>b) return a; else return b;
}

int menor(int a, int b){
    if (a<b) return a; else return b;
}

int cintas ( int P[], int Np, int Lp, int Vsal[] ){
    int tiempo[Np+1][Lp+1];

    for (int i=0; i<=Lp; i++)
        tiempo[0][i]=mayor(i, Lp-i);

    int suma=Lp;
    for (int i=1; i<=Np; i++){
        suma-=P[i];
        for (int j=0; j<=suma; j++){
            tiempo[i][j]=menor(tiempo[i-1][j+P[i]], tiempo[i-1][j]);
        }
    }
//Calculamos la solución
    int L1=0;
    for ( int i=Np; i>=1; i--){
        if (tiempo[i][L1]==tiempo[i-1][L1])
            Vsal[i]=2;
        else{
            Vsal[i]=1;
            L1+=P[i];
        }
    }

    return (tiempo[Np][0]); //devolvemos el resultado de la última celda de la matriz
			// hasta con n monedas, combinaciones para obtener un franqueo T

}



int main(){

    int Vsal[MAX],P[MAX]={0,5,4,6};
    int Lp=15;
    int Np=3;

    cout << "Tiempo optimo:" << cintas (P,Np,Lp,Vsal);
    cout << "\nProgramas grabados: " << endl;
    for (int i=1; i<=Np; i++){
        cout << Vsal[i] << ",";
    }
    cout << endl;

    return 0;
}
