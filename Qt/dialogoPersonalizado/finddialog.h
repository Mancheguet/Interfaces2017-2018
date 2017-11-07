#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QComboBox>
#include <QRadioButton>

 class FindDialog : public QDialog
 {
     Q_OBJECT

 public:
     FindDialog(QWidget *parent = 0);

 private:
     QCheckBox *check1;
     QCheckBox *check2;
     QCheckBox *check3;
     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;
     QPushButton *button5;
     QSlider *slider;
     QComboBox *combo1;
     QComboBox *combo2;
     QComboBox *combo3;
     QRadioButton *radio1;
     QRadioButton *radio2;
 };

 #endif
