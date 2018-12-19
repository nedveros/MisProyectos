#include <iostream>
#define TAM 4

using namespace std;

void muestra(int m[][TAM],int n){
     for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
}

void AlgoritmoSumaClasico(int a[][TAM],int b[][TAM], int r[][TAM], int f1, int f2, int c1, int c2){

   for (int i=f1;i<=f2;i++){
        for (int j=c1;j<=c2;j++) {
            r[i][j]=a[i][j]+b[i][j];
        }
     }
}

void SumaMatdyv(int a[][TAM], int b[][TAM],int c[][TAM], int pf, int uf, int pc, int uc){
    int n=uf-pf+1;
	if (n==1){
                AlgoritmoSumaClasico(a , b, c, pf, uf, pc, uc);
	}else{
		SumaMatdyv(a,b,c, pf, pf+(n/2)-1, pc, pc+(n/2)-1);
		SumaMatdyv(a,b,c, pf+(n/2), uf, pc, pc+(n/2)-1);
		SumaMatdyv(a,b,c, pf, pf+(n/2)-1, pc+(n/2), uc);
		SumaMatdyv(a,b,c, pf+(n/2), uf, pc+(n/2), uc);
	}
}


int main(){

        int a[][4]={{8,4,5,3},{3,8,4,6},{6,1,3,3},{7,2,7,5}};
        int b[][4]={{6,2,3,6},{2,3,9,5},{5,4,6,3},{4,5,2,1}};

        int c[4][4];
        cout << "Originales: " << endl;
        muestra(a,TAM);
        cout << endl;
        muestra(b,TAM);

	SumaMatdyv(a,b,c,0,TAM-1,0,TAM-1);

	cout << "Suma DyV: " << endl;
        muestra(c,TAM);

	return 0;

}

/*#include <iostream>
#define TAM 4

using namespace std;

void muestra(int m[][TAM],int n){
     for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
}

void AlgoritmoSumaMatrices(int a[][TAM],int b[][TAM], int r[][TAM], int t){
     for (int i=0;i<t;i++){
        for (int j=0;j<t;j++) {
            r[i][j]=a[i][j]+b[i][j];
        }
     }
}

void CopiaMatriz(int rt[][TAM],int c[][TAM], int t){
    for (int i=0;i<t;i++){
        for (int j=0;j<t;j++) {
            c[i][j]= rt[i][j];
        }
    }
}

void AlgoritmoMultClasico(int a[][TAM],int b[][TAM], int r[][TAM], int f1, int c1, int f2, int c2){

   for (int i=f1;i<f1+2;i++){
        for (int j=c2;j<c2+2;j++){
            int suma= 0;
            for (int k=c1, l=f2; k<c1+2;k++,l++)
                suma+= a[i][k]*b[l][j];
            r[i][j]= suma;
        }
    }
}

void MultMatdyv(int a[][TAM], int b[][TAM],int c[][TAM], int n, int pf, int uf, int pc, int uc){
    //int n=uf-pf+1;
    int r1[TAM][TAM], r2[TAM][TAM], rt[TAM][TAM];
	if (n==2){
                AlgoritmoMultClasico(a , b, c, pf, uf, pc, uc);
	}else{
		MultMatdyv(a ,b, r1, n/2, 0, 0, 0, 0);
                MultMatdyv(a ,b, r2, n/2, 0, n/2, n/2, 0);

		MultMatdyv(a ,b, r1, n/2, 0, 0, 0, n/2);
                MultMatdyv(a ,b, r2, n/2, 0, n/2, n/2, n/2);

                MultMatdyv(a ,b, r1, n/2, n/2, 0, 0, 0);
                MultMatdyv(a ,b, r2, n/2, n/2, n/2, n/2, 0);

		MultMatdyv(a ,b, r1, n/2, n/2, 0, 0, n/2);
                MultMatdyv(a ,b, r2, n/2, n/2, n/2, n/2, n/2);
                AlgoritmoSumaMatrices(r1,r2,rt,n);
                CopiaMatriz(rt,c,n);

	}
}


int main(){

	int a[][4]={{8,4,5,3},{3,8,4,6},{6,1,3,3},{7,2,7,5}};
        int b[][4]={{6,2,3,6},{2,3,9,5},{5,4,6,3},{4,5,2,1}};
        int c[4][4];
        cout << "Originales: " << endl;
        muestra(a,TAM);
        cout << endl;
        muestra(b,TAM);

	MultMatdyv(a,b,c,TAM,0,TAM-1,0,TAM-1);

	cout << "Producto DyV: " << endl;
        muestra(c,TAM);

	return 0;

}*/
