#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>

#include <Bola.h>

class MainWindow : public QMainWindow{

    Q_OBJECT

    public:

        MainWindow (QWidget *parent = 0, Qt::WindowFlags flags = 0);

        void paintEvent (QPaintEvent *event);
        void inicializarBolas();
        
        QTimer *temporizador;

        QVector<Bola *> bolas;

    public slots:
        void slotRepintar();
};

#endif
