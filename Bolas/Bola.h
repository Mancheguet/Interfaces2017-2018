#ifndef _BOLA_H
#define _BOLA_H

#include <QApplication>
#include <QMainWindow>

#include <math.h>

class Bola {

    public :

        static int diametro;
        float posX, posY, velX, velY;

        Bola();
        Bola(float x, float y, float vx, float vy);

        void mover(float anch, float alt);
        void pintar(QPainter& pintor);

};

#endif
