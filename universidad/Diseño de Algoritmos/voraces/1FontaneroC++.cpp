#include <iostream>
#include <list>
#include "time.h"
#include "stdlib.h"

#include "Cliente.h"


using namespace std;

int main()
{
   srand(time(0));
   int n = (rand()%10)+1;
   //int n=4;

   list<Cliente> clientes;
   for (int i = 0; i < n; i++)
            clientes.push_back(Cliente(i));
    clientes.sort();
    int esperaParcial = 0;
    list <Cliente>::iterator p;
    for (p = clientes.begin(); p!= clientes.end() ; p++) {
        Cliente actual = *p;
        actual.setEspera(esperaParcial);
        cout << "Cliente " << actual.getNumCliente()
                << ": Tiempo de trabajo -> " << actual.getMinutosTrabajo()
                << "\tEspera parcial: " << esperaParcial << " minutos."<< endl;
        esperaParcial += actual.getMinutosTrabajo() ;
    }
    //tiempo final el total menos el de la última reparación
    int E = esperaParcial - clientes.back().getMinutosTrabajo();
    cout << endl << "Numero total de clientes: " << n << endl;
    cout << "Tiempo total de espera: " << E << " minutos." << endl;

    return 0;
}

