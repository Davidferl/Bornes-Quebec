/********************************************************************************
** Form generated from reading UI file 'SupprimeBorneInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMEBORNEINTERFACE_H
#define UI_SUPPRIMEBORNEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimeBorneInterface
{
public:
    QLabel *label;
    QSpinBox *spinBoxIdentifiant;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *SupprimeBorneInterface)
    {
        if (SupprimeBorneInterface->objectName().isEmpty())
            SupprimeBorneInterface->setObjectName(QString::fromUtf8("SupprimeBorneInterface"));
        SupprimeBorneInterface->resize(649, 300);
        label = new QLabel(SupprimeBorneInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 271, 16));
        spinBoxIdentifiant = new QSpinBox(SupprimeBorneInterface);
        spinBoxIdentifiant->setObjectName(QString::fromUtf8("spinBoxIdentifiant"));
        spinBoxIdentifiant->setGeometry(QRect(350, 70, 81, 21));
        spinBoxIdentifiant->setMinimum(1);
        spinBoxIdentifiant->setMaximum(1000000);
        pushButtonOK = new QPushButton(SupprimeBorneInterface);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(240, 180, 90, 28));

        retranslateUi(SupprimeBorneInterface);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), SupprimeBorneInterface, SLOT(accept()));

        QMetaObject::connectSlotsByName(SupprimeBorneInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimeBorneInterface)
    {
        SupprimeBorneInterface->setWindowTitle(QApplication::translate("SupprimeBorneInterface", "SupprimeBorneInterface", nullptr));
        label->setText(QApplication::translate("SupprimeBorneInterface", "Entrez l'identifiant de la borne \303\240 supprimer :", nullptr));
        pushButtonOK->setText(QApplication::translate("SupprimeBorneInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimeBorneInterface: public Ui_SupprimeBorneInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMEBORNEINTERFACE_H
