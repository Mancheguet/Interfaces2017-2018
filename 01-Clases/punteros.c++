#include <iostream>
using namespace std;

void incrementar (int * direccion){

  (*direccion)++; //tenemos que poner la recuperación de la direccion entre parentesis primero y luego
  //incrementar , porque sino incrementa primero y lo que incrementa es la direccion de memoria y no el numero.

}

void incrementar2 (int & referencia){ //me van a pasar un Int en el cual voy a "hacer referencia"(&) con el nombre referencia
  //referencia , es una referencia de i ( o el argumento pasado )
  referencia++;

}

int mac(int i, int j){

  if( i > j ) return i;
  return j;

}

int main(int argc, char *argv[]) {

    int i;
    int j = 8;
    int c = mac (j,i);

    //int &j = i; //Declara una referencia , que es otro nombre para una variable ya existente. Ahora j e i són lo mismo.
    //Es decir , ahora i también se llama j (I tiene ahora el "mote" de j). Desde primer hora ya tienes que
    //poner a que variable va a hacer referencia.

    int * p; //Declaración de un puntero. Un puntero es una variable que guarda la direccion de memoria de otra variable
    //int -> Hace referencia al tipo de datos que tiene la variable que a la que apuntamos en p (en este caso
    // apuntaremos a i , y i es un int ). * dice que p va a ser un puntero
    // p es el nombre del puntero.

    i = 7;

    //quiero que p contenga la direccion de memoria de i

    //p = &i; // ( &i )  recupera la direccion de memoria i se le asigna a p. En P ahora tengo la direccion de i.
    //"*" antes de la p dice que -> accede a lo que referencia p ( en este caso i), a lo apuntado por p
//    *p = 5; //accedemos a la posición de memoria a la que apunta p (que es la variable i) y le  guardamos el 5

    incrementar(&i); //le pasamos la direccion de i
    incrementar2(i); //le pasamos i y la funcion le hará una referencia

    //cout << "El valor de i es : " << i << endl;
    cout << "El maximo entre " << i << " y " << j << " es " << c << endl;
}
