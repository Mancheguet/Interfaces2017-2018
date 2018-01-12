#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QPainter>

//Prueba de imagenes
#include <QPixmap>
//

#include <Bola.h>

class MainWindow : public QMainWindow{

    Q_OBJECT

    public:

        MainWindow (QWidget *parent = 0, Qt::WindowFlags flags = 0);

        QTimer *temporizador;

        QVector<Bola *> bolas;

        void paintEvent (QPaintEvent *event);
        void inicializarBolas();

    public slots:

        void slotRepintar();

};

#endif
