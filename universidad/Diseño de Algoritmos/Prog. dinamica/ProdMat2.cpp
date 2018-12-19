#include <iostream>
#define MAX 1000000
#define N 100
using namespace std;


/**int Minimo(int d[N], int M[N+1][N+1], int i, int j, int &k1){
    int aux,k,min;

    min=MAX;
    for (k=i; k<=j-1; k++){
        aux=M[i][k]+M[k+1][j]+(d[i-1]*d[k]*d[j]);
        //cout << i-1 << "," << k << "," << j << endl;
        if (aux<min){
            min=aux;
            k1=k;
        }
    }
    return min;
}
*/
int Matriz(int d[N], int n, int Compo[N+1][N+1]){
    int  i,s,aux,k,k1,min;
    int M[N+1][N+1];

    for (i=1;i<=n;i++){
        M[i][i]=0;
    }

    for (s=1; s<=n-1; s++){
        for (i=1; i<=n-s; i++){
                //calculamos minimos
                min=MAX;
                for (k=i; k<=i+s-1; k++){
                    aux=M[i][k]+M[k+1][i+s]+(d[i-1]*d[k]*d[i+s]);
                    if (aux<min){
                        min=aux;
                        k1=k;
                    }
                }
                M[i][i+s]=min;
                Compo[i][i+s]=k1;
                //M[i][i+s]= Minimo(d,M,i,i+s,Compo[i][i+s]);
                cout << M[i][i+s] << " ";
        }
        cout << endl;
    }


    return M[1][n];
}

void Orden(int Compo[N+1][N+1],int i,int j){
    int k;

    if (i==j) {
        cout << "M" << i;
    }else{
        k=Compo[i][j];
        cout << "(";
        Orden(Compo,i,k);
        cout << "*";
        Orden(Compo,k+1,j);
        cout << ")";
    }
}

int main(){
// 3 Matrices de Dimensiones (10,10),(10,50),(50,50) -->>
//dimensiones en pos. dk-1,dk para matriz k

    //int d[]={10,10,50,50};
    int d[]={13,5,89,3,34};
    int i,j,n=4;
    int Compo[N+1][N+1];
    int mult;

    cout << "Valores matriz resultados:" << endl;
    mult= Matriz(d, n, Compo);
    cout << "Matriz Orden de Productos:" << endl;
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
                cout << Compo[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nNumero multiplicaciones escalares: " << mult << endl;

    cout << "Orden de llamadas: " << endl;
    Orden(Compo,1,n);

    return 0;
}
