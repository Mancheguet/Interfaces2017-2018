#include <QApplication>

#include <QMainWindow>

#include "MainWindow.h"

int main (int argc, char *argv []){ 
    
    QApplication app (argc, argv); 
    
    MainWindow *ventana = new MainWindow(); 
    ventana->show();
    
    return app.exec(); 
}
