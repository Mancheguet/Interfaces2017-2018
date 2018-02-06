/********************************************************************************
** Form generated from reading UI file 'DVerColisiones.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVERCOLISIONES_H
#define UI_DVERCOLISIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DVerColisiones
{
public:

    void setupUi(QDialog *DVerColisiones)
    {
        if (DVerColisiones->objectName().isEmpty())
            DVerColisiones->setObjectName(QStringLiteral("DVerColisiones"));
        DVerColisiones->resize(585, 373);

        retranslateUi(DVerColisiones);

        QMetaObject::connectSlotsByName(DVerColisiones);
    } // setupUi

    void retranslateUi(QDialog *DVerColisiones)
    {
        DVerColisiones->setWindowTitle(QApplication::translate("DVerColisiones", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DVerColisiones: public Ui_DVerColisiones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVERCOLISIONES_H
