#include "BolaYWidget.h"

BolaYWidget::BolaYWidget(float x, float y, float vx, float vy, QWidget *parent) :
  Bola(x,y,vx,vy), WidgetBola(this, parent) {

}
