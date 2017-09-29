/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.cpp
 * Author: nedveros
 * 
 * Created on 19 de septiembre de 2017, 18:53
 */

#include "Diccionario.h"
#include <fstream> 
#include <iostream> 

Diccionario::Diccionario() {
    
    
    fstream fichero; 
    char texto[200]; 
                                // Abro para lectura 
    fichero.open("listado-general.txt", ios::in); 
    fichero >> texto; 
    int i=0;
    while (!fichero.eof())    {
      //std::cout << texto << endl; 
        string intermedio(texto);
        
      
//      vector[i]=intermedio;
        Palabra p;
        p.SetTermino(intermedio);
        
        vector.setVector(i,p);
       
   
      i++;
      fichero >> texto;         // Y vuelvo a intentar leer 
    } 
    fichero.close();            // Finalmente, cierro 
    

    
}

Diccionario::Diccionario(const Diccionario& orig) {
}

Diccionario::~Diccionario() {
}

