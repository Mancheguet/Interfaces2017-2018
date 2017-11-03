#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton("Quit");
    //Cuando en el objeto button , se pulsa (clicked), llama al objeto app y llama de ese objeto al metodo quit.
    QObject::connect( button , SIGNAL(clicked()),
                    &app, SLOT(quit()));

    button->show();
    return app.exec();
}
