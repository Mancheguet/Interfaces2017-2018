#ifndef DVERCOLISIONES_H
#define DVERCOLISIONES_H

#include <QDialog>
#include <QWidget>

#include "ui_DVerColisiones.h"

class DVerColisiones: public QDialog, public Ui::DVerColisiones {

    Q_OBJECT

    public:

        DVerColisiones(QWidget *parent=0);

};

#endif
