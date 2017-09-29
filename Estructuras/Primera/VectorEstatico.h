/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorEstatico.h
 * Author: nedveros
 *
 * Created on 19 de septiembre de 2017, 18:42
 */

#ifndef VECTORESTATICO_H
#define VECTORESTATICO_H
#include "Palabra.h"
#include <iostream>
using namespace std;
template <typename T>
class VectorEstatico {
public:
    VectorEstatico();
    VectorEstatico(const VectorEstatico& orig);
    virtual ~VectorEstatico();
   T getVector(int i){
        return vector[i].GetTermino();
    }
    void setVector(int pos,T p){
        vector[pos].SetTermino(p.GetTermino());
    }
    void ensena(int tamano){
        for (int i =0 ; i < tamano ; i++){
        
            std::cout<<vector[i].GetTermino()<<endl;
        
        }
    
    }


    void setTamano(int tamano);
    int getTamano() const;
    
private:
    int tamano;
    T vector[tamano];
};

#endif /* VECTORESTATICO_H */

