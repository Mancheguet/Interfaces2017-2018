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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnParar;
    QPushButton *btnColor;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QStringLiteral("WidgetBola"));
        WidgetBola->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(WidgetBola);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnParar = new QPushButton(WidgetBola);
        btnParar->setObjectName(QStringLiteral("btnParar"));

        verticalLayout->addWidget(btnParar);

        btnColor = new QPushButton(WidgetBola);
        btnColor->setObjectName(QStringLiteral("btnColor"));

        verticalLayout->addWidget(btnColor);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", Q_NULLPTR));
        btnParar->setText(QApplication::translate("WidgetBola", "Parar bola", Q_NULLPTR));
        btnColor->setText(QApplication::translate("WidgetBola", "Elegir color", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
