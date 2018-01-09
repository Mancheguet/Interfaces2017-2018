#include <QtGui>

//#include <math.h>

#include "MainWindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) : QMainWindow (parent, flags){

    //dar tamaño a la pantalla main.
    resize(800, 600);

    temporizador = new QTimer();
    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotRepintar()));
    temporizador->setInterval(100);
    temporizador->setSingleShot(false);
    temporizador->start();

    inicializarBolas();
}


///////////
//METHODS//
///////////
void MainWindow::inicializarBolas(){

    for (int i=0; i<10; i++) {
      //Creo la bola y le doy una velocidad de inicio y posición
        //posición en la que salen y velocidad en la que salen
        bolas.append(new Bola(rand()%(width()-100),
                              rand()%(height()-20),
                              (float)(rand()%100)/5-1,
                              (float)(rand()%100)/5-1,
                              30)); //Este valor es el tamaño de las bolas.
    }
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter pintor(this);
    //Color para los elementos creados por el QPainter.
    QColor colorBola("#00ff2a");
    Qt::BrushStyle style = Qt::SolidPattern;
    QBrush brush(colorBola, style);
    pintor.setBrush(brush);
    foreach (Bola *unaBola, bolas){

        pintor.drawEllipse (unaBola->posX, unaBola->posY, unaBola->tamanyo, unaBola->tamanyo);
    }

    /* PINTADO DE RECTANGULO,...
     * QUE SE ENSANCHA CON CAMBIO TAMAÑO VENTANA:
     *
     * static int anchura = 50;
     * QPainter pintor(this);
     * pintor.fillRect(10, 10, anchura, 100, QColor(QString("red")));
     * anchura += 5;
     */
}



///////////
///SLOTS///
///////////

void MainWindow::slotRepintar(){

    // update() es un slot.
    update();

    float limiteDerecho = this->width();
    float limiteInferior = this->height();

    for (int i = 0; i < bolas.size(); i++){

        bolas[i]->mover(limiteDerecho, limiteInferior);
    }


    /*ANTES DE PASARLO A CLASE BOLA
    posX += velX;
    posY += velY;

    if (posX > (this->width()-anchura)) velX = -fabs(velX);
    if (posX < 0) velX = fabs(velX);
    if (posY > (this->height()-altura)) velY = -fabs(velY);
    if (posY < 0) velY = fabs(velY);
    */

    /* VERSION CON BOOLEANOS
     *
     * if (posX > (800-anchura)) derecha = false;
     * if (posY > (600-altura)) abajo = false;
     * if (posX < 0) derecha = true;
     * if (posY < 0) abajo = true;
     *
     * if (derecha) posX += velX;
     * else posX -= velX;
     * if (abajo) posY += velY;
     * else posY -= velY;
     */
}
