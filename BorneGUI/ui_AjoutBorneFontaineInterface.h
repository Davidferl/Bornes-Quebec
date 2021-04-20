/********************************************************************************
** Form generated from reading UI file 'AjoutBorneFontaineInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTBORNEFONTAINEINTERFACE_H
#define UI_AJOUTBORNEFONTAINEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutBorneFontaineInterface
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEditDirection;
    QLineEdit *lineEditNomTopographique;
    QLineEdit *lineEditVille;
    QLineEdit *lineEditArrondissement;
    QDoubleSpinBox *doubleSpinBoxLongitude;
    QDoubleSpinBox *doubleSpinBoxLatitude;
    QPushButton *pushButtonOK;
    QSpinBox *spinBoxIdentifiant;

    void setupUi(QDialog *AjoutBorneFontaineInterface)
    {
        if (AjoutBorneFontaineInterface->objectName().isEmpty())
            AjoutBorneFontaineInterface->setObjectName(QString::fromUtf8("AjoutBorneFontaineInterface"));
        AjoutBorneFontaineInterface->resize(406, 606);
        label = new QLabel(AjoutBorneFontaineInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 71, 16));
        label_2 = new QLabel(AjoutBorneFontaineInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 71, 16));
        label_3 = new QLabel(AjoutBorneFontaineInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 130, 131, 16));
        label_4 = new QLabel(AjoutBorneFontaineInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 160, 71, 16));
        label_5 = new QLabel(AjoutBorneFontaineInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 190, 61, 16));
        label_6 = new QLabel(AjoutBorneFontaineInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 220, 58, 16));
        label_7 = new QLabel(AjoutBorneFontaineInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 250, 111, 16));
        lineEditDirection = new QLineEdit(AjoutBorneFontaineInterface);
        lineEditDirection->setObjectName(QString::fromUtf8("lineEditDirection"));
        lineEditDirection->setGeometry(QRect(220, 90, 113, 28));
        lineEditNomTopographique = new QLineEdit(AjoutBorneFontaineInterface);
        lineEditNomTopographique->setObjectName(QString::fromUtf8("lineEditNomTopographique"));
        lineEditNomTopographique->setGeometry(QRect(220, 120, 113, 28));
        lineEditVille = new QLineEdit(AjoutBorneFontaineInterface);
        lineEditVille->setObjectName(QString::fromUtf8("lineEditVille"));
        lineEditVille->setGeometry(QRect(220, 210, 113, 28));
        lineEditArrondissement = new QLineEdit(AjoutBorneFontaineInterface);
        lineEditArrondissement->setObjectName(QString::fromUtf8("lineEditArrondissement"));
        lineEditArrondissement->setGeometry(QRect(220, 240, 113, 28));
        doubleSpinBoxLongitude = new QDoubleSpinBox(AjoutBorneFontaineInterface);
        doubleSpinBoxLongitude->setObjectName(QString::fromUtf8("doubleSpinBoxLongitude"));
        doubleSpinBoxLongitude->setGeometry(QRect(220, 150, 111, 26));
        doubleSpinBoxLongitude->setMinimum(-1000000.000000000000000);
        doubleSpinBoxLongitude->setMaximum(1000000.000000000000000);
        doubleSpinBoxLatitude = new QDoubleSpinBox(AjoutBorneFontaineInterface);
        doubleSpinBoxLatitude->setObjectName(QString::fromUtf8("doubleSpinBoxLatitude"));
        doubleSpinBoxLatitude->setGeometry(QRect(220, 180, 111, 26));
        doubleSpinBoxLatitude->setMinimum(-1000000.000000000000000);
        doubleSpinBoxLatitude->setMaximum(1000000.000000000000000);
        pushButtonOK = new QPushButton(AjoutBorneFontaineInterface);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(140, 390, 90, 28));
        spinBoxIdentifiant = new QSpinBox(AjoutBorneFontaineInterface);
        spinBoxIdentifiant->setObjectName(QString::fromUtf8("spinBoxIdentifiant"));
        spinBoxIdentifiant->setGeometry(QRect(220, 60, 111, 26));
        spinBoxIdentifiant->setMinimum(1);
        spinBoxIdentifiant->setMaximum(999999);

        retranslateUi(AjoutBorneFontaineInterface);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), AjoutBorneFontaineInterface, SLOT(validerValeur()));

        QMetaObject::connectSlotsByName(AjoutBorneFontaineInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutBorneFontaineInterface)
    {
        AjoutBorneFontaineInterface->setWindowTitle(QApplication::translate("AjoutBorneFontaineInterface", "AjoutBorneFontaineInterface", nullptr));
        label->setText(QApplication::translate("AjoutBorneFontaineInterface", "Identifiant :", nullptr));
        label_2->setText(QApplication::translate("AjoutBorneFontaineInterface", "Direction :", nullptr));
        label_3->setText(QApplication::translate("AjoutBorneFontaineInterface", "Nom Topographique :", nullptr));
        label_4->setText(QApplication::translate("AjoutBorneFontaineInterface", "Longitude :", nullptr));
        label_5->setText(QApplication::translate("AjoutBorneFontaineInterface", "Latitude :", nullptr));
        label_6->setText(QApplication::translate("AjoutBorneFontaineInterface", "Ville :", nullptr));
        label_7->setText(QApplication::translate("AjoutBorneFontaineInterface", "Arrondissement : ", nullptr));
        pushButtonOK->setText(QApplication::translate("AjoutBorneFontaineInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutBorneFontaineInterface: public Ui_AjoutBorneFontaineInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTBORNEFONTAINEINTERFACE_H
