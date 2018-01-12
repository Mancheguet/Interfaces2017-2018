#ifndef _BOLA_H
#define _BOLA_H

#include <QApplication>
#include <QMainWindow>

#include <math.h>

class Bola {

    public :

        float posX, posY, velX, velY, tamanyo;

        Bola();

        Bola(float x, float y, float vx, float vy, float tamanyo);

        void mover(float anch, float alt);

};

#endif
