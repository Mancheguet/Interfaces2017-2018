/********************************************************************************
** Form generated from reading UI file 'WidgetBola.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QPushButton *botonParar;
    QPushButton *botonElegirColor;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QStringLiteral("WidgetBola"));
        WidgetBola->resize(259, 154);
        botonParar = new QPushButton(WidgetBola);
        botonParar->setObjectName(QStringLiteral("botonParar"));
        botonParar->setGeometry(QRect(70, 20, 98, 27));
        botonElegirColor = new QPushButton(WidgetBola);
        botonElegirColor->setObjectName(QStringLiteral("botonElegirColor"));
        botonElegirColor->setGeometry(QRect(70, 90, 98, 27));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", Q_NULLPTR));
        botonParar->setText(QApplication::translate("WidgetBola", "Parar Bola", Q_NULLPTR));
        botonElegirColor->setText(QApplication::translate("WidgetBola", "Elegir Color", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
