#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) : QMainWindow (parent, flags){

    //dar tamaño a la pantalla principal
    resize(800, 600);

    //control if
    bool control = true;

    //inicio el tmeporizador para hacer que las bolas tengan la animación
    temporizador = new QTimer();
    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotRepintar()));
    temporizador->setInterval(20); //intervalo en milisegundos
    temporizador->setSingleShot(false); //para que no lo haga solo una vez...
    temporizador->start();

    inicializarBolas();

}


///////////////////////////////////
///////////// METHODS /////////////
///////////////////////////////////

void MainWindow::inicializarBolas(){

    for (int i=0; i<100; i++) {
      //Creo la bola y le doy una velocidad de inicio y posición
        //posición en la que salen y velocidad en la que salen
        bolas.append(new Bola(rand()%(width()-100),
                              rand()%(height()-20),
                              (float)(rand()%100)/25-1,
                              (float)(rand()%100)/25-1,
                              50)); //Este valor es el tamaño de las bolas.
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
        //LO MISMO PERO CON RECTANGULOS !!!!
        //puedo poner también las dos cosas a la vez :)
        //pintor.fillRect(unaBola->posX, unaBola->posY, unaBola->tamanyo, unaBola->tamanyo, QColor(QString("red")));

        /* Meter una imagen !!!! */
          QPixmap pixmap1("./img/doge.png"); //declaro la imagen , y dónde está
          //ver tamaño real dónde esta el doge
          //pintor.drawEllipse (unaBola->posX, unaBola->posY, unaBola->tamanyo, unaBola->tamanyo);
          pintor.drawPixmap(unaBola->posX, unaBola->posY, unaBola->tamanyo, unaBola->tamanyo, pixmap1);
        /* */

        /* añadir gif !!!!

        QMovie *movie=new QMovie("./img/pizza.gif");

        // Play GIF
        QLabel* label = new QLabel(this);
        label->setGeometry(30,30,30,30);
        label->setMovie(movie);
        movie->start();

         */

        /////////// parte normal de bolas /////////////
        //pintor.drawEllipse (unaBola->posX, unaBola->posY, unaBola->tamanyo, unaBola->tamanyo);

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



////////////////////////////////
///////////// SLOTS ////////////
////////////////////////////////

void MainWindow::slotRepintar(){

    // update() es un slot para refrescar la pantalla
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
