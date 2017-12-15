#ifndef INTRODUCIRPALABRA_H
#define INTRODUCIRPALABRA_H

#include <QDialog>
#include "ui_IntroducirPalabra.h"

#include <QTextEdit>
#include <QPushButton>

 class IntroducirPalabra : public QDialog, public  Ui::IntroducirPalabra
 {
     Q_OBJECT

 public:
     IntroducirPalabra(QWidget *parent = 0);
     QStringList *pIntroducidasLista;
     QTextEdit *editor;

 signals:

 private slots:
     void slotEnviarPalabra();
 };

 #endif
