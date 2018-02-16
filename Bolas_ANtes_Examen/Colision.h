#ifndef COLISION_H
#define COLISION_H

#include "Bola.h"

class Bola; //Promesa de que habrá una clase bla para poder compilar

class Colision {

public:

  Colision();
  Colision(Bola * u, Bola * o, float x, float y);
  
  Bola * una, *otra;
  float posX, posY;

};

#endif
