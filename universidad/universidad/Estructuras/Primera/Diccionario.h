/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: nedveros
 *
 * Created on 19 de septiembre de 2017, 18:53
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "VectorEstatico.h"
#include "Palabra.h"

class Diccionario {
public:
    Diccionario();
    Diccionario(const Diccionario& orig);
    virtual ~Diccionario();
    string GetPalabra(int i ){
    
        return this->vector.getVector(i);
        
    }
    
    
    
     void quicksort(int comienzo,int final){
 
     int derecha;
     string pivote;
     int izquierda;
     izquierda=comienzo;
     derecha =final;
     pivote =vector.getVector((comienzo + final)/2);
     while(izquierda < derecha ){
     
         while(vector.getVector(izquierda) < pivote ) izquierda++;
         while (vector.getVector(derecha) > pivote )derecha--;
         Palabra Ptemporal;
         Palabra Ptemporal2;
         if (izquierda <= derecha ) {
             string temporal = vector.getVector(izquierda);
             Ptemporal.SetTermino(vector.getVector(derecha));
             
             vector.setVector(izquierda,Ptemporal);
             Ptemporal2.SetTermino(temporal);
             
             vector.setVector(derecha,Ptemporal2);
             izquierda++;
             derecha--;
         }}
     if (comienzo < derecha ) quicksort(comienzo,derecha);
     if (izquierda < final )quicksort(izquierda,final);
    
         }
     
     

    
    
    /**
     * @brief funcion que inserta un valor en el vector
     * @param i posicion en la que inserta el valor
     * @param p palabra que inserta en la posicion de i
     */

    void inserta(int i ,Palabra p){
    
    
        vector.setVector(i,p);
        
        quicksort(0,80337);
        
    }
    
    /**
     * 
     * @brief funcion para enseñar todo el vector.
     * 
     */
    
    
    
    void ensena(){
    
        for (int i=0 ; i < 80338; i++){
        
            std::cout<<i<<" "<<vector.getVector(i)<<endl;
        
        
        
        }

    }
/**
 * @brief funcion de busqueda binaria o dicotomica.
 * @param inicio el inicio del vector estatico.
 * @param final el final del vector estatico.
 * @param x la cadena que se va a buscar en el vector.
 * @return la posicion de la cadena donde esta.
 * 
 */
    
    int busqueda_binaria(int inicio, int final, string x)
{
    
     int medio;
     bool flag = false; 
     while((inicio <= final) && (!flag))
     {
        medio = (inicio + final) / 2;
        //para comparar usamos compare() de string
       
        if(x.compare(vector.getVector(medio)) > 0) inicio = medio + 1;
        else if(x.compare(vector.getVector(medio)) < 0) final = medio - 1;
        else flag = true;
     }
     if(flag) {cout << "Elemento" <<" "<< x << " "<<"encontrado en la posicion " << medio << endl;
     return medio;
     }
     else {cout << "El elemento no esta en la lista" << endl;
     return -1;
     }
}
    
    
//no funciona
 string quitarAcentos(std::string &cadena){
     
    char vocal_sin[]="aeiou",vocal_con[]="áéíóú";
    int i,j;
    for (i=0;i<5;i++){
       
            if (vocal_con[i]==cadena[0])
                cadena[0]=vocal_sin[i];
        
    }
    return cadena;
}
 //no funciona
 string acentos(std::string &cade){





for(int i=0; i< cade.length(); i++) { 
if( cade[i] ==(char)135 ) cade[i] = 'a'; 
if( cade[i] ==(char)142 ) cade[i] = 'e'; 
if( cade[i] ==(char)161 ) cade[i] = 'a'; 
if( cade[i] ==(char)162 ) cade[i] = 'o'; 
if( cade[i] ==(char)163 ) cade[i] = 'u'; 
} 

cout << "Texto corregido: " << cade << endl; 

 }
 
    
    
    
   
private:
    
    VectorEstatico vector;
    
};

#endif /* DICCIONARIO_H */

