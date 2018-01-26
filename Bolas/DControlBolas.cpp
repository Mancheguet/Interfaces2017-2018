#include "DControlBolas.h"

DControlBolas::DControlBolas(QVector<Bola *> * bolasMain, QWidget *parent) : QDialog(parent) {

    setupUi(this);

    while(tabBolas->count() > 0 ) tabBolas->removeTab(0);
    //tabBolas->clear();

    for (int i = 0; i < bolasMain->size(); i++) {
      //ir añadiendo pestañas con un botón dentro
      tabBolas->addTab(
        new WidgetBola(bolasMain->at(i)),
        QString("Pestanya")+QString::number(i));
    }

    connect(tabBolas, SIGNAL(currentChanged(int)),this, SLOT(slotCambioPestana(int)));

}

/////////////////////
///////slot/////////
///////////////////

void DControlBolas::slotCambioPestana(int i){

  /* resetear resaltado a false
  for (int i = 0; i < bolasMain->size(); i++) {
    bolasMain->at(i)->miBola->resaltado=false;
  }
  */
  WidgetBola * pestanaMomento = qobject_cast<WidgetBola*>(tabBolas->currentWidget());
  pestanaMomento->miBola->resaltado=true;

}
