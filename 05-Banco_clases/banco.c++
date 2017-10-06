#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "Cuenta.h"

//http://en.cppreference.com/w/cpp/container/vector
//http://www.cplusplus.com/reference/vector/vector/begin/

//define una macro BORRARPANTALLA que ejecuta lo que esta a continuacion
#define BORRARPANTALLA   for (int i=0; i<40; i++) cout << endl;


void menu(void){

  //lineas en blanco
  BORRARPANTALLA //llamada a la macro definida al prinicpio

   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        b - Borrar cuenta " << endl;
   cout << "        5 - Salir a MSDOS " << endl;

  //lineas en blanco
  BORRARPANTALLA

}

Cuenta * seleccionarCuenta(vector<Cuenta> & cuentas){
    string cuentaSolicitada;
    cout << "Dime el numero de cuenta : " << endl;
    cin >> cuentaSolicitada;

    for (int i=0 ; i < cuentas.size(); i++) {
        if(cuentas[i].numCuenta == cuentaSolicitada){
            return & cuentas[i];
        }
    }

    return NULL;

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

void inicializarCuentas(vector<Cuenta> * cuentas) {

    for (int i=0 ; i < 5; i++) {
        // nombre
        stringstream sss ;
        sss << i;
        string str = sss.str();
        string nombre = "pepe" + str;

        //numCuenta
        stringstream ss ;
         ss << 100+i ;
        string numCuenta = ss.str();

          // el saldo. es siempre 0
        cuentas->push_back( Cuenta(nombre,numCuenta,0)); // creo una cuenta i me guardo su direccion en cuentas

     }

}


void mostrarCuentas(vector<Cuenta> cuentas){

  cout << "Titular" << "\t";
  for (int i=0 ; i < cuentas.size(); i++) {
    cout << "\t" << cuentas[i].titular;
  }
  cout << endl << "NumCuenta" << "\t";
  for (int i=0 ; i < cuentas.size(); i++) {
    cout << cuentas[i].numCuenta << "\t";
  }
  cout << endl << "Saldo" << "\t";
  for (int i=0 ; i < cuentas.size(); i++) {
    cout << "\t" << cuentas[i].saldo;
  }

}

bool borrarCuenta(vector<Cuenta> & cuentas){
  string cuentaSolicitada;
  cout << "Dime el numero de cuenta "<< endl;
  cin >> cuentaSolicitada;

  //Para recorrer un vector (objeto) se usa el iterator
  vector<Cuenta>::iterator it;

  it = cuentas.begin(); //me devuelve el primer elemento del container (vector) . El primer elemento es aleatorio

  while (it != cuentas.end()) { //.end te devuelve el valor despues del ultimo elemento del vector.

    if (it->numCuenta == cuentaSolicitada){
      cuentas.erase(it);
      return true;
    }
    it++; //ir al siguiente elemento (es aleatorio el siguiente , pero no se repiten)
  }
  return false;
}

int main(int argc, char *argv[]) {

  char opcion;
  //Cuenta * cuentas[10];
  vector<Cuenta> cuentas;

//poner cuentaseleccionada a null

  Cuenta * cuentaSelecionada = NULL;
  //string nombres[10] = {"Juan","Jose","Alberto","Perico","Andres","Puertos","Paco","Pepe","Pepito","Javi",};

  inicializarCuentas(&cuentas);
  mostrarCuentas(cuentas);

  while (true) {

    menu();
    cin >> opcion;

    switch (opcion) {

      case '1':
          cuentaSelecionada = seleccionarCuenta(cuentas);
        break;
      case '2':
        if(cuentaSelecionada){ // este if es igual que cuentaSeleccionada != NULL
          ingresar(cuentaSelecionada);
        }
        break;
      case '3':
        if(cuentaSelecionada){
          reintegrar(cuentaSelecionada);
        }
        break;
      case '4':
        if(cuentaSelecionada){
          mostrarSaldo(cuentaSelecionada);
        }
        break;
      case 'b':
          borrarCuenta(cuentas);
          cuentaSelecionada = NULL;
        break;
      case '5': exit(0);
    };

    cout <<"Pulsa una tecla para contiuar." << endl;
    cin >> opcion;

  }

}
