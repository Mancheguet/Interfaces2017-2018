#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H

#include "Bola.h"
#include "ui_WidgetBola.h"

 class WidgetBola : public QWidget, public Ui::WidgetBola 
{
     Q_OBJECT

 public:	
     WidgetBola(Bola * b, QWidget *parent = 0);
	Bola *miBola;
 public slots:
	void pararBola();
};

#endif

