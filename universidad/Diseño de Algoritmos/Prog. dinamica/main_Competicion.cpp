#include <iostream>
#define PMAX 10

using namespace std;

//funcionando con una matriz de solución
float competi2(int n,float p){
     float P[n+1][n+1];

    for (int j=1;j<=n;j++)
        P[0][j]=1;
    for (int j=1;j<=n;j++)
        P[j][0]=0;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            P[i][j]=(p*P[i-1][j]) + ((1-p)*P[i][j - 1]);
        }
    }

    return P[n][n];
}

//Teniendo en cuenta que hay p(gana), q(pierde), r(empata
float competi(int n, float p, float q, float r){
    float P[n+1];
    P[0]=0;
    for (int j=1;j<=n;j++)
        P[j]=1;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
                //cout << p/(1-r) <<";" << q/(1-r)<< endl;
            P[j]=(p/(1-r)*P[j]) + (q/(1-r)*P[j - 1]);
        }
    }

    return P[n];
}

//funcionando con una vector de solución
float competi(int n, float p){
    float P[n+1];
    P[0]=0;
    for (int j=1;j<=n;j++)
        P[j]=1;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            P[j]=(p*P[j]) + ((1-p)*P[j - 1]);
        }
    }

    return P[n];
}


int main()
{

    int n=10;
    float p=0.8, q=0.1, r=0.1;

    cout << "1) Probabilidad de que A gane el campeonato: " <<competi(n,p) << endl;
    // Version con probabilidad de empate
    cout << "2) Probabilidad de que A gane el campeonato: " <<competi(n,p,q,r);
    return 0;
}
