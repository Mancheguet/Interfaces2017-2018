#ifndef WIDGETDATOSBOLA_H
#define WIDGETDATOSBOLA_H

#include <QDialog>
#include <QPushButton>
#include <QColorDialog>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>

#include "ui_WidgetDatosBola.h"
#include "Bola.h"

class WidgetDatosBola: public QDialog, public Ui::WidgetDatosBola {

    Q_OBJECT

    public:

        WidgetDatosBola(Bola * bola, QWidget *parent=0);
        Bola * miBola;

        void keyPressEvent(QKeyEvent *e);

    signals:


    private slots:
        void slotCambioColor();
};

#endif
