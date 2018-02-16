/********************************************************************************
** Form generated from reading UI file 'WidgetVitalizar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETVITALIZAR_H
#define UI_WIDGETVITALIZAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WidgetVitalizar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdBola;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkProteger;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QProgressBar *vidaProgress;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spinBoxVida;
    QPushButton *buttonAplicar;

    void setupUi(QDialog *WidgetVitalizar)
    {
        if (WidgetVitalizar->objectName().isEmpty())
            WidgetVitalizar->setObjectName(QStringLiteral("WidgetVitalizar"));
        WidgetVitalizar->resize(372, 195);
        verticalLayout = new QVBoxLayout(WidgetVitalizar);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(WidgetVitalizar);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lcdBola = new QLCDNumber(WidgetVitalizar);
        lcdBola->setObjectName(QStringLiteral("lcdBola"));

        horizontalLayout->addWidget(lcdBola);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkProteger = new QCheckBox(WidgetVitalizar);
        checkProteger->setObjectName(QStringLiteral("checkProteger"));

        horizontalLayout_2->addWidget(checkProteger);

        horizontalSpacer_2 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(WidgetVitalizar);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        vidaProgress = new QProgressBar(WidgetVitalizar);
        vidaProgress->setObjectName(QStringLiteral("vidaProgress"));
        vidaProgress->setValue(24);

        horizontalLayout_3->addWidget(vidaProgress);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(WidgetVitalizar);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        spinBoxVida = new QSpinBox(WidgetVitalizar);
        spinBoxVida->setObjectName(QStringLiteral("spinBoxVida"));
        spinBoxVida->setMinimum(-5);
        spinBoxVida->setMaximum(5);

        horizontalLayout_4->addWidget(spinBoxVida);

        buttonAplicar = new QPushButton(WidgetVitalizar);
        buttonAplicar->setObjectName(QStringLiteral("buttonAplicar"));

        horizontalLayout_4->addWidget(buttonAplicar);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(WidgetVitalizar);

        QMetaObject::connectSlotsByName(WidgetVitalizar);
    } // setupUi

    void retranslateUi(QDialog *WidgetVitalizar)
    {
        WidgetVitalizar->setWindowTitle(QApplication::translate("WidgetVitalizar", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetVitalizar", "N\303\272mero de bola ", Q_NULLPTR));
        checkProteger->setText(QApplication::translate("WidgetVitalizar", "Proteger", Q_NULLPTR));
        label_2->setText(QApplication::translate("WidgetVitalizar", "Vida restante", Q_NULLPTR));
        label_3->setText(QApplication::translate("WidgetVitalizar", "Modificar vida", Q_NULLPTR));
        buttonAplicar->setText(QApplication::translate("WidgetVitalizar", "Aplicar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetVitalizar: public Ui_WidgetVitalizar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETVITALIZAR_H
