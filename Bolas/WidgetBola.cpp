#include "WidgetBola.h"

WidgetBola::WidgetBola(Bola * bola, QWidget *parent) : QDialog(parent) {

    setupUi(this);
    this->miBola = bola;

    connect(btnParar, SIGNAL(clicked()),this, SLOT(slotParar()));
    connect(btnColor, SIGNAL(clicked()),this, SLOT(slotCambioColor()));

}


//////////////////////
/////// SLOTS ////////
/////////////////////

void WidgetBola::slotParar(){

  miBola->parar();

}

void WidgetBola::slotCambioColor(){

  QPainter pintor(this);
  
  QColorDialog dialogoCambioColor(this);
  dialogoCambioColor.exec(); //ejecutar en modal (no deja usar la de abajo -> show = no modal

    int r = dialogoCambioColor.result();

    if(r == QDialog::Accepted){

      miBola->color=dialogoCambioColor.selectedColor();
      miBola->pinta(pintor);

    }

}
