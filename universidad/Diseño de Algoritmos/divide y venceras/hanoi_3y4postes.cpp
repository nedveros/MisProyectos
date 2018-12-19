/**
   @file Resolución del problema de las Torres de Hanoi
*/


#include <iostream>
#include <ctime>
using namespace std;


void hanoi3(int N,int Orig, int Dest,int Aux, int &mov){

    if (N == 1){
      cout <<"Disco " << N << " desde " << Orig << " hasta " << Dest << endl;
      mov++;
    }else{
        hanoi3(N-1,Orig,Aux,Dest,mov);
        cout <<"Disco " << N << " desde " << Orig << " hasta " << Dest << endl;
        mov++;
        hanoi3(N-1,Aux,Dest,Orig,mov);
    }
}

void hanoi4(int N,int Orig, int Dest,int Aux1,int Aux2, int &mov){

    if (N!=0){
      if (N == 1){
        cout <<"Disco " << N << " desde " << Orig << " hasta " << Dest << endl;
        mov++;
      }else{
        hanoi4(N-2,Orig,Aux1,Dest,Aux2,mov);
        cout <<"Disco " << N-1 << " desde " << Orig << " hasta " << Aux2 << endl;
        cout <<"Disco " << N << " desde " << Orig << " hasta " << Dest << endl;
        cout <<"Disco " << N-1 << " desde " << Aux2 << " hasta " << Dest << endl;
        mov+=3;
        hanoi4(N-2,Aux1,Dest,Orig,Aux2,mov);
      }
    }
}
int main()
{

  int M,cont=0;
  do
    {
      cout << "Número de discos: ";
      cin >> M;
    } while (M <= 0);

  cout <<"HANOI 3 Postes" << endl;
  hanoi3(M, 1,3,2, cont);
  cout << "Movimientos: " << cont << endl;

  cont=0;

  cout <<"HANOI 4 Postes" << endl;
  hanoi4(M, 1,3,2,4, cont);
  cout << "Movimientos: " << cont << endl;
  return 0;
}
