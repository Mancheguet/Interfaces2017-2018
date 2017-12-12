#ifndef DIALOGDESHACER_H
#define DIALOGDESHACER_H

#include <QDialog>
#include "ui_DialogoDeshacer.h"

#include <QTextEdit>
#include <QPushButton>

 class DialogoDeshacer : public QDialog, public  Ui::DialogoDeshacer
 {
     Q_OBJECT

 public:
     DialogoDeshacer(QWidget *parent = 0);
     QTextEdit *editor;

 signals:

 private slots:
    void slotDeshacerRehacer();
    void slotBotonVisible(bool);
    void slotBotonVisibleRehacer(bool);

 };

 #endif
