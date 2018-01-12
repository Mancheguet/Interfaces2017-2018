#include "Bola.h"

using namespace std;

int Bola::diametro;

Bola::Bola(){}

Bola::Bola(float x, float y, float vx, float vy):
                          posX(x), posY(y), velX(vx), velY(vy) {

    /* Ahora tenemos esto puesto diretcamente en el constructor y no hace falta ponerlo aquí */
    /*
    posX = x;
    posY = y;
    velX = vx;
    velY = vy;
    */

}

void Bola::mover(float anchura, float altura){

    if (posX > (anchura-Bola::diametro)) velX = -fabs(velX);
    if (posX < 0) velX = fabs(velX);
    if (posY > (altura-Bola::diametro)) velY = -fabs(velY);
    if (posY < 0) velY = fabs(velY);

    posX += velX;
    posY += velY;

}
/*
void Bola::pintar(QPainter& pinto){

  pintor.setBrush(color);
  pintor.drawEllipse(posX,posY,diametro,diametro);

}
*/
