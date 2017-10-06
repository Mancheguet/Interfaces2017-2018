#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

//define una macro BORRARPANTALLA que ejecuta lo que esta a continuacion
#define BORRARPANTALLA   for (int i=0; i<40; i++) cout << endl;

class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;

    void ingresar(float cantidad){
      this->saldo += cantidad;
    }

    bool retirar(float cantidad){

      if (this->saldo < cantidad){
        return false;
      }

      this->saldo -= cantidad;
      return true;

    }

private:
    float interes;
};

void menu(void){

  //lineas en blanco
  BORRARPANTALLA //llamada a la macro definida al prinicpio

   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        5 - Salir a MSDOS " << endl;

  //lineas en blanco
  BORRARPANTALLA

}

int seleccionarCuenta(Cuenta * cuentas){
    string numCuenta;
    cout << "Dime el numero de cuenta : " << endl;
    cin >> numCuenta;

    for (int i=0 ; i < 10; i++) {
        if(numCuenta == (cuentas[i]).numCuenta){
          return i;
        }
    }

    return -1;

}

void ingresar(Cuenta * cuenta){
  //cout <<"Has elegido ingresar" << endl;
  float cantidadIngres;
  cout << "Dime la cantidad a ingresar : " << endl;
  cin >> cantidadIngres;
  (cuenta->ingresar(cantidadIngres));

}

void mostrarSaldo(Cuenta * cuenta){

    cout <<"Has elegido mostrar saldo" << endl;
    cout << "El saldo de la cuenta "<< (*cuenta).numCuenta << " : " << (*cuenta).saldo << endl;

}

void reintegrar(Cuenta * cuenta){

    float cantidad;
    cout << "Dime una cantidad a reintegrar :  ";
    cin >> cantidad;

    if ( (*cuenta).retirar(cantidad) ){
      cout << "Se han podido retirar " << cantidad << " euros . Saldo = " << (*cuenta).saldo <<endl;
    } else {
      cout << "No se ha podido retirar " << cantidad << " euros . Saldo = " << (*cuenta).saldo <<endl;
    }

}

void inicializarCuentas (Cuenta cuentas[]){
  for (int i=0 ; i < 5; i++) {
    stringstream ss;
    ss << 100+i;
    cuentas[i].numCuenta=ss.str();
    cuentas[i].saldo=0;

    stringstream sss;
    sss << i;
    string str = sss.str();
    cuentas[i].titular = "pepe" + str;
  }
}

void mostrarCuentas(Cuenta cuentas[]){

  cout << "Titular" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << "\t" << cuentas[i].titular;
  }
  cout << endl << "NumCuenta" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << cuentas[i].numCuenta << "\t";
  }
  cout << endl << "Saldo" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << "\t" << cuentas[i].saldo;
  }

}

int main(int argc, char *argv[]) {

  char opcion;
  Cuenta cuentas[10];
  int cuentaSelecionada=-1;
  //string nombres[10] = {"Juan","Jose","Alberto","Perico","Andres","Puertos","Paco","Pepe","Pepito","Javi",};

  inicializarCuentas(cuentas);
  mostrarCuentas(cuentas);

  while (true) {

    menu();
    cin >> opcion;

    switch (opcion) {

      case '1': cuentaSelecionada = seleccionarCuenta(cuentas);
        break;
      case '2':
        if(cuentaSelecionada<0){
          cout << "Debes seleccionar una cuenta primero , opción 1 !!!" << endl;
        } else {
          ingresar(&cuentas[cuentaSelecionada]);
        }
        break;
      case '3':
        if(cuentaSelecionada<0){
          cout << "Debes seleccionar una cuenta primero , opción 1 !!!" << endl;
        } else {
          reintegrar(&cuentas[cuentaSelecionada]);
        }
        break;
      case '4':
        if(cuentaSelecionada<0){
          cout << "Debes seleccionar una cuenta primero , opción 1 !!!" << endl;
        } else {
          mostrarSaldo(&cuentas[cuentaSelecionada]);
        }
        break;
      case '5': exit(0);

    };

    cout <<"Pulsa una tecla para contiuar." << endl;
    cin >> opcion;

  }

}
