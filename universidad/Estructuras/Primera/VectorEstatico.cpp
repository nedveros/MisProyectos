/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorEstatico.cpp
 * Author: nedveros
 * 
 * Created on 19 de septiembre de 2017, 18:42
 */

#include "VectorEstatico.h"

VectorEstatico::VectorEstatico() {
    
    for (int i=0;i < 80383 ; i++){
    
        vector[i].SetTermino("vacio");
    }
    
}



void VectorEstatico::setTamano(int tamano) {
    this->tamano = tamano;
}

int VectorEstatico::getTamano() const {
    return tamano;
}

VectorEstatico::VectorEstatico(const VectorEstatico& orig) {
    for (int i ; i<orig.tamano;i++ ){
    vector[i].SetTermino(orig.vector[i].GetTermino());
    }
    
    
    
    
}

VectorEstatico::~VectorEstatico() {
}

