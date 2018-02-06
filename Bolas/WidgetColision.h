#ifndef WIDGETCOLISION_H
#define WIDGETCOLISION_H

#include <QDialog>
#include <QWidget>

#include "ui_WidgetColision.h"
#include "Colision.h"
#include "Bola.h"


class WidgetColision: public QDialog, public Ui::WidgetColision {

    Q_OBJECT

    public:

        Colision colision;

        WidgetColision(Colision colisionPasada, QWidget *parent=0);

    signals:


    private slots:

};

#endif
