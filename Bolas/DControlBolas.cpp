#include "DControlBolas.h"

DControlBolas::DControlBolas(QVector<Bola *> * bolasMain, QWidget *parent) : QDialog(parent) {

    setupUi(this);

    while(tabBolas->count() > 0 ) tabBolas->removeTab(0);
    //tabBolas->clear();

    for (int i = 0; i < 10/*bolasMain->size()*/; i++) {
      //ir añadiendo pestañas con un botón dentro
      tabBolas->addTab(
        new WidgetBola(),
        QString("Pestanya")+QString::number(i));
    }

}
