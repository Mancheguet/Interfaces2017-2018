/********************************************************************************
** Form generated from reading UI file 'WidgetColision.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCOLISION_H
#define UI_WIDGETCOLISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetColision
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelX;
    QLabel *label_3;
    QLabel *labelY;

    void setupUi(QWidget *WidgetColision)
    {
        if (WidgetColision->objectName().isEmpty())
            WidgetColision->setObjectName(QStringLiteral("WidgetColision"));
        WidgetColision->resize(318, 35);
        horizontalLayout = new QHBoxLayout(WidgetColision);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(WidgetColision);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        labelX = new QLabel(WidgetColision);
        labelX->setObjectName(QStringLiteral("labelX"));

        horizontalLayout->addWidget(labelX);

        label_3 = new QLabel(WidgetColision);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        labelY = new QLabel(WidgetColision);
        labelY->setObjectName(QStringLiteral("labelY"));

        horizontalLayout->addWidget(labelY);


        retranslateUi(WidgetColision);

        QMetaObject::connectSlotsByName(WidgetColision);
    } // setupUi

    void retranslateUi(QWidget *WidgetColision)
    {
        WidgetColision->setWindowTitle(QApplication::translate("WidgetColision", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetColision", "PosX = ", Q_NULLPTR));
        labelX->setText(QApplication::translate("WidgetColision", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("WidgetColision", "PosY =", Q_NULLPTR));
        labelY->setText(QApplication::translate("WidgetColision", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetColision: public Ui_WidgetColision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCOLISION_H
