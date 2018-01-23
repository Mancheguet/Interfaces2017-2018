#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) : QMainWindow (parent, flags){

    Bola::diametro=60;
    //dar tamaño a la pantalla principal
    resize(800, 600);

    //

    //inicio el tmeporizador para hacer que las bolas tengan la animación
    temporizador = new QTimer();
    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotRepintar()));
    temporizador->setInterval(20); //intervalo en milisegundos
    temporizador->setSingleShot(false); //para que no lo haga solo una vez...
    temporizador->start();

    inicializarBolas();

    //llamar a los dos metodos de creación
    createActions();
    createMenus();

    setMouseTracking(true);//Hacemos el track del mouse

}


///////////////////////////////////
///////////// METHODS /////////////
///////////////////////////////////

void MainWindow::inicializarBolas(){

    for (int i=0; i<10; i++) {
      //Creo la bola y le doy una velocidad de inicio y posición
        //posición en la que salen y velocidad en la que salen
        bolas.append(new Bola(rand()%(width()-100),
                              rand()%(height()-20),
                              (float)(rand()%100)/25-1,
                              (float)(rand()%100)/25-1));
    }

    //Crear bola jugador
    bolaJugador = new Bola(rand()%(width()-100),rand()%(height()-20),
    (float)(rand()%100)/25-1,(float)(rand()%100)/25-1);

}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter pintor(this);

    foreach (Bola *unaBola, bolas){

      /* Meter una imagen !!!! */
        //QPixmap pixmap1("./img/doge.png"); //declaro la imagen , y dónde está
        //pintor.drawPixmap(unaBola->posX, unaBola->posY, Bola::diametro, Bola::diametro, pixmap1);
        //Color para los elementos creados por el QPainter.
        QColor colorBola("#00ff2a");
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush(colorBola, style);

        pintor.setBrush(brush);
        unaBola->pinta(pintor);


    }

    //Pintamos al jugador

    //Color para los elementos creados por el QPainter.
    QColor colorBola("#ffffff");
    Qt::BrushStyle style = Qt::SolidPattern;
    QBrush brush(colorBola, style);

    pintor.setBrush(brush);
    bolaJugador->pinta(pintor);

    //le pones el Foco en el mainWindow
    setFocus();

}

void MainWindow::createActions(){

  //Sección MENÚ
  //Crear el QAction de Salir para poder luego ya , implementarlo en nuestro menú
  accionSalir = new QAction(QIcon("./img/exit.png"),"&Salir",this); //Crea la accionSalir con el nombre Salir y la ventana principal
  //Conectar la señal accionsalir con la acción que va a realizar (signal trigger es la opción de "disparado")
  connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));
  accionSalir->setShortcut(tr("Ctrl+q"));

  //Opcion llamar al nuevo dialogo
  accionDialog = new QAction(QIcon("./img/nuevo.png"), "Información", this);
  connect(accionDialog, SIGNAL(triggered()), this, SLOT(slotAbirDialog()));
  accionDialog->setShortcut(tr("Ctrl+i"));

  //Opcion llamar al nuevo dialogo
  accionInfoTabla = new QAction(QIcon("./img/nuevo.png"), "InfoTabla", this);
  connect(accionInfoTabla, SIGNAL(triggered()), this, SLOT(slotInfoTabla()));
  accionInfoTabla->setShortcut(tr("Ctrl+f"));

}


void MainWindow::createMenus(){

  //Por defecto  QMainWindow , ya tiene una Barra de menú , tenemos que añadir un objeto a la barra de menu
  //I Luego , agregar al Menu , las QAction
  fileMenu = menuBar()->addMenu("&Archivo"); //Añado a la Barra de menus la opción Archivo
  fileMenu->addAction(accionDialog);
  fileMenu->addAction(accionInfoTabla);
  fileMenu->addAction(accionSalir); //Añado al menuArchivo la acciuon Salir

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

        for (int j = 0; j < bolas.size(); j++) {
            if(bolas[i]->choca(bolas[j])){
                bolas[i]->vida--;
                bolas[j]->vida--;
                }
            }

            bolas[i]->mover(limiteDerecho, limiteInferior);
        }




    //parte de bolasJugador
    for (int x = 0; x < bolas.size(); x++) {
        if(bolaJugador->choca(bolas[x])){
            bolaJugador->vida--;
            bolas[x]->vida--;
            if(bolas[x]->vida<=0){
              delete bolas[x];
              bolas.remove(x);
              break;
            }
        }
    }

    bolaJugador->mover(limiteDerecho, limiteInferior);

    for (int x = 0; x < bolas.size(); x++) {
      if(bolas[x]->vida<=0){
        delete bolas[x];
        bolas.remove(x);
        break;
      }

    }

}

void MainWindow::slotAbirDialog(){

  Dialog *dialogo = new Dialog(bolas.size(),this->width(),this->height(),this);
  //dialogo->nBolas->setText(QString::number(bolas.size()));
  //dialogo->tVentana->setText(QString::number(this->width())+"  x  "+QString::number(this->height()));
  dialogo->show();

}

void MainWindow::keyPressEvent(QKeyEvent *event){

    //cuando apretamos las teclas de flechas , que aumente o disminuya la velocidad
    switch (event->key()) {

      case Qt::Key_Up:
        bolaJugador->velY--;
        break;
      case Qt::Key_Down:
        bolaJugador->velY++;
        break;
      case Qt::Key_Left:
        bolaJugador->velX--;
        break;
      case Qt::Key_Right:
        bolaJugador->velX++;
        break;

    }


}

void MainWindow::mousePressEvent(QMouseEvent *event){

  posIX=event->x();
  posIY=event->y();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){

  float velocidadX = (event->x()-posIX)/30.3;
  float velocidadY = (event->y()-posIY)/30.3;

  bolas.append(new Bola(posIX,
                        posIY,
                        velocidadX,velocidadY));

}

 void MainWindow::mouseMoveEvent(QMouseEvent *event){

    float magnitudX = (event->x()-bolaJugador->posX)/600.3;
    float magnitudY = (event->y()-bolaJugador->posY)/600.3;

    bolaJugador->velX+=magnitudX;
    bolaJugador->velY+=magnitudY;

 }

void MainWindow::slotInfoTabla(){
  if(dInfoTabla==NULL){
    dInfoTabla = new DInfoTabla();
  }
  dInfoTabla->show();
}
