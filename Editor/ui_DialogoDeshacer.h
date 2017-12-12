/********************************************************************************
** Form generated from reading UI file 'DialogoDeshacer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGODESHACER_H
#define UI_DIALOGODESHACER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoDeshacer
{
public:
    QPushButton *bDesHacer;
    QPushButton *bReHacer;

    void setupUi(QDialog *DialogoDeshacer)
    {
        if (DialogoDeshacer->objectName().isEmpty())
            DialogoDeshacer->setObjectName(QStringLiteral("DialogoDeshacer"));
        DialogoDeshacer->resize(249, 67);
        bDesHacer = new QPushButton(DialogoDeshacer);
        bDesHacer->setObjectName(QStringLiteral("bDesHacer"));
        bDesHacer->setGeometry(QRect(10, 20, 99, 27));
        bReHacer = new QPushButton(DialogoDeshacer);
        bReHacer->setObjectName(QStringLiteral("bReHacer"));
        bReHacer->setGeometry(QRect(130, 20, 99, 27));

        retranslateUi(DialogoDeshacer);

        QMetaObject::connectSlotsByName(DialogoDeshacer);
    } // setupUi

    void retranslateUi(QDialog *DialogoDeshacer)
    {
        DialogoDeshacer->setWindowTitle(QApplication::translate("DialogoDeshacer", "Dialog", Q_NULLPTR));
        bDesHacer->setText(QApplication::translate("DialogoDeshacer", "DesHacer", Q_NULLPTR));
        bReHacer->setText(QApplication::translate("DialogoDeshacer", "ReHacer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoDeshacer: public Ui_DialogoDeshacer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGODESHACER_H
