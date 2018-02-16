#include <QPainter>
#include <QColor>
#include <stdlib.h>
#include <math.h>
#include <QMenu>
#include <QMenuBar>
#include <QBrush>
#include "MainWindow.h"

MainWindow::MainWindow ( QWidget * parent , Qt::WindowFlags flags ) :
		 QMainWindow(parent,flags) {
	Bola::totalBolas=0;
	Bola::diametro=40;
	resize(800,600);

	temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(50);

	connect(temporizador,SIGNAL(timeout()),this,SLOT(slotRepintar()));
	temporizador->start();

  dInfoBolas=NULL;
	dInfoTabla = NULL;
	dControlBolas=NULL;
	dVitalizar=NULL;
	inicializarBolas();
	//inicializarWidgetsVitalizar();
	inicializarMenus();

	mouseEventDentro=true;
	dVitalizar = NULL;

}

/////////////////////////////////////
///////////// funciones /////////////
////////////////////////////////////

void MainWindow::inicializarMenus(){

	accionDInformacion = new QAction("ver Info",this);
	QMenu *menuFichero = menuBar()->addMenu("Archivo");

	menuFichero->addAction(accionDInformacion);

        accionDInfoBolas = new QAction("Inform. Bolas",this);
	QMenu *menuDialogos = menuBar()->addMenu("Dialogos");
	menuDialogos->addAction(accionDInfoBolas);

accionDInfoTabla =new QAction("Tabla",this);
menuDialogos->addAction(accionDInfoTabla);

accionDControlBolas =new QAction("Control",this);
menuDialogos->addAction(accionDControlBolas);

	connect(accionDInformacion,SIGNAL(triggered()),
		this, SLOT(slotDInformacion()));

	connect(accionDInfoBolas,SIGNAL(triggered()),
		this, SLOT(slotDInfoBolas()));

	connect(accionDInfoTabla,SIGNAL(triggered()),
		this, SLOT(slotDInfoTabla()));

	connect(accionDControlBolas,SIGNAL(triggered()),
		this, SLOT(slotDControlBolas()));
}

void MainWindow::inicializarBolas(){

	for (int i = 0; i<10; i++) {
		float px = random() % width();
		float py = random() % height();
		float vel = random() % 3 + 1;
		/*** examen **/
		float vx = (random() % 1000) / 200.1 - 2.501;
		vx = vx * vel;
		float vy = (random() % 1000) / 200.1 - 2.51;
		vy = vy * vel ;
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

void MainWindow::mousePressEvent(QMouseEvent *event){

	//qDebug()<< "Funciona!";

	if(mouseEventDentro && dVitalizar == NULL){

		//dVitalizar=new DVitalizar(&widgetsDeVitalizar, this);
		dVitalizar=new DVitalizar(bolas, this);
		dVitalizar->show();
		mouseEventDentro=false;

	} else {

		dVitalizar->close();
		delete dVitalizar;
		dVitalizar = NULL;
		mouseEventDentro=true;

	}


}

//////////////////////////////////
/////// slots ///////////////////
////////////////////////////////

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
