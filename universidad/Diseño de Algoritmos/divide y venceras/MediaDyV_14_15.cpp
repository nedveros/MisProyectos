#include <iostream>
#define TAM 4

using namespace std;

float AlgoritmoMediaClasico(int m[][TAM], int n, int pf, int uf, int pc, int uc){

    int i,j,s=0;

    for(i=pf;i<=uf;i++)
            for (j=pc;j<=uc;j++)
                s+=m[i][j];
    return (float) s/(n*n);
}

float MediaMatdyv(int m[][TAM], int n, int pf, int uf, int pc, int uc){

	if (n==2)
		return AlgoritmoMediaClasico(m, n, pf, uf, pc, uc);
	else{
		float m1=MediaMatdyv(m, n/2, 0, (n/2)-1, 0, (n/2)-1);
		float m2=MediaMatdyv(m, n/2, n/2, n-1, 0, (n/2)-1);
		float m3=MediaMatdyv(m, n/2, 0, (n/2)-1, n/2, n-1);
		float m4=MediaMatdyv(m, n/2, n/2, n-1, n/2, n-1);
		//cout << m1 <<","<< m2 <<","<< m3 <<","<< m3 << endl;
		return (m1+m2+m3+m4)/4;
	}
}


int main(){

	int m[][4]={{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};


	float res=MediaMatdyv(m,4,0,3,0,3);

	cout << "Media DyV: " << res << endl;

	return 0;

}
