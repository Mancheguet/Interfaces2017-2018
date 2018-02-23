#include "WidgetDatosBola.h"

WidgetDatosBola::WidgetDatosBola(Bola * bola, QWidget *parent) : QDialog(parent) {

    setupUi(this);
    this->miBola = bola;


    connect(botonColor, SIGNAL(clicked()),this, SLOT(slotCambioColor()));

}

void WidgetDatosBola::keyPressEvent(QKeyEvent *e){

	switch (e->key()) {

        case QEvent::Enter : qDebug() << "Enter pulsado"; break;
      };
}

void WidgetDatosBola::slotCambioColor(){

  QPainter pintor(this);

  QColorDialog dialogoCambioColor(this);
  dialogoCambioColor.exec(); //ejecutar en modal (no deja usar la de abajo -> show = no modal

    int r = dialogoCambioColor.result();

    if(r == QDialog::Accepted){

      miBola->color=dialogoCambioColor.selectedColor();

    }

}
