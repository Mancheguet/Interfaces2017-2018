#ifndef _BOLA_H
#define _BOLA_H

#include <QApplication>
#include <QMainWindow>
#include <QPainter>

#include <math.h>

class Bola {

    public :

        static int diametro;
        const static int vidaInicial = 100;

        int vida;
        float posX, posY, velX, velY;

        bool resaltado;

        Bola();
        Bola(float x, float y, float vx, float vy);

        void mover(float anch, float alt);
        void pinta(QPainter& pintor);
        float distancia(Bola * otra);
        bool choca(Bola * otra);
        void parar();

};

#endif
