#include <iostream>
using namespace std;


void incrementar (int & n) {

    n++;
}


int * maxReferencia (int & uno, int & dos){

  if(uno > dos)
    return &uno;
  else
    return &dos;

}

int * maxPuntero (int * uno, int * dos){

  if((*uno) > (*dos))
    return uno;
  else
    return dos;

}

int & maxM (int * x, int * y){
  if(*x>*y)
    return *x;
  else
    return *y;
}

//lo mismo que maxM por referencia
//int & maxM (int &uno, int &dos){
//  if(uno>dos)
//    return uno;
//  else
//    return dos;
//}

int main(int argc, char *argv[]) {

    int i = 7;
    int j = 8;

    //int * p ;
    // quiero que p contenga la dirección de memoria de i
    // p = &i;

    int * pR;
    int * pP;

    //cout << "La direccion i "<< &i <<endl;
    //cout << "La direccion j "<< &j <<endl;

    pR = maxReferencia (j,i);
    pP = maxPuntero (&i, &j);

    int &m = maxM(&i,&j);
    //int &m = maxM(i,j);

    *pR=0;
    *pP=0;
    m=0;

    cout << "J es igual a "<< j << " - I es igual a " << i <<endl;

}
