#ifndef BOLAYWIDGET_H
#define BOLAYWIDGET_H

#include "Bola.h"
#include "WidgetBola.h"

class BolaYWidget : public WidgetBola, public Bola {

  public:

    BolaYWidget();
    BolaYWidget(float x, float y, float vx, float vy, QWidget *parent=0);

};

#endif

/*tabBolas->addTab(bolas.at(i))*/
