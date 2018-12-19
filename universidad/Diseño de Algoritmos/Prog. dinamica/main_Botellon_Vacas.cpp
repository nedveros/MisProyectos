#include <iostream>
#define MAX 100

using namespace std;

int mayor(int a, int b){
    if (a>b) return a; else return b;
}

int vasos(int P[MAX], int n){

    int bebidas[MAX][MAX];
    int i,j,d;
    int bebe_i,bebe_j;

    for (i=1; i<=n-1; i++){
        bebidas[i][i+1]= mayor(P[i],P[i+1]);
    }

    for (d=3;d<=n-1;d+=2){
        for (i=1;i<=n-d;i++){
            j=i+d;
            if (P[j]>P[i+1])
                bebe_i=bebidas[i+1][j-1];
            else
                bebe_i=bebidas[i+2][j];

            if (P[i]>P[j-1])
                bebe_j=bebidas[i+1][j-1];
            else
                bebe_j=bebidas[i][j-2];

            bebidas[i][j]=mayor(P[i]+bebe_i,P[j]+bebe_j);
        }
    }

    //Mostrar matriz opcional
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
                cout << bebidas[i][j] << "\t";
        }
        cout << endl;
    }
    return (bebidas[1][n]);

}

int main()
{
    int P[]={0,4,1,6,3,7,2};

    int n=6;

    cout << "cantidad TOTAL bebida: " << vasos(P,n) << endl;

    return 0;
}
