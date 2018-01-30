/********************************************************************************
** Form generated from reading UI file 'DControlBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONTROLBOLAS_H
#define UI_DCONTROLBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DControlBolas
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabBolas;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *btnIgualar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DControlBolas)
    {
        if (DControlBolas->objectName().isEmpty())
            DControlBolas->setObjectName(QStringLiteral("DControlBolas"));
        DControlBolas->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(DControlBolas);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabBolas = new QTabWidget(DControlBolas);
        tabBolas->setObjectName(QStringLiteral("tabBolas"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabBolas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabBolas->addTab(tab_2, QString());

        verticalLayout->addWidget(tabBolas);

        btnIgualar = new QPushButton(DControlBolas);
        btnIgualar->setObjectName(QStringLiteral("btnIgualar"));

        verticalLayout->addWidget(btnIgualar);

        buttonBox = new QDialogButtonBox(DControlBolas);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DControlBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DControlBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DControlBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DControlBolas);
    } // setupUi

    void retranslateUi(QDialog *DControlBolas)
    {
        DControlBolas->setWindowTitle(QApplication::translate("DControlBolas", "Dialog", Q_NULLPTR));
        tabBolas->setTabText(tabBolas->indexOf(tab), QApplication::translate("DControlBolas", "Tab 1", Q_NULLPTR));
        tabBolas->setTabText(tabBolas->indexOf(tab_2), QApplication::translate("DControlBolas", "Tab 2", Q_NULLPTR));
        btnIgualar->setText(QApplication::translate("DControlBolas", "Igualar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DControlBolas: public Ui_DControlBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONTROLBOLAS_H
