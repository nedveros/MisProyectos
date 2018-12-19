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
void AlgoritmoTraspClasico(int m[][TAM], int pf, int uf, int pc, int uc){

    int aux;
    aux= m[pf][uc];
    m[pf][uc]=m[uf][pc];
    m[uf][pc]=aux;
}

void intercambiaCol(int m[][TAM], int col1, int col2, int n){

    int aux;
    for (int i=0;i<n/2;i++){
        aux=m[i][col2];
        m[i][col2]=m[i+n/2][col1];
        m[i+n/2][col1]=aux;
    }
}
void TraspMatdyv(int m[][TAM], int n, int pf, int uf, int pc, int uc){

	if (n==2)
        AlgoritmoTraspClasico(m, pf, uf, pc, uc);
	else{
		TraspMatdyv(m, n/2, pf, pf+(n/2)-1, pc, pc+(n/2)-1);
		TraspMatdyv(m, n/2, pf+(n/2), uf, pc, pc+(n/2)-1);
		TraspMatdyv(m, n/2, pf, pf+(n/2)-1, pc+(n/2), uc);
		TraspMatdyv(m, n/2, pf+(n/2), uf, pc+(n/2), uc);

		for (int i=n/2;i<n;i++)
            intercambiaCol(m, i-n/2, i, n);
	}
}


int main(){

	int m[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

        cout << "Original: " << endl;
        muestra(m,TAM);

	TraspMatdyv(m,TAM,0,TAM-1,0,TAM-1);

	cout << "Traspuesta DyV: " << endl;
        muestra(m,TAM);

	return 0;

}
