#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H

#include <QDialog>
#include <QPushButton>

#include "ui_WidgetBola.h"
#include "Bola.h"

class WidgetBola: public QDialog, public Ui::WidgetBola {

    Q_OBJECT

    public:

        WidgetBola(Bola * bola, QWidget *parent=0);
        Bola * miBola;

    signals:


    private slots:
       void slotParar();

};

#endif
