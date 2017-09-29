/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: nedveros
 *
 * Created on 19 de septiembre de 2017, 18:40
 */

#ifndef PALABRA_H
#define PALABRA_H
#include <string>
using namespace std;

class Palabra {
public:
    Palabra();
    Palabra(const Palabra& orig);
    virtual ~Palabra();
    void SetTermino(string termino);
      string GetTermino() const {
        return termino;
    }

private:
    string termino;
};

#endif /* PALABRA_H */

