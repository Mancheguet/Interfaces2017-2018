
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define BORRARPANTALLA    for (int i=0; i<10 ; i++) cout << endl;


void menu(void){


   BORRARPANTALLA
   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        b - Borrar Cuenta " << endl;
   cout << "        5 - Salir a MSDOS " << endl;
   BORRARPANTALLA
}


class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;

  Cuenta(){}

  Cuenta(string tit,string numC, float s){
    titular = tit;
    numCuenta = numC;
    saldo = s;
  }

   void ingresar(float cantidad    ){
    saldo +=  cantidad;
    }

   bool retirar(float cantidad){

      if (saldo < cantidad) {
        return false;
    }

    saldo -=cantidad;
    return true;
}

private:
    float interes;
};



void ingresar(Cuenta *c) {

    cout << "Has elegido ingresar. Escribe la cantidad" << endl;
    int cantidad;
    cin >> cantidad;
    (*c).ingresar(cantidad);

}

void reintegrar(Cuenta *c) {
    cout << "Has elegido reintegrar. Escribe la cantidad" << endl;
    int cantidad;
    cin >> cantidad;
    if (c->retirar(cantidad) )
        cout << "Todo Ok, dinero retirado"<< endl;
    else
        cout << "No hay bastante dinero" << endl;
}

void mostrarSaldo(Cuenta c) {
    cout << "Has elegido ver el Saldo" << endl;
    cout << "El saldo de la cuenta " << c.numCuenta << " es " << c.saldo <<endl;
}



void inicializarCuentas(vector<Cuenta> * cuentas) {

    for (int i=0 ; i < 4; i+=2) {
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

            cuentas->push_back(  Cuenta(nombre,numCuenta,0)) ;

     }

}
void mostrarCuentas(vector<Cuenta> cuentas) {

    cout << "Titular  ";
    for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].titular ;
    cout <<endl<< "numCuenta" ;
    for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].numCuenta ;
    cout <<endl<< "Saldo    " ;
    for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].saldo ;

   cout <<endl<< "Pulsa pa empezar"<< endl;

}

Cuenta * seleccionarCuenta(vector<Cuenta> & cuentas) {
    string cuentaSolicitada;
    cout <<"Escribe el número d ecuenta a seleccionar"<<endl;
    cin >> cuentaSolicitada;

    for (int i = 0 ; i < cuentas.size(); i++)
        if (cuentas[i].numCuenta == cuentaSolicitada )
            return & cuentas[i];

    return NULL;

}
/*
void borrarCuentas(Cuenta * cuentas[]) {
    string cuentaSolicitada;
    cout <<"Escribe el número d ecuenta a borrar"<<endl;
    cin >> cuentaSolicitada;

    for (int i = 0 ; i < 10; i++) {
        if ( (lasCuentas[i]!=NULL)
            &&
             (lasCuentas[i]->numCuenta == cuentaSolicitada ) )
            {
                delete lasCuentas[i];
                lasCuentas[i] = NULL;
            }// if
    }

    return;



}
*/

int main(int argc, char *argv[]) {

    //int cuentaSeleccionada = -1;  // soy pesimista
    Cuenta * cuentaSeleccionada = NULL ; // null es pesimista

    char opcion;
    string nombres[10]= {"juan","perico","andres","fulano","sotano","vegano","juan","juan","juan","juan"};
    //Cuenta * cuentas[10];

    vector<Cuenta> cuentas;

    //  cuentas[5].ingresar(100); <- esto es correcto (no en esta línea)



    inicializarCuentas(&cuentas);

    mostrarCuentas(cuentas);
     cin >>opcion;

  while (true) {
    menu();
    cin >> opcion;

    switch (opcion) {
        case '1': cout << "Has elegido la opción de elegir una cuenta" << endl;
              cuentaSeleccionada = seleccionarCuenta(cuentas);
              break;

        case '2': if (cuentaSeleccionada != NULL )
                ingresar(cuentaSeleccionada );
              break;

            case '3': if (cuentaSeleccionada)
                reintegrar(cuentaSeleccionada);
              break;

        case '4': if (cuentaSeleccionada )
                mostrarSaldo(*cuentaSeleccionada);
              break;

        case 'b':  /*borrarCuenta(cuentas);
              cuentaSeleccionada = NULL; // for if the flies.*/
              break;
        case '5':
              exit(0);
    } ;
    cout<< "pulsa una tecla pa seguir"<< endl ;
    cin >> opcion;
  }
}

Cuenta cuentas[10];








void inicializarCuentas(Cuenta cuentas[10]) {

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

        Cuenta c(nombre,numCuenta,0); // 0 es el saldo

     }

}
