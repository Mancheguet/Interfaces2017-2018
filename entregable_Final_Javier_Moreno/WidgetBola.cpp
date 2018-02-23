
#include "WidgetBola.h"

 WidgetBola::WidgetBola(Bola * bola, QWidget *parent)
      : QWidget(parent)
  {
   
	setupUi(this);
	miBola = bola;
	connect(botonParar,SIGNAL(clicked()),	
		this,SLOT(pararBola()));
}


void WidgetBola::pararBola(){

	miBola->velX = miBola->velY = 0;
}
