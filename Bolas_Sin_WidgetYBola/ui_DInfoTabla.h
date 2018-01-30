/********************************************************************************
** Form generated from reading UI file 'DInfoTabla.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOTABLA_H
#define UI_DINFOTABLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DInfoTabla
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DInfoTabla)
    {
        if (DInfoTabla->objectName().isEmpty())
            DInfoTabla->setObjectName(QStringLiteral("DInfoTabla"));
        DInfoTabla->resize(400, 300);
        widget = new QWidget(DInfoTabla);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaBolas = new QTableView(widget);
        tablaBolas->setObjectName(QStringLiteral("tablaBolas"));

        verticalLayout->addWidget(tablaBolas);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DInfoTabla);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInfoTabla, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInfoTabla, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInfoTabla);
    } // setupUi

    void retranslateUi(QDialog *DInfoTabla)
    {
        DInfoTabla->setWindowTitle(QApplication::translate("DInfoTabla", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DInfoTabla: public Ui_DInfoTabla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOTABLA_H
