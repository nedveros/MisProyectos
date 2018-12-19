#include <iostream>
#include <list>
#include "stdlib.h"
#include "time.h"

#include "Equipo.h"
#include "Ciudad.h"

#define NCIUDAD 10

using namespace std;

Equipo *seleccionarEquipo(const Ciudad &ciudad, list <Equipo> &equipos) {
		list<Equipo>::iterator it = equipos.begin();
		while (it !=equipos.end()) {
			if (it->getEfectivos() >= ciudad.getEfectivos()) {

                Equipo *otroEquipo = new Equipo(*it);
				it=equipos.erase(it);
				return otroEquipo;
			}else{
                it++;
			}
		}
		return 0;
	}



int main()
{
    srand(time(0));
    int n= (rand()%NCIUDAD)+1;
    int numVictorias = 0;

	list<Ciudad> ciudadesEnemigas;
    list<Equipo> equiposIntervencion;

    for (int i = 0; i < n; i++) {
        ciudadesEnemigas.push_back(Ciudad(i));
        equiposIntervencion.push_back(Equipo(i));
    }
	ciudadesEnemigas.sort();
    equiposIntervencion.sort();
    Equipo *seleccionado;
	list <Ciudad>::iterator p;
		for (p = ciudadesEnemigas.begin(); p!= ciudadesEnemigas.end() ; p++) {
            Ciudad ciudadAtacada = *p;
            seleccionado = seleccionarEquipo(ciudadAtacada,equiposIntervencion);
			if (seleccionado != 0) {
					cout << "Batalla de la ciudad "
							<< ciudadAtacada.getNumCiudad() << " ("
							<< ciudadAtacada.getEfectivos()
							<< ") con el equipo de asalto "
							<< seleccionado->getNumEquipo() << " ("
							<< seleccionado->getEfectivos() << ")."<< endl;
					numVictorias++;
            }else{
                cout << "Ciudad perdida: " << ciudadAtacada.getNumCiudad() << endl;
            }
		}
		cout <<endl<< "Numero de victorias: " << numVictorias
            << " Numero total de ciudades: " << n << ".";

    return 0;
}
