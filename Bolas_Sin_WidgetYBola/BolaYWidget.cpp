#include "BolaYWidget.h"

BolaYWidget::BolaYWidget(float x, float y, float vx, float vy, QWidget *parent) :
  posX(x), posY(y), velX(vx), velY(vy), QWidget(parent) {

    setupUi(this);

}
