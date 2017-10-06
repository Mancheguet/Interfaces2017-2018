#include <iostream>
#include <sstream>
#include "Complejo.h"
using namespace std;


Complejo::Complejo(float realP, float imagP){
  real=realP;
  imag=imagP;
}


Complejo::Complejo(){}

Complejo::Complejo(float realP){
  real=realP;
  imag=0;
}




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
