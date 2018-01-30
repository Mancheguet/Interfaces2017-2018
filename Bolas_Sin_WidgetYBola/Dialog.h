#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_Dialog.h"

#include <QTextEdit>
#include <QPushButton>

 class Dialog : public QDialog, public  Ui::Dialog
 {
     Q_OBJECT

 public:
     Dialog(int numBolas, int ancho, int altura, QWidget *parent = 0);

 private:

    int numBolas;
    int ancho;
    int altura;

 signals:

 private slots:

 };

 #endif
