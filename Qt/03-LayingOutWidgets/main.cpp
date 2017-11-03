#include <QApplication>
//#include <QHBoxLayout> //biblioteca horizontal
#include <QVBoxLayout> //layout vertical
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget *window = new QWidget;
   window->setWindowTitle("Enter Your Age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);
    //Creo los botones
    QPushButton *buttonB = new QPushButton("Bajar");
    QPushButton *buttonS = new QPushButton("Subir");

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QObject::connect( buttonB , SIGNAL(clicked()),
                    spinBox, SLOT(stepDown()));

      QObject::connect( buttonS , SIGNAL(clicked()),
                        spinBox, SLOT(stepUp()));

    //QHBoxLayout *layout = new QHBoxLayout; //layout horizontal
    QVBoxLayout *layout = new QVBoxLayout; //layout vertical

    layout->addWidget(spinBox);
    layout->addWidget(slider);
    //Añado los botones al layout
    layout->addWidget(buttonB);
    layout->addWidget(buttonS);

    window->setLayout(layout);

    window->show();

    return app.exec();
}
