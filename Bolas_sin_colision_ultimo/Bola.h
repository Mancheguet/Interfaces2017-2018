#ifndef _BOLA_H
#define _BOLA_H

#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QImage>

#include <math.h>

class Bola {

    public :

        static int diametro;
        const static int vidaInicial = 100;

        int vida;
        float posX, posY, velX, velY;

        bool resaltado;
        bool tieneImagen;

        QColor color;
        QImage imagenBola;

        Bola();
        Bola(float x, float y, float vx, float vy);

        void mover(float anch, float alt);
        void pinta(QPainter& pintor);
        float distancia(Bola * otra);
        bool choca(Bola * otra);
        void parar();
        void insertarImagen(QImage imagenMomento);

};

#endif
