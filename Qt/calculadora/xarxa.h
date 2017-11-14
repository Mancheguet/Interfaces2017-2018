#ifndef XARXA_H
#define XARXA_H

#include <QDialog>
#include <QPushButton>

#include "ui_xarxa.h"

class Xarxa : public QDialog, public Ui::Xarxa
{
    Q_OBJECT

public:
    Xarxa(QWidget *parent = 0);

private slots:
  void activarPanelRed(int index);

};

#endif
