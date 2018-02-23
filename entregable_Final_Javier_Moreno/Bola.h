#ifndef BOLA_H
#define BOLA_H
#include <QColor>
#include <QPainter>

class Bola {
public :
//	static QVector<QPixmap> imagenes;
	static int diametro ;
	static int totalBolas;
	bool protegida;
	const static int vidaInicial=100;
	bool resaltada;
	QColor color;
	QString numBola;
	enum estado {colocado, contento, normal, cabreado, putamierda};
	int vida;
	Bola(float x, float y ,float vx ,float vy);
	void mueve(int,int);

	float posX,posY,velX,velY;
	void pinta(QPainter & p);

	float distancia(Bola * otra);
	/*** examen **/
	int choca(Bola *otraBola);
  /*** examen **/
	void quitaVida(int);

};


#endif
