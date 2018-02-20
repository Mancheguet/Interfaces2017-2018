#include <QDebug>
#include "WidgetVitalizar.h"

 WidgetVitalizar::WidgetVitalizar(Bola * bola, QWidget *parent)
      : QWidget(parent)
  {

	setupUi(this);
  temporizador = NULL;
	miBola = bola;
  actualizarVida();
  connect(botonAplicar,SIGNAL(clicked()),this,SLOT(slotAplicarVida()));
  connect(checkProteger,SIGNAL(stateChanged(int)),this, SLOT(slotProteger(int)));

}

void WidgetVitalizar::ponBola(Bola *b) {
	
 miBola = b;
 lcdNumBola->display(miBola->numBola);
 actualizarVida();
 if (miBola->protegida) checkProteger->setCheckState(Qt::Checked);
else  checkProteger->setCheckState(Qt::Unchecked);

}

void WidgetVitalizar::actualizarVida(){


    if ((miBola->vida < (Bola::vidaInicial)/2 ) && (temporizador ==NULL)) {
		qDebug() << "activando timer";
		temporizador = new QTimer();
		temporizador->setSingleShot(false);
		temporizador->setInterval(500);
		connect(temporizador,SIGNAL(timeout()),this,SLOT(slotParpadear()));
		temporizador->start();		
		}	
    if ((miBola->vida > (Bola::vidaInicial)/2 ) && (temporizador != NULL)) {
		qDebug() << "desactivando timer";
		barraVida->setVisible(true);
		delete temporizador;
		temporizador = NULL;
		barraVida->setVisible(true);
	}
    barraVida->setValue((miBola->vida*100) / Bola::vidaInicial) ;
}

void WidgetVitalizar::slotParpadear(){

	if (barraVida->isVisible()) barraVida->hide();
	else barraVida->show();

	if ((miBola->vida < (Bola::vidaInicial)/2 ) && (temporizador != NULL)) {
		temporizador->setInterval(500);
	}
	
	if ((miBola->vida < (Bola::vidaInicial)/4 ) && (temporizador != NULL)) {
		temporizador->setInterval(250);
	}

}

void WidgetVitalizar::slotAplicarVida(){
  miBola->vida += spinVida->value();
  actualizarVida();
}

void WidgetVitalizar::slotProteger(int marcado){
  if (marcado==Qt::Checked) qDebug() << "protegiendo la bola" << miBola->numBola;
  miBola->protegida =  marcado==Qt::Checked;

}
