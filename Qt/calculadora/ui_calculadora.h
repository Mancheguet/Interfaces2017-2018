/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QLineEdit *pantalla;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn0;
    QPushButton *btndot;
    QVBoxLayout *verticalLayout;
    QPushButton *btnplus;
    QPushButton *btnEnter;

    void setupUi(QDialog *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QStringLiteral("Calculadora"));
        Calculadora->resize(405, 215);
        widget = new QWidget(Calculadora);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 366, 167));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pantalla = new QLineEdit(widget);
        pantalla->setObjectName(QStringLiteral("pantalla"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, pantalla);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn7 = new QPushButton(widget);
        btn7->setObjectName(QStringLiteral("btn7"));

        gridLayout->addWidget(btn7, 0, 0, 1, 1);

        btn8 = new QPushButton(widget);
        btn8->setObjectName(QStringLiteral("btn8"));

        gridLayout->addWidget(btn8, 0, 1, 1, 1);

        btn9 = new QPushButton(widget);
        btn9->setObjectName(QStringLiteral("btn9"));

        gridLayout->addWidget(btn9, 0, 2, 1, 1);

        btn4 = new QPushButton(widget);
        btn4->setObjectName(QStringLiteral("btn4"));

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn5 = new QPushButton(widget);
        btn5->setObjectName(QStringLiteral("btn5"));

        gridLayout->addWidget(btn5, 1, 1, 1, 1);

        btn6 = new QPushButton(widget);
        btn6->setObjectName(QStringLiteral("btn6"));

        gridLayout->addWidget(btn6, 1, 2, 1, 1);

        btn1 = new QPushButton(widget);
        btn1->setObjectName(QStringLiteral("btn1"));

        gridLayout->addWidget(btn1, 2, 0, 1, 1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName(QStringLiteral("btn2"));

        gridLayout->addWidget(btn2, 2, 1, 1, 1);

        btn3 = new QPushButton(widget);
        btn3->setObjectName(QStringLiteral("btn3"));

        gridLayout->addWidget(btn3, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn0 = new QPushButton(widget);
        btn0->setObjectName(QStringLiteral("btn0"));

        horizontalLayout->addWidget(btn0);

        btndot = new QPushButton(widget);
        btndot->setObjectName(QStringLiteral("btndot"));

        horizontalLayout->addWidget(btndot);


        verticalLayout_2->addLayout(horizontalLayout);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnplus = new QPushButton(widget);
        btnplus->setObjectName(QStringLiteral("btnplus"));
        btnplus->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnplus->sizePolicy().hasHeightForWidth());
        btnplus->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnplus);

        btnEnter = new QPushButton(widget);
        btnEnter->setObjectName(QStringLiteral("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btnEnter);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout);


        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QDialog *Calculadora)
    {
        Calculadora->setWindowTitle(QApplication::translate("Calculadora", "Dialog", Q_NULLPTR));
        btn7->setText(QApplication::translate("Calculadora", "7", Q_NULLPTR));
        btn8->setText(QApplication::translate("Calculadora", "8", Q_NULLPTR));
        btn9->setText(QApplication::translate("Calculadora", "9", Q_NULLPTR));
        btn4->setText(QApplication::translate("Calculadora", "4", Q_NULLPTR));
        btn5->setText(QApplication::translate("Calculadora", "5", Q_NULLPTR));
        btn6->setText(QApplication::translate("Calculadora", "6", Q_NULLPTR));
        btn1->setText(QApplication::translate("Calculadora", "1", Q_NULLPTR));
        btn2->setText(QApplication::translate("Calculadora", "2", Q_NULLPTR));
        btn3->setText(QApplication::translate("Calculadora", "3", Q_NULLPTR));
        btn0->setText(QApplication::translate("Calculadora", "0", Q_NULLPTR));
        btndot->setText(QApplication::translate("Calculadora", ".", Q_NULLPTR));
        btnplus->setText(QApplication::translate("Calculadora", "+", Q_NULLPTR));
        btnEnter->setText(QApplication::translate("Calculadora", "Ent", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
