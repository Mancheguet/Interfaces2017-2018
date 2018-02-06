#include "Dialog.h"

Dialog::Dialog(int numBolas, int ancho, int altura, QWidget *parent)
     : QDialog(parent){

       this->numBolas = numBolas;
       this->ancho = ancho;
       this->altura = altura;

       setupUi(this);

       nBolas->setText(QString::number(numBolas));
       tVentana->setText(QString::number(ancho)+"  x  "+QString::number(altura));

}
