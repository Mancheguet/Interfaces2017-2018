#include "WidgetVitalizar.h"

WidgetVitalizar::WidgetVitalizar(Bola * bola, QWidget *parent): QDialog(parent){

	setupUi(this);
	miBola = bola;

  pintarNumero();
  pintarVida();

  connect(buttonAplicar,SIGNAL(clicked()),this,SLOT(slotAplicar()));

}
void WidgetVitalizar::pintarVida(){

    vidaProgress->setValue(miBola->vida);

}

void WidgetVitalizar::pintarNumero(){

    lcdBola->display(miBola->numBola);

}

void WidgetVitalizar::slotAplicar(){

  int valorVida = spinBoxVida->value();
  miBola->vida+(valorVida);
  pintarVida();

}
