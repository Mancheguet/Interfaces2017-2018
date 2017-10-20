#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


void inicializar (vector<int> &numeros, int cant){

  for (int i = 0 ; i< cant; i++)
    //Número aleatorio entre 100 para quedarse con el resto de dos números.
    numeros.push_back(rand()%100);
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

int main(int argc, char *argv[]){

  vector<int> numeros;

  inicializar(numeros, 15);
  mostrar(numeros);
  //burbuja(numeros);
  seleccion(numeros);
  //intercambiar(numeros, 2, 4);
  mostrar(numeros);

  //cout << "Mínimo del vector es: " << numeros[posMin(numeros)] << endl;

  //  cout << "Dirección: " << minimo(numeros) << endl;
  //  cout << "Número mínimo: " << *minimo(numeros) << endl;
}
