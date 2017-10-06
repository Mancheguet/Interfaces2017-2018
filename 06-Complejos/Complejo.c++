#include <iostream>
#include <sstream>
#include "Complejo.h"
using namespace std;

//Constructor con dos parametros
Complejo::Complejo(float realP, float imagP){
  real=realP;
  imag=imagP;
}

//Delego el constructor en el primero pasandole los dos parametros
Complejo::Complejo() : Complejo(0,0) {}

//con constructor : Complejo(realP,0) , lo que hago es ejecutar el constructor doble
Complejo::Complejo(float realP) : Complejo(realP,0) {}




string Complejo::imprimir(){

    stringstream sss ;
    sss <<  "(" << real << " + " << imag<<"i" << ")";
    return sss.str();
}

Complejo Complejo::operator+ (Complejo otro){

  Complejo resultado;
  resultado.real = real + otro.real;
  resultado.imag = imag + otro.imag;
  return resultado;

}

Complejo Complejo::operator- (Complejo otro){

  Complejo resultado;
  resultado.real = real - otro.real;
  resultado.imag = imag - otro.imag;
  return resultado;

}

Complejo Complejo::operator- (){

  Complejo resultado;
  resultado.real = -(real);
  resultado.imag = -(imag);
  return resultado;

}

//Para ++a;
Complejo Complejo::operator++ (){

  real++;
  return (*this);

}
//Para a++;
Complejo Complejo::operator++ (int i){

  Complejo temp = (*this);
  real++;
  return temp;

}
