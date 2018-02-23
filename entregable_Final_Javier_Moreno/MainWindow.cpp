#include <QPainter>
#include <QColor>
#include <stdlib.h>
#include <math.h>
#include <QMenu>
#include <QMenuBar>
#include <QBrush>
#include <QMessageBox>
/*** examen **/
#include <QFile>
#include <QTextStream>

#include "MainWindow.h"

MainWindow::MainWindow ( QWidget * parent , Qt::WindowFlags flags ) :
		 QMainWindow(parent,flags) {
	Bola::totalBolas=0;
	Bola::diametro=30;
	resize(800,600);

	temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(50);

	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotRepintar()));
	temporizador->start();

        dInfoBolas=NULL;
 dInfoTabla = NULL;
 dControlBolas=NULL;
 dCargaBolas = NULL ;
	inicializarBolas();
	inicializarMenus();

}

void MainWindow::inicializarMenus(){

	accionDInformacion = new QAction("ver Info",this);
	QMenu *menuFichero = menuBar()->addMenu("Archivo");

	menuFichero->addAction(accionDInformacion);

	/*** examen **/
  accionAbrirFichero = new QAction("Abrir Fichero",this);
	menuFichero->addAction(accionAbrirFichero);

        accionDInfoBolas = new QAction("Inform. Bolas",this);
	QMenu *menuDialogos = menuBar()->addMenu("Dialogos");
	menuDialogos->addAction(accionDInfoBolas);

accionDInfoTabla =new QAction("Tabla",this);
menuDialogos->addAction(accionDInfoTabla);

accionDControlBolas =new QAction("Control",this);
menuDialogos->addAction(accionDControlBolas);

/*** examen **/

accionDCargaBolas =new QAction("Cargar",this);
menuDialogos->addAction(accionDCargaBolas);

	connect(accionDInformacion,SIGNAL(triggered()),
		this, SLOT(slotDInformacion()));

	connect(accionDInfoBolas,SIGNAL(triggered()),
		this, SLOT(slotDInfoBolas()));

	connect(accionDInfoTabla,SIGNAL(triggered()),
		this, SLOT(slotDInfoTabla()));

	connect(accionDControlBolas,SIGNAL(triggered()),
		this, SLOT(slotDControlBolas()));
		/*** examen **/
   connect(accionAbrirFichero,SIGNAL(triggered()),
 		this, SLOT(slotAbrirFichero()));

		connect(accionDCargaBolas,SIGNAL(triggered()),
		 this, SLOT(slotDCargaBolas()));



}

void MainWindow::inicializarBolas(){

	for (int i = 0; i<10; i++) {
		float px = random() % width();
		float py = random() % height();
		float vx = (random() % 1000) / 100.1 - 4.49;
		float vy = (random() % 1000) / 100.1 - 4.49;
		bolas.append( new Bola(px,py,vx,vy));
	}

		float px = random() % width();
		float py = random() % height();
		float vx = 0;//(random() % 1000) / 100.1 - 4.49;
		float vy = 0;//(random() % 1000) / 100.1 - 4.49;
		bolaJugador = new Bola(px,py,vx,vy);
}

void MainWindow::keyPressEvent(QKeyEvent *e){

	switch (e->key()) {
        case Qt::Key_Left : bolaJugador->velX -=0.2 ; break;
        case Qt::Key_Up   : bolaJugador->velY -=0.2 ; break;
        case Qt::Key_Down : bolaJugador->velY +=0.2 ; break;
        case Qt::Key_Right: bolaJugador->velX +=0.2 ; break;
};

}

void MainWindow::paintEvent( QPaintEvent * e ){

	QPainter pintor(this);
	int w =width(), h= height();
	for (int i=0;i < bolas.size(); i++){
		bolas[i]->pinta(pintor);
		bolas[i]->mueve(w,h);
	}
	if (bolaJugador != NULL) bolaJugador->mueve(w,h);
	pintor.setBrush(QBrush(Qt::cyan));
	pintor.drawEllipse(bolaJugador->posX,bolaJugador->posY,
		Bola::diametro,Bola::diametro);
}

void MainWindow::slotDInformacion(){

	DInformacion *dialoguito =
		 new DInformacion(this);

	QString letrerito = QString() + " " + QString::number(width()) + " x "+
		QString::number(height());

	dialoguito->etiquetaNumBolas->setText(letrerito);
	dialoguito -> show() ;

}


void MainWindow::slotRepintar() {
	int impacto;
	for (int i=0; i< bolas.size();i++)
		for (int j=0; j< bolas.size();j++)
		if (impacto = bolas[i]->choca(bolas[j]) ) {
							/*** examen **/
 						bolas[i]->quitaVida(impacto);
						bolas[j]->quitaVida(impacto);
	}


	for (int i=0; i<bolas.size(); i++)
		if (bolas[i]->vida <=0) {
			delete bolas[i];
			bolas.remove(i);
			break;
		}

	update();

}


void MainWindow::slotDInfoBolas(){

	if (dInfoBolas == NULL) dInfoBolas  =
		 new DInfoBolas(bolas,this);

	dInfoBolas -> show() ;
}
void MainWindow::slotDInfoTabla(){

	if (dInfoTabla == NULL) dInfoTabla  =
		 new DInfoTabla(&bolas,this);

	dInfoTabla -> show() ;
}

void MainWindow::slotDControlBolas(){

	if (dControlBolas == NULL) dControlBolas  =
		 new DControlBolas(bolas, this);

	dControlBolas -> show() ;
}
/*** examen **/
bool MainWindow::slotAbrirFichero(QVector<Bola*> &bolas){

	for (int i=0;i<bolas.size();i++){
		delete bolas[i];
		bolas.clear();
	}

    QFile fichero("bolas.dat");
      if (!fichero.open(QIODevice::ReadOnly)) {
                QMessageBox::warning(this, tr("Editor"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fichero.fileName())
                             .arg(fichero.errorString()));
				return false;
    }
 		QString strX , strY ,strRed, strGreen, strBlue ;

        QTextStream stream(&fichero);


        while (!stream.atEnd()){
					stream >> strX >> strY >> strRed >> strGreen>> strBlue ;
					if (strBlue.isEmpty()) return true;
					QColor color(strRed.toInt(),strGreen.toInt(),strBlue.toInt());
					bolas.append(new Bola(strX.toInt(),
																strY.toInt(),
																0,0));
					bolas.last()->color = color;
        }
				return true;

}


void MainWindow::slotDCargaBolas(){
  QVector<Bola *> bolasCargar;
	if (dCargaBolas == NULL){
		slotAbrirFichero(bolasCargar);
		dCargaBolas = new DCargaBolas( width(),height(), bolasCargar, &bolas);


	}
	dCargaBolas->show();

}
