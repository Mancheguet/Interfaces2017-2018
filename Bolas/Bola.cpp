#include "Bola.h"

using namespace std;

Bola::Bola(){}

Bola::Bola(float x, float y, float vx, float vy, float tam){

    posX = x;
    posY = y;
    velX = vx;
    velY = vy;
    tamanyo = tam;

}

void Bola::mover(float anchura, float altura){

    if (posX > (anchura-tamanyo)) velX = -fabs(velX);
    if (posX < 0) velX = fabs(velX);
    if (posY > (altura-tamanyo)) velY = -fabs(velY);
    if (posY < 0) velY = fabs(velY);

    posX += velX;
    posY += velY;

}
