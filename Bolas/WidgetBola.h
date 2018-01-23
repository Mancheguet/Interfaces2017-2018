#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H

#include <QDialog>
#include <QPushButton>

#include "ui_WidgetBola.h"


class WidgetBola: public QDialog, public Ui::WidgetBola {

    Q_OBJECT

    public:

        WidgetBola(QWidget *parent=0);

};

#endif
