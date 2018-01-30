#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QPainter>
#include <QAction>
//Incluir estas dos para lo del menu (QMENU - QMENUBAR)
#include <QMenu>
#include <QMenuBar>

//Prueba de imagenes
#include <QPixmap>
//

#include <Bola.h>
#include <Dialog.h>
#include <DInfoTabla.h>
#include <DControlBolas.h>
#include "BolaYWidget.h"

class MainWindow : public QMainWindow{

    Q_OBJECT

    public:

        MainWindow (QWidget *parent = 0, Qt::WindowFlags flags = 0);

        QTimer *temporizador;

        QVector<BolaYWidget *> bolas;

        QAction *accionSalir;
        QAction *accionDialog;
        QAction *accionInfoTabla;
        QAction *accionControlBolas;

        QMenu *fileMenu;

        BolaYWidget *bolaJugador;

        DInfoTabla *dInfoTabla;
        DControlBolas *dControlBolas;

        float posIX, posIY;

        void paintEvent (QPaintEvent *event);
        void inicializarBolas();
        void createActions();
        void createMenus();
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);

    public slots:

        void slotRepintar();
        void slotAbirDialog();
        void keyPressEvent(QKeyEvent *event);
        void slotInfoTabla();
        void slotControlBolas();

};

#endif
