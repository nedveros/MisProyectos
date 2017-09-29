/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.cpp
 * Author: nedveros
 * 
 * Created on 19 de septiembre de 2017, 18:40
 */

#include "Palabra.h"

Palabra::Palabra() {
}

Palabra::Palabra(const Palabra& orig):termino(orig.termino) {
}

Palabra::~Palabra() {
}

void Palabra::SetTermino(string termino) {
    this->termino = termino;
}
