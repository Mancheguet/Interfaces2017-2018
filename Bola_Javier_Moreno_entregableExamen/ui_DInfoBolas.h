/********************************************************************************
** Form generated from reading UI file 'DInfoBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOBOLAS_H
#define UI_DINFOBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DInfoBolas
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listaBolas;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboFrecuencia;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DInfoBolas)
    {
        if (DInfoBolas->objectName().isEmpty())
            DInfoBolas->setObjectName(QStringLiteral("DInfoBolas"));
        DInfoBolas->resize(400, 300);
        verticalLayout = new QVBoxLayout(DInfoBolas);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listaBolas = new QListWidget(DInfoBolas);
        listaBolas->setObjectName(QStringLiteral("listaBolas"));

        verticalLayout->addWidget(listaBolas);

        frame = new QFrame(DInfoBolas);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboFrecuencia = new QComboBox(frame);
        comboFrecuencia->setObjectName(QStringLiteral("comboFrecuencia"));

        horizontalLayout->addWidget(comboFrecuencia);


        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(DInfoBolas);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DInfoBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInfoBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInfoBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInfoBolas);
    } // setupUi

    void retranslateUi(QDialog *DInfoBolas)
    {
        DInfoBolas->setWindowTitle(QApplication::translate("DInfoBolas", "Dialog", Q_NULLPTR));
        comboFrecuencia->clear();
        comboFrecuencia->insertItems(0, QStringList()
         << QApplication::translate("DInfoBolas", "g\303\241pido", Q_NULLPTR)
         << QApplication::translate("DInfoBolas", "Medio", Q_NULLPTR)
         << QApplication::translate("DInfoBolas", "gento", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class DInfoBolas: public Ui_DInfoBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOBOLAS_H
