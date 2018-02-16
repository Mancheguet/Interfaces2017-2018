/********************************************************************************
** Form generated from reading UI file 'DVitalizar.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVITALIZAR_H
#define UI_DVITALIZAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DVitalizar
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameCentral;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *layoutFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QToolButton *botonAnterior;
    QToolButton *botonSiguiente;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *botonBuscar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DVitalizar)
    {
        if (DVitalizar->objectName().isEmpty())
            DVitalizar->setObjectName(QStringLiteral("DVitalizar"));
        DVitalizar->resize(486, 371);
        verticalLayout = new QVBoxLayout(DVitalizar);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frameCentral = new QFrame(DVitalizar);
        frameCentral->setObjectName(QStringLiteral("frameCentral"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameCentral->sizePolicy().hasHeightForWidth());
        frameCentral->setSizePolicy(sizePolicy);
        frameCentral->setFrameShape(QFrame::StyledPanel);
        frameCentral->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameCentral);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        layoutFrame = new QVBoxLayout();
        layoutFrame->setObjectName(QStringLiteral("layoutFrame"));

        horizontalLayout_3->addLayout(layoutFrame);


        verticalLayout->addWidget(frameCentral);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(DVitalizar);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        botonAnterior = new QToolButton(DVitalizar);
        botonAnterior->setObjectName(QStringLiteral("botonAnterior"));
        botonAnterior->setArrowType(Qt::LeftArrow);

        horizontalLayout_2->addWidget(botonAnterior);

        botonSiguiente = new QToolButton(DVitalizar);
        botonSiguiente->setObjectName(QStringLiteral("botonSiguiente"));
        botonSiguiente->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(botonSiguiente);

        label_3 = new QLabel(DVitalizar);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        botonBuscar = new QPushButton(DVitalizar);
        botonBuscar->setObjectName(QStringLiteral("botonBuscar"));

        horizontalLayout->addWidget(botonBuscar);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DVitalizar);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DVitalizar);
        QObject::connect(buttonBox, SIGNAL(accepted()), DVitalizar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DVitalizar, SLOT(reject()));

        QMetaObject::connectSlotsByName(DVitalizar);
    } // setupUi

    void retranslateUi(QDialog *DVitalizar)
    {
        DVitalizar->setWindowTitle(QApplication::translate("DVitalizar", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("DVitalizar", "Anterior", Q_NULLPTR));
        botonAnterior->setText(QApplication::translate("DVitalizar", "...", Q_NULLPTR));
        botonSiguiente->setText(QApplication::translate("DVitalizar", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("DVitalizar", "Siguiente", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        botonBuscar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        botonBuscar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        botonBuscar->setText(QApplication::translate("DVitalizar", "Buscar Bola Moribunda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DVitalizar: public Ui_DVitalizar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVITALIZAR_H
