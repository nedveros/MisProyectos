#include <iostream>
#define TAM 4

using namespace std;

float AlgoritmoMayorClasico(int m[][TAM], int pf, int uf, int pc, int uc){

    int i,j,mayor=m[pf][pc];

    for(i=pf;i<=uf;i++)
            for (j=pc;j<=uc;j++)
                if (m[i][j]>mayor)
                    mayor =m[i][j];
    return mayor;
}

float Maxde4(float a, float b, float c, float d){
    if (a>b && a>c && a>d)
        return a;
    else
        if (b>a && b>c && b>d)
            return b;
        else
            if (c>b && c>a && c>d)
                return c;
            else
                return d;
}
float MayorMatdyv(int m[][TAM], int n, int pf, int uf, int pc, int uc){

	if (n==2)
		return AlgoritmoMayorClasico(m, pf, uf, pc, uc);
	else{
		float m1=MayorMatdyv(m, n/2, 0, (n/2)-1, 0, (n/2)-1);
		float m2=MayorMatdyv(m, n/2, n/2, n-1, 0, (n/2)-1);
		float m3=MayorMatdyv(m, n/2, 0, (n/2)-1, n/2, n-1);
		float m4=MayorMatdyv(m, n/2, n/2, n-1, n/2, n-1);
		//cout << m1 <<","<< m2 <<","<< m3 <<","<< m3 << endl;
		return (Maxde4(m1,m2,m3,m4));
	}
}


int main(){

	int m[][4]={{8,2,3,4},{1,9,3,4},{1,2,6,4},{1,2,3,14}};


	float res=MayorMatdyv(m,4,0,3,0,3);

	cout << "Mayor DyV: " << res << endl;

	return 0;

}
