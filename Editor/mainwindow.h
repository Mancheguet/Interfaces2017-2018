#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
//Incluir estas dos para lo del menu (QMENU - QMENUBAR)
#include <QMenu>
#include <QMenuBar>

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);

private:
    QTextEdit *editorCentral;
    QAction *accionSalir;
    QMenu *fileMenu;

};

#endif
