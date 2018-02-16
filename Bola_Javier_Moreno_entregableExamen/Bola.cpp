#include <stdlib.h>
#include <math.h>
#include "Bola.h"


int Bola::diametro;
int Bola::totalBolas;
Bola::Bola(float x, float y ,float vx ,float vy):
	posX(x),posY(y),velX(vx),velY(vy) {

	color = QColor(000,255,000);
	vida = vidaInicial;
	resaltada = false;

	numBola =QString::number(totalBolas);
	totalBolas++;
}

void Bola::mueve(int anchura,int altura){
	posX = posX+ velX;
	posY=posY+ velY;

	if (posX > anchura - 40 )
		 velX = -fabs(velX);
	if (posY > altura - 40 )
		velY = -fabs(velY);

	if (posX < 0 ) velX = fabs(velX);
	if (posY < 0) velY = fabs(velY);


}

void Bola::pinta(QPainter & pintor){
	pintor.setBrush(color);


	if (resaltada) {
		QBrush brush;
		brush.setStyle(Qt::FDiagPattern);
		pintor.setBrush(brush);
	}
	pintor.drawEllipse(posX,posY,Bola::diametro,Bola::diametro);
/* pintamos las barritas de la vida */
    int  ancho = diametro;
    float anchoVerde= (((float)vida) / vidaInicial) * (float)ancho;
    float anchoRojo = (ancho - (float)anchoVerde);
    pintor.setBrush(Qt::green);
    pintor.drawRect(posX,posY,anchoVerde,3);
    pintor.setBrush(Qt::red);
    pintor.drawRect(posX + anchoVerde,posY,anchoRojo,3);
pintor.setBrush(Qt::black);
/*** examen **/
pintor.drawText(posX+5,posY+20,QString::number(vida));
pintor.drawText(posX, posY-20,numBola);
}

float Bola::distancia(Bola * otra){
  float dist;
  dist = sqrtf( powf((posX+diametro/2) - (otra->posX+otra->diametro/2),2) +
                powf((posY+diametro/2) - (otra->posY+otra->diametro/2),2 ) );
  return dist;
}

/*** examen **/
void Bola::quitaVida(int impacto){
	vida = vida - impacto;
	int green = color.green()-5 >10 ? color.green() - 5 : 0 ;
	int red = color.red()< 250 ? color.red()+5 : 255 ;
	color = QColor(red,green,0);
}

int Bola::choca(Bola *otra){
/*** examen **/
  float colisionX=0 ,colisionY=0;

 if (this == otra)
	return 0;
 if ( distancia (otra) >  ( diametro  + otra->diametro ) / 2  )
        return 0;

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
        abajo =  otra;
    } else {
        arriba = otra;
        abajo = this;
    }
    if ( izquierda->velX > derecha->velX ) {
        float aux = derecha->velX;
        derecha->velX=izquierda->velX;
        izquierda->velX = aux;
				/*** examen **/
				colisionX = fabs(fabs(derecha->velX) - fabs(izquierda->velX));
	      rebota = true;
    }
    if ( arriba->velY > abajo->velY ) {
        float aux = arriba->velY;
        arriba->velY = abajo->velY;
        abajo->velY = aux;
				/*** examen **/
				colisionY = fabs(fabs(arriba->velY) - fabs(abajo->velY));
	      rebota =true;
    }
		/*** examen **/
	return (colisionX + colisionY) ;
}
