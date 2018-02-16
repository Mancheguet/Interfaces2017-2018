#include "DVitalizar.h"

 DVitalizar::DVitalizar(QVector<Bola*> bolasAux, QWidget *parent)
      : QDialog(parent)
  {

	setupUi(this);

  inicializarWidgetsVitalizar(bolasAux);

  contador=0;

  connect(botonSiguiente, SIGNAL(clicked()),this,SLOT(slotSiguiente()));
  connect(botonAnterior, SIGNAL(clicked()),this,SLOT(slotAnterior()));
  connect(botonBuscar,SIGNAL(clicked()),this,SLOT(slotBuscar()));

  inciarUna();

}

void DVitalizar::inicializarWidgetsVitalizar(QVector<Bola*> bolas){

	for (int i = 0; i < bolas.size(); i++) {

		widgetsDeVitalizar.append(new WidgetVitalizar(bolas[i]));

	}

}

void DVitalizar::inciarUna(){

    layoutFrame->addWidget(widgetsDeVitalizar[contador]);
    widgetsDeVitalizar[contador]->pintarVida();
    widgetsDeVitalizar[contador]->pintarNumero();

}

void DVitalizar::slotSiguiente(){

    layoutFrame->removeWidget(widgetsDeVitalizar[contador]);
    contador++;
    layoutFrame->addWidget(widgetsDeVitalizar[contador]);
    widgetsDeVitalizar[contador]->pintarVida();
    widgetsDeVitalizar[contador]->pintarNumero();

}
void DVitalizar::slotAnterior(){

  layoutFrame->removeWidget(widgetsDeVitalizar[contador]);
  contador--;
  layoutFrame->addWidget(widgetsDeVitalizar[contador]);
  widgetsDeVitalizar[contador]->pintarVida();
  widgetsDeVitalizar[contador]->pintarNumero();

}
void DVitalizar::slotBuscar(){

  layoutFrame->removeWidget(widgetsDeVitalizar[contador]);
  int vidaMenor=100;
  int posicionVida=0;

  for (int i = 0; i < widgetsDeVitalizar.size(); i++) {
      if(widgetsDeVitalizar[i]->miBola->vida < vidaMenor){
        vidaMenor=widgetsDeVitalizar[i]->miBola->vida;
        posicionVida=i;
      }
  }

  contador=posicionVida;
  layoutFrame->addWidget(widgetsDeVitalizar[contador]);
  widgetsDeVitalizar[contador]->pintarVida();
  widgetsDeVitalizar[contador]->pintarNumero();

}
