#include <QDebug>
#include <QPushButton>
#include "DControlBolas.h"
#include "WidgetBola.h"

 DControlBolas::DControlBolas(QVector<Bola*> bolas, QWidget *parent)
      : QDialog(parent)
  {
   
	setupUi(this);

	connect(tabBolas,SIGNAL(currentChanged(int)),
		this,SLOT(slotCambioPestanya(int)));
	
	while (tabBolas->count() > 0) tabBolas->removeTab(0);

	for (int i = 0;i<bolas.size(); i++)
		tabBolas->addTab(new WidgetBola(bolas.at(i)), QString("Pestanya")+QString::number(i));
	
}

void DControlBolas::slotCambioPestanya(int numPestanya){

	for (int i = 0; i< tabBolas->count();i++) {
		//qDebug() << "viendo bola" << i << endl;
		WidgetBola *widget = qobject_cast<WidgetBola *> (tabBolas->widget(i));
		if (widget != NULL ) widget->miBola->resaltada = false;
			else qDebug() << "fallo en pestaña" << i << endl;
	}

	WidgetBola *widget = qobject_cast<WidgetBola * > (tabBolas->currentWidget());
	if (widget != NULL ) widget->miBola->resaltada = true;
			else qDebug() << "fallo en pestaña current" << endl;
}

