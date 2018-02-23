#include "DInfoBolas.h"

 DInfoBolas::DInfoBolas(QVector<Bola*> bolasPasadas, QWidget *parent)
      : QDialog(parent)
  {
   
	setupUi(this); 
	bolas=bolasPasadas;
	temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(1000);
	connect(temporizador,SIGNAL(timeout()),this,SLOT(mostrar()));

	temporizador->start();
	mostrar();
}

void DInfoBolas::mostrar(){
  listaBolas->clear();
  for(int i=0; i<bolas.size();i++) 
	listaBolas->addItem(QString("posx:") + QString::number(bolas.at(i)->posX)+
	QString("PosY= ") + QString::number(bolas.at(i)->posY) ); 
}


