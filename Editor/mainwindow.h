#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
//Incluir estas dos para lo del menu (QMENU - QMENUBAR)
#include <QMenu>
#include <QMenuBar>

#include <QToolBar>
#include <QStatusBar>

#include <QLabel>

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);

private:
    QTextEdit *editorCentral;

    QAction *accionSalir;
    QAction *accionGuardar;
    QAction *accionAbrir;
    QAction *accionNuevo;

    QMenu *fileMenu;

    QToolBar *barraArchivo;
    QToolBar *barraSalir;

    QLabel *labelNumeroLineas;
    QLabel *labelNumeroCaracteres;

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

private slots:
    void slotAbrir();
    void slotGuardar();
    void slotActualizarBarraEstado();
    void slotNuevo();

};

#endif
