#include <iostream>
using namespace std;

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

void reintegrar(Cuenta * pCuen){

    float cantidad;
    cout << "Dime una cantidad a reintegrar :  ";
    cin >> cantidad;

    //Se tiene que poner *pCuen entre parentesis paraa que recupere primero el objeto
    //y luego ejecute el metodo : (*pCuen).retirar(cantidad)
    // tambien se puede hacer con la flecha : pCuen->retirar(cantidad)
    if ( (*pCuen).retirar(cantidad) ){
      cout << "Se han podido retirar " << cantidad << " euros . Saldo = " << (*pCuen).saldo <<endl;
    } else {
      cout << "No se ha podido retirar " << cantidad << " euros . Saldo = " << (*pCuen).saldo <<endl;
    }

}

int main(int argc, char *argv[]) {

cout << "bienvenido al banco" <<endl;
// System.out.println("bienvenido al banco");

    Cuenta c;

    //se crea un objecto y a ese objeto se le llama c
    c.titular = "pepe";
    c.numCuenta ="001";
    c.saldo = 10.04 ;

    cout << " la cuenta " << c.numCuenta << " de " << c.titular
        << " tiene " << c.saldo << " euros " <<endl;

        //voy a ingresar dinero;

    c.ingresar(1000);

        //voy a sacar dinero;

    reintegrar(&c);

    cout << "Saldo " << c.saldo << endl;







//    Cuenta c2;

//    c2=c;

//    cout << "Imprimo los valores de c2 una vez igualadas." << endl;
//    cout << " la cuenta c2 " << c2.numCuenta << " de " << c2.titular
//        << " tiene " << c2.saldo << " euros " <<endl;

//    cout << "Con cambio variable en c2" << endl;
//    c2.saldo = 20.03 ;

//    cout << " la cuenta c2 " << c2.numCuenta << " de " << c2.titular
//        << " tiene " << c2.saldo << " euros " <<endl;
//    cout << " la cuenta c " << c.numCuenta << " de " << c.titular
//        << " tiene " << c.saldo << " euros " <<endl;
//conclusion , se han creado dos objetos totalmente diferentes



}
