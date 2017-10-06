#include <iostream>
#include <string>

using namespace std;

#include "Complejo.h"

/*
Complejo operator+ (Complejo c1, Complejo c2){

  Complejo resultado;
  resultado.real = c1.real + c2.real;
  resultado.imag = c1.imag + c2.imag;
  return resultado;

}

Complejo operator- (Complejo c1, Complejo c2){

  Complejo resultado;
  resultado.real = c1.real - c2.real;
  resultado.imag = c1.imag - c2.imag;
  return resultado;

}

Complejo operator- (Complejo c1){

  Complejo resultado;
  resultado.real = -(c1.real);
  resultado.imag = -(c1.imag);
  return resultado;

}

//Para ++a;
Complejo operator++ (Complejo & c1){

  c1.real++;
  return c1;

}
//Para a++;
Complejo operator++ (Complejo & c1, int i){

  Complejo temp = c1;
  c1.real++;
  return temp;

}
*/

int main (int argc,char * argv[]){

  Complejo c(5,-8);
  Complejo a(4,9);
  Complejo b;
/*
  c.real=5;
  c.imag = -8;

  a.real = 4;
  a.imag = 9;
*/
  b = a + c;

  cout<< "El número es c -> "<< c.imprimir() << endl;
  cout<< "El número es a -> "<< a.imprimir() << endl;
  cout<< "La suma directamente -> "<< (a+c).imprimir() << endl;
  cout<< "La resta directamente -> "<< (a-c).imprimir() << endl;

  Complejo d;
  d = -a;
  cout<< "El número es d es (-a) -> "<< d.imprimir() << endl;

  ++a;
  cout<< "El número a con ++a -> "<< (a).imprimir() << endl;

  Complejo e;
  e = a++;
  cout<< "El número a con a++ -> "<< (a).imprimir() << endl;
  cout<< "El número e con a++ -> "<< (e).imprimir() << endl;

}
