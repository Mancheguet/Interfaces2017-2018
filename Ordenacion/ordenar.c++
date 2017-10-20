#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


void inicializar (vector<int> &numeros, int cant){

  int min = (cant < 100 ? 100 : cant*4);
  for (int i = 0 ; i< cant; i++)
    //Número aleatorio entre 100 para quedarse con el resto de dos números.
    numeros.push_back(rand()% min);
  }

void mostrar(vector<int> &numeros) { // just for efficiency

  for (int i = 0 ; i< numeros.size(); i++)
    cout << numeros.at(i) <<"  ";
    cout << endl;
}

void intercambiar(vector<int> &numeros, int pos1, int pos2){

  int aux = numeros[pos1];
  numeros[pos1] = numeros[pos2];
  numeros[pos2] = aux;
}




/*DEVOLVER POSICIÓN MÍNIMO EN EL ARRAY*/
int posMin(vector<int> numeritos){

  int pos=0;
  for (int i = 0 ; i < numeritos.size(); i++){
    if (numeritos[i] < numeritos[pos]){
      pos = i;
    }
  }
  return pos;
}

/* DEVOLVER DIRECCION
int *minimo(vector<int> &numeros){

  int min = 100, *posMin;
  for (int i = 0 ; i< numeros.size(); i++){
    if (numeros.at(i) <= min){
      min = numeros.at(i);
      posMin = &numeros.at(i);
    }
  }
  return posMin;
}
*/

//Ordenación por burbuja.
void burbuja(vector<int> &numeros) {

  for (int i = 0; i < numeros.size(); i++){
    for (int j = 0 ; j < numeros.size()-1; j++){
      if(numeros.at(j) > numeros.at(j+1)){
        intercambiar(numeros, j, j+1);
      }
    }
  }
}

void seleccion(vector<int> &numeros) {
  int pos_min;
  for (int i = 0; i < numeros.size(); i++){
    //Buscar mínimo desde aquí hasta el final.
    pos_min = i;
    for (int j = i; j < numeros.size(); j++){
      if (numeros[pos_min] > numeros[j]){
        pos_min = j;
      }
    }
    //Esto no va dentro del for del j.
    intercambiar(numeros, i, pos_min);
  }
}



vector <int> merge(vector<int> vectorUno, vector<int> vectorDos){
  vector<int> resultado;
  int pos1 = 0 ,pos2 = 0;

  while (pos1 < vectorUno.size() && pos2 < vectorDos.size() ){

    if(vectorUno[pos1] < vectorDos[pos2] ){
      resultado.push_back(vectorUno[pos1]);
      pos1++;
    } else {
      resultado.push_back(vectorDos[pos2]);
      pos2++;
    }
  }

  while (pos1<vectorUno.size()){
    resultado.push_back(vectorUno[pos1]);
    pos1++;
  }
  while (pos2<vectorDos.size()){
    resultado.push_back(vectorDos[pos2]);
    pos2++;
  }


/* otra forma de hacer lo de los while
  if(pos1==vectorUno.size()){
    while(pos2 != vectorDos.size()){
      resultado.push_back(vectorDos[pos2]);
      pos2++;
    }
  } else {
      while(pos1 != vectorUno.size()){
        resultado.push_back(vectorUno[pos1]);
        pos1++;
      }
  }
*/
/* quea remplazado por la parte de arriba, donde veo que vector queda con numeros con if
  while (pos1 != vectorUno.size() || pos2 != vectorDos.size() ){
    if(pos1 == vectorUno.size()){
      resultado.push_back(vectorDos[pos2]);
      pos2++;
    } else if ( pos2 == vectorDos.size()){
      resultado.push_back(vectorUno[pos1]);
      pos1++;
    }
  }
*/

  return resultado;

}

void mergeSort (vector<int> & numeros){

  vector<int> mitadIzq, mitadDer;

  if(numeros.size()<=1) return;

  /* Forma de Nacho */
  /*
  int mitad = numeros.size()/2;
  int i=0;
  while (i< numeros.size()){
    if(i<mitad){
        mitadIzq.push_back(numeros[i]);
    } else {
        mitadDer.push_back(numeros[i]);
    }
    i++;
  }

  */

  for (int i = 0 ; i<(numeros.size()/2); i++){
    mitadIzq.push_back(numeros[i]);
  }
  for (int i = (numeros.size()/2) ; i<numeros.size() ;i++ ){
    mitadDer.push_back(numeros[i]);
  }

  mergeSort(mitadIzq);
  mergeSort(mitadDer);

  numeros = merge(mitadIzq,mitadDer);

}

int main(int argc, char *argv[]){

  vector<int> numeros1;
  vector<int> numeros2;

  inicializar(numeros1, 3);
  inicializar(numeros2, 100);

  cout << "Sin ordenar" <<endl;
  //mostrar(numeros1);
  mostrar(numeros2);

  mergeSort(numeros2);

  cout << "Ordenado : " << endl;
  mostrar(numeros2);
/*
  burbuja(numeros1);
  burbuja(numeros2);

  cout << "Ordenado" <<endl;
  mostrar(numeros1);
  mostrar(numeros2);

  vector<int> numeros3 = merge(numeros1,numeros2);

  cout << "Vector 3 con los anteriores ordenados: " <<endl;
  mostrar(numeros3);
*/



  /* PARA ORDENAR
  //burbuja(numeros);
  //seleccion(numeros);
  //intercambiar(numeros, 2, 4);
  */

  //mostrar(numeros);

  //cout << "Mínimo del vector es: " << numeros[posMin(numeros)] << endl;

  //  cout << "Dirección: " << minimo(numeros) << endl;
  //  cout << "Número mínimo: " << *minimo(numeros) << endl;
}
