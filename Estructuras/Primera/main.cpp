/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nedveros
 *
 * Created on 19 de septiembre de 2017, 18:39
 */

#include <cstdlib>
#include <iostream>

#include "Palabra.h"
#include "Diccionario.h"
#include "VectorEstatico.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Palabra p;

   p.SetTermino("david");
//    v.setVector(1,p);
   
   
    Diccionario d ;
   
   
 d.inserta(80337,p);
//    
//    
  // std::cout<<d.GetPalabra(80337);
//    
    //d.ensena();
  
  
   
//    

d.busqueda_binaria(0,80338,"david");
//    std::cout<<v;
//    
//    
    
    
    return 0;
}

