#include "WidgetBola.h"

WidgetBola::WidgetBola(Bola * bola, QWidget *parent) : QDialog(parent) {

    setupUi(this);
    this->miBola = bola;

    connect(btnParar, SIGNAL(clicked()),this, SLOT(slotParar()));

}


//////////////////////
/////// SLOTS ////////
/////////////////////

void WidgetBola::slotParar(){

  miBola->parar();

}
