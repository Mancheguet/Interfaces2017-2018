#include <QtGui>
#include <QTextEdit>

#include "xarxa.h"

Xarxa::Xarxa(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(activarPanelRed(int)));

}

void Xarxa::activarPanelRed(int index){

    afegir->setEnabled(index == 0);

}
