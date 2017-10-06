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

    Cuenta(string tit, string numC, float s){

      titular = tit;
      numCuenta = numC;
      saldo = s;

    }

    Cuenta(){ //constructor vacio

    }

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
   cout << "        b - Borrar cuenta " << endl;
   cout << "        5 - Salir a MSDOS " << endl;

  //lineas en blanco
  BORRARPANTALLA

}

Cuenta * seleccionarCuenta(Cuenta * cuentas[]){
    string numCuenta;
    cout << "Dime el numero de cuenta : " << endl;
    cin >> numCuenta;

    for (int i=0 ; i < 10; i++) {
      //compruebo si existe la cuenta (no esta a null) y luego , si el numerocuenta existe
      //resulta que si haces directament un if a cuentas(i) , mira si esta a NULL
      //si lo esta, retorna false
        if( cuentas[i] && numCuenta == (cuentas[i]->numCuenta)){
          return cuentas[i];
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

void inicializarCuentas(Cuenta * cuentas[10]) {

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
        cuentas[i] = new Cuenta(nombre,numCuenta,0); // creo una cuenta i me guardo su direccion en cuentas

     }

}


void mostrarCuentas(Cuenta * cuentas[]){

  cout << "Titular" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << "\t" << cuentas[i]->titular;
  }
  cout << endl << "NumCuenta" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << cuentas[i]->numCuenta << "\t";
  }
  cout << endl << "Saldo" << "\t";
  for (int i=0 ; i < 5; i++) {
    cout << "\t" << cuentas[i]->saldo;
  }

}

void borrarCuenta(Cuenta * cuentas[]){
  string numCuenta;
  cout << "Dime el numero de cuenta "<< endl;
  cin >> numCuenta;

  for (int i=0 ; i < 10; i++) {
      if( cuentas[i] && numCuenta == (cuentas[i]->numCuenta)){
        delete cuentas[i];
        cuentas[i] = NULL;
      }
  }

}

int main(int argc, char *argv[]) {

  char opcion;
  Cuenta * cuentas[10];

//inicializar todas las cuentas a null

//  for(int i=0; i<10; i++){
//    cuentas[i] = NULL;
//  }

  //es lo mismo que la forma de arriba
  for(int i=0; i<10; cuentas[i] = NULL, i++);

//poner cuentaseleccionada a null

  Cuenta * cuentaSelecionada = NULL;
  //string nombres[10] = {"Juan","Jose","Alberto","Perico","Andres","Puertos","Paco","Pepe","Pepito","Javi",};

  inicializarCuentas(cuentas);
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
