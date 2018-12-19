#include <iostream>

#define N 20  //modificar para probar otros numeros

/*Aplicación del ejercicio del temario: Potencia eficiente con DyV
*/

using namespace std;


float Potencia(float x, int n){
 float y;
 // casos base
    if (n==0)
        return 1;
    if (n==1)
        return x;

    y = Potencia(x, n/2);
    if (n%2==0)
        y = y*y;
    else
        y = x*(y*y);

    return y;

}


int main()
{
    int x,n;

    cout << "Introduce base" << endl;
    cin >> x;
    cout << "Introduce exponente natural" << endl;
    cin >> n;
    cout << "Potencia: " << Potencia(x,n);


    return 0;
}
