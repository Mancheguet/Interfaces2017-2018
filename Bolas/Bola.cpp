#include "Bola.h"

using namespace std;

int Bola::diametro;

Bola::Bola(){}

Bola::Bola(float x, float y, float vx, float vy):
                          posX(x), posY(y), velX(vx), velY(vy) {

    vida = Bola::vidaInicial;

}

void Bola::mover(float anchura, float altura){

    if (posX > (anchura-Bola::diametro)) velX = -fabs(velX);
    if (posX < 0) velX = fabs(velX);
    if (posY > (altura-Bola::diametro)) velY = -fabs(velY);
    if (posY < 0) velY = fabs(velY);

    posX += velX;
    posY += velY;

}

void Bola::pinta(QPainter& pintor){

  pintor.drawEllipse(posX,posY,Bola::diametro,Bola::diametro);
  pintor.drawText(posX+(20),posY+(20),QString::number(this->vida));
  /* pintamos las barritas de la vida */
      int  ancho = diametro;
      float anchoVerde= (((float)vida) / vidaInicial) * (float)ancho;
      float anchoRojo = (ancho - (float)anchoVerde);
      pintor.setBrush(Qt::green);
      pintor.drawRect(posX,posY,anchoVerde,3);
      pintor.setBrush(Qt::red);
      pintor.drawRect(posX + anchoVerde,posY,anchoRojo,3);

}

float Bola::distancia(Bola * otra){
  float dist;
  dist = sqrtf( powf((posX+diametro/2) - (otra->posX+otra->diametro/2),2) +
                powf((posY+diametro/2) - (otra->posY+otra->diametro/2),2 ) );
  return dist;
}

bool Bola::choca(Bola * otra) {


    if(this == otra){
      return false;
    }

    if ( distancia (otra) >  ( diametro  + otra->diametro ) / 2  )
        return false;


    bool rebota = false;

    Bola * izquierda, *derecha ;
    Bola * arriba, * abajo ;

    if (posX <  otra->posX )  {
        izquierda = this;
        derecha = otra;
    } else {
        izquierda = otra;
        derecha = this;
    }

    if (posY <  otra->posY )  {
        arriba = this;
        abajo = otra;
    } else {
        arriba = otra;
        abajo = this;
    }

    if ( izquierda->velX > derecha->velX ) {
            float aux = derecha->velX;
            derecha->velX=izquierda->velX;
            izquierda->velX = aux;
            rebota = true;
    }

    if ( arriba->velY > abajo->velY ) {
            float aux = arriba->velY;
            arriba->velY = abajo->velY;
            abajo->velY = aux;
            rebota=true;
    }

    return rebota;

}
