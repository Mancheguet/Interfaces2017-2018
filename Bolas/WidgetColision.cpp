#include "WidgetColision.h"

WidgetColision::WidgetColision(Colision colisionPasada, QWidget *parent) : QDialog(parent){

  setupUi(this);
  colision = colisionPasada;

  labelX->setText(QString::number(colision.posX));
  labelY->setText(QString::number(colision.posY));

}
