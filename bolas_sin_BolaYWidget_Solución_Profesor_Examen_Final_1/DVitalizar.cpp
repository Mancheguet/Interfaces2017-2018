#include "DVitalizar.h"
#include <QMessageBox>

 DVitalizar::DVitalizar(QVector<Bola * > *p, QWidget *parent)
      : pBolas(p), QDialog(parent)
  {

	setupUi(this);
   if (p->size()== 0) return;
   w = new WidgetVitalizar(pBolas->at(0));
   w->ponBola(w->miBola);

  layoutFrame->addWidget(w);

  connect(botonSiguiente, SIGNAL(clicked()),this,SLOT(slotSiguiente()));
  connect(botonAnterior, SIGNAL(clicked()),this,SLOT(slotAnterior()));
  connect(botonBuscar,SIGNAL(clicked()),this,SLOT(slotBuscar()));
}

void DVitalizar::verificarBola(Bola *b) {
	if (w->miBola != b) return;

	int ret = QMessageBox::warning(this, tr("Peligro"),
                               tr("Bola Mostrada Borrada.\n"
                                   "Elijo otra bola?"),
                                QMessageBox::Yes | QMessageBox::Cancel,QMessageBox::Yes);
	if (ret==QMessageBox::Yes) 
		for (int i=0 ; i < pBolas->size();i++)
		 if (pBolas->at(i)->vida > 0) {
			w->ponBola(pBolas->at(i));	
			return;
		}
	
}

void DVitalizar::slotSiguiente(){
    Bola * actual = w->miBola;

    for (int i=0;i<(pBolas->size()-1);i++)
      if (pBolas->at(i) == actual) {
          w->ponBola(pBolas->at(i+1));
          return;
        }

}
void DVitalizar::slotAnterior(){

  Bola * actual = w->miBola;

  for (int i=1;i<(pBolas->size());i++)
    if (pBolas->at(i) == actual) {
        w->ponBola(pBolas->at(i-1));
        return;
      }

}
void DVitalizar::slotBuscar(){
  if (pBolas->size()==0) return;
  Bola * minima = pBolas->at(0);

  for (int i=1;i<(pBolas->size());i++)
    if (pBolas->at(i)->vida < minima->vida) {
        minima = pBolas->at(i);
      }

    w->ponBola(minima);
}

void DVitalizar::slotActualizarVida(){

  w->actualizarVida();

}
