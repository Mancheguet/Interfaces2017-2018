#include "DControlBolas.h"

DControlBolas::DControlBolas(QVector<BolaYWidget *> * bolasMain, QWidget *parent) : QDialog(parent) {

    setupUi(this);

    bolas = bolasMain;

    while(tabBolas->count() > 0 ) tabBolas->removeTab(0);
    //tabBolas->clear();

    for (int i = 0; i < bolas->size(); i++) {
      //ir añadiendo pestañas con un botón dentro
      tabBolas->addTab(bolasMain->at(i),QString("Pestanya")+QString::number(i));
    }

    connect(tabBolas, SIGNAL(currentChanged(int)),this, SLOT(slotCambioPestana(int)));
    connect(btnIgualar, SIGNAL(clicked()),this, SLOT(slotIgualar()));

}

/////////////////////
///////slot/////////
///////////////////

void DControlBolas::slotCambioPestana(int i){

  //resetear resaltado a false
  for (int i = 0; i < bolas->size(); i++) {
    bolas->at(i)->resaltado=false;
  }
  //Recuperamos y pintamos la bola que esta ene l widget del momento
  WidgetBola * pestanaMomento = qobject_cast<WidgetBola*>(tabBolas->currentWidget());
  pestanaMomento->miBola->resaltado=true;

}

void DControlBolas::slotIgualar(){

  float v = (random() % 1000) /100.1 - 4.49;

  for (int i=0; i < tabBolas->count(); i++){

    Bola *unaBola = dynamic_cast<Bola*>(tabBolas->widget(i));
    unaBola->velX = unaBola->velY = v;

  }

}
