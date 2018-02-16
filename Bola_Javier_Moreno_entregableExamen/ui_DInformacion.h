/********************************************************************************
** Form generated from reading UI file 'DInformacion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFORMACION_H
#define UI_DINFORMACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DInformacion
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *etiquetaNumBolas;
    QLabel *label_3;
    QLabel *etiquetaTamanyo;

    void setupUi(QDialog *DInformacion)
    {
        if (DInformacion->objectName().isEmpty())
            DInformacion->setObjectName(QStringLiteral("DInformacion"));
        DInformacion->resize(400, 300);
        buttonBox = new QDialogButtonBox(DInformacion);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DInformacion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 70, 131, 20));
        etiquetaNumBolas = new QLabel(DInformacion);
        etiquetaNumBolas->setObjectName(QStringLiteral("etiquetaNumBolas"));
        etiquetaNumBolas->setGeometry(QRect(190, 70, 66, 17));
        label_3 = new QLabel(DInformacion);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(15, 110, 121, 20));
        etiquetaTamanyo = new QLabel(DInformacion);
        etiquetaTamanyo->setObjectName(QStringLiteral("etiquetaTamanyo"));
        etiquetaTamanyo->setGeometry(QRect(190, 110, 66, 17));

        retranslateUi(DInformacion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInformacion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInformacion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInformacion);
    } // setupUi

    void retranslateUi(QDialog *DInformacion)
    {
        DInformacion->setWindowTitle(QApplication::translate("DInformacion", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DInformacion", "N\303\272mero de bolas", Q_NULLPTR));
        etiquetaNumBolas->setText(QApplication::translate("DInformacion", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("DInformacion", "Tama\303\261o Finestra", Q_NULLPTR));
        etiquetaTamanyo->setText(QApplication::translate("DInformacion", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DInformacion: public Ui_DInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFORMACION_H
