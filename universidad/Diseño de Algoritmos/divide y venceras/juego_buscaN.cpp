#include <iostream>

#define N 20  //modificar para probar otros numeros

/*Nº a adivinar: mediante este juego, dado un intervalo hay que encontrar un
nº dentro del mismo previamente seleccionado, de tal manera que solo podemos
saber cuando dicho nº es menor o igual que aquellos que vamos intentando.
Filosofia DyV tipo Busqueda Binaria
*/

using namespace std;









bool MenorIgual(int x){
    return (N<=x);
}


int BuscaNumero(int prim, int ult, int &intentos){
 int mitad;

 // casos base
    if (prim==ult){
        intentos++;
        return prim;
    }
    mitad=(prim+ult)/ 2;
 //resto
    intentos++;
    if (MenorIgual(mitad))
        return BuscaNumero(prim,mitad,intentos);

    return BuscaNumero(mitad+1,ult,intentos);

}


int main()
{
    int p,u, intentos=0;

    cout << "Introduce numero inicial" << endl;
    cin >> p;
    cout << "Introduce numero final" << endl;
    cin >> u;
    cout << "Numero encontrado:" << BuscaNumero(p,u, intentos) << endl;

    //mostramos los intentos que necesitamos para encontrarlo
    cout << "Numero de intentos:" << intentos << endl;

    return 0;
}
