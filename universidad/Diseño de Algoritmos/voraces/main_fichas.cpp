/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Xenahort
 *
 * Created on 8 de abril de 2016, 17:20
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

struct Ficha {
    int fichas;
    string anio;
};

int unirFicheros(Ficha fich[], int tam) {
    bool unidos[tam];
    int tamT = tam;
    for (int i = 0; i < tam; i++) {
        unidos[i] = false;
    }
    while (tamT != 1) {
        int n1 = -1, n2 = -1;
        for (int i = 0; i < tam; i++) {
            if (unidos[i] == false) {
                if (n1 == -1) {
                    n1 = i;
                } else {
                    if (fich[i].fichas < fich[n1].fichas) {
                        n1 = i;
                    }
                }
            }
        }
        unidos[n1] = true;
        for (int i = 0; i < tam; i++) {
            if (unidos[i] == false) {
                if (n2 == -1) {
                    n2 = i;
                } else {
                    if (fich[i].fichas < fich[n2].fichas) {
                        n2 = i;
                    }
                }
            }
        }
        fich[n2].fichas += fich[n1].fichas;
        fich[n2].anio += "-" + fich[n1].anio;
        cout << "Formado el conjunto " << fich[n2].anio << " con " << fich[n2].fichas << " fichas" << endl;
        --tamT;
    }
}
/*
int unirFicheros(Ficha fich[], int tam) {
    bool unidos[tam];
    int tamT = tam;
    for (int i = 0; i < tam; i++) {
        unidos[i] = false;
    }
    while (tamT != 1) {
        int n1 = 999999, n2 = 999999;
        for (int i = 0; i < tam; i++) {
            if (unidos[i] == false) {
                if (fich[i].fichas<n1) {
                    n2 = n1;
                    n1 = i;
                } else {
                    if (fich[i].fichas < n2) {
                        n2 = i;
                    }
                }
            }
        }
        unidos[n1] = true;

        fich[n2].fichas += fich[n1].fichas;
        fich[n2].anio += "-" + fich[n1].anio;
        cout << "Formado el conjunto " << fich[n2].anio << " con " << fich[n2].fichas << " fichas" << endl;
        --tamT;
    }


}
*/
int main(int argc, char** argv) {

    int tam = 6;
   // Ficha fich[]={{20,"2010"},{15,"2011"},{13,"2012"},{10,"2013"},{30,"2014"},{25,"2015"}};
    Ficha fich[tam];

    Ficha f1;
    f1.anio = "2010";
    f1.fichas = 20;
    Ficha f2;
    f2.anio = "2011";
    f2.fichas = 15;
    Ficha f3;
    f3.anio = "2012";
    f3.fichas = 13;
    Ficha f4;
    f4.anio = "2013";
    f4.fichas = 10;
    Ficha f5;
    f5.anio = "2014";
    f5.fichas = 30;
    Ficha f6;
    f6.anio = "2015";
    f6.fichas = 25;

    fich[0] = f1;
    fich[1] = f2;
    fich[2] = f3;
    fich[3] = f4;
    fich[4] = f5;
    fich[5] = f6;

    unirFicheros(fich, tam);

    return 0;
}


