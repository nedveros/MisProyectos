#include <iostream>
#include <list>
#include <vector>
#include "time.h"
#include "stdlib.h"

#include "Cliente.h"


using namespace std;

int main()
{
   srand(time(0));
   int nC= (rand()%10)+1;

   //nuevo
   int Nf=3;
   vector<vector<int> >reparto;
   reparto.resize(Nf, vector<int>(nC));

   list<Cliente> clientes;
   for (int i = 1; i <= nC; i++)
            clientes.push_back(Cliente(i));
    clientes.sort();
    int esperaParcial = 0;
    list <Cliente>::iterator p;

    //nuevo
    int i=0;
    int j=0;

    for (p = clientes.begin(); p!= clientes.end() ; p++) {
        Cliente actual = *p;

        //nuevo para asignar los trabajos al fontanero mas libre
        reparto[i%Nf][j]=actual.getNumCliente();
        i++;
        j=i/Nf;

        actual.setEspera(esperaParcial);
        cout << "Cliente " << actual.getNumCliente()
                << ": Tiempo de trabajo -> " << actual.getMinutosTrabajo()
                << "\tEspera parcial: " << esperaParcial << " minutos."<< endl;
        esperaParcial += actual.getMinutosTrabajo() ;
    }
    //tiempo final el total menos el de la última reparación
    int E = esperaParcial - clientes.back().getMinutosTrabajo();
    cout << endl << "Numero total de clientes: " << nC << endl;
    cout << "Tiempo total de espera: " << E << " minutos." << endl;

    //nuevo
    for ( i=0; i<Nf; i++){
        cout << "Fontanero " << i+1 << ": ";
        for ( j=0; j<nC; j++){
            if (reparto[i][j])
                cout << reparto[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}

