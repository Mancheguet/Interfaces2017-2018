/********************************************************************************
** Form generated from reading UI file 'IntroducirPalabra.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRODUCIRPALABRA_H
#define UI_INTRODUCIRPALABRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroducirPalabra
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *palabraIntroducida;
    QPushButton *bIntroducido;

    void setupUi(QDialog *IntroducirPalabra)
    {
        if (IntroducirPalabra->objectName().isEmpty())
            IntroducirPalabra->setObjectName(QStringLiteral("IntroducirPalabra"));
        IntroducirPalabra->resize(320, 90);
        widget = new QWidget(IntroducirPalabra);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 271, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        palabraIntroducida = new QLineEdit(widget);
        palabraIntroducida->setObjectName(QStringLiteral("palabraIntroducida"));

        horizontalLayout->addWidget(palabraIntroducida);

        bIntroducido = new QPushButton(widget);
        bIntroducido->setObjectName(QStringLiteral("bIntroducido"));

        horizontalLayout->addWidget(bIntroducido);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(IntroducirPalabra);

        QMetaObject::connectSlotsByName(IntroducirPalabra);
    } // setupUi

    void retranslateUi(QDialog *IntroducirPalabra)
    {
        IntroducirPalabra->setWindowTitle(QApplication::translate("IntroducirPalabra", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("IntroducirPalabra", "Introduce una palabra:", Q_NULLPTR));
        bIntroducido->setText(QApplication::translate("IntroducirPalabra", "Introducir", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IntroducirPalabra: public Ui_IntroducirPalabra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCIRPALABRA_H
