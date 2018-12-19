#include <iostream>

using namespace std;


int mostrar (int i) {

    switch(i){
        case 10: cout << "A"; break;
        case 11: cout << "B"; break;
        case 12: cout << "C"; break;
        case 13: cout << "D"; break;
        case 14: cout << "E"; break;
        case 15: cout << "F"; break;
        default:  cout << i;
    }
}

void CambioBase(int n, int base){

    if (n<base){

            mostrar(n);
    }else{
            CambioBase(n/base,base);
            mostrar(n%base);
        }
}

int main(){

    int n=274, base=2;

    cout << "Cambio: ";
    CambioBase(n, base);

return 0;
}
