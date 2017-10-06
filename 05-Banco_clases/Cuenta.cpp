#include <string>
#include "Cuenta.h"

using namespace std;

Cuenta::Cuenta() {}

Cuenta::Cuenta(string tit, string numC, float s){
      titular = tit;
      numCuenta = numC;
      saldo = s;

}

void Cuenta::ingresar(float cantidad){
      this->saldo += cantidad;
}

bool Cuenta::retirar(float cantidad){

      if (this->saldo < cantidad){
        return false;
      }

      this->saldo -= cantidad;
      return true;

}
