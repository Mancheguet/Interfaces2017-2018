#include "IntroducirPalabra.h"
#include "mainwindow.h"

IntroducirPalabra::IntroducirPalabra(QWidget *parent)
     : QDialog(parent){

       setupUi(this);

       connect(bIntroducido, SIGNAL(clicked()),
              this, SLOT(slotEnviarPalabra()));

     }

void IntroducirPalabra::slotEnviarPalabra(){

  QString stringIntroducido = palabraIntroducida->text();
  //editor->document()->setPlainText(stringIntroducido);
  pIntroducidasLista->append(stringIntroducido);
  //editor->document()->setPlainText(QString::number(pIntroducidasLista->size()));
  this->close();

}
