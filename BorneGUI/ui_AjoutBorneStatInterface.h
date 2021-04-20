/********************************************************************************
** Form generated from reading UI file 'AjoutBorneStatInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTBORNESTATINTERFACE_H
#define UI_AJOUTBORNESTATINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutBorneStatInterface
{
public:
    QLabel *label;
    QSpinBox *spinBoxIdentifiant;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEditDirection;
    QLineEdit *lineEditNomTopographique;
    QDoubleSpinBox *doubleSpinBoxLongitude;
    QDoubleSpinBox *doubleSpinBoxLatitude;
    QLineEdit *lineEditType;
    QDoubleSpinBox *doubleSpinBoxLectureMetrique;
    QSpinBox *spinBoxSegmentRue;
    QSpinBox *spinBoxNumBorne;
    QLineEdit *lineEditCoteRue;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *AjoutBorneStatInterface)
    {
        if (AjoutBorneStatInterface->objectName().isEmpty())
            AjoutBorneStatInterface->setObjectName(QString::fromUtf8("AjoutBorneStatInterface"));
        AjoutBorneStatInterface->resize(400, 520);
        label = new QLabel(AjoutBorneStatInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 71, 16));
        spinBoxIdentifiant = new QSpinBox(AjoutBorneStatInterface);
        spinBoxIdentifiant->setObjectName(QString::fromUtf8("spinBoxIdentifiant"));
        spinBoxIdentifiant->setGeometry(QRect(200, 30, 111, 26));
        spinBoxIdentifiant->setMinimum(1);
        spinBoxIdentifiant->setMaximum(1000000);
        label_2 = new QLabel(AjoutBorneStatInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 60, 71, 16));
        label_3 = new QLabel(AjoutBorneStatInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 90, 141, 16));
        label_4 = new QLabel(AjoutBorneStatInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 120, 71, 16));
        label_5 = new QLabel(AjoutBorneStatInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 150, 58, 16));
        label_6 = new QLabel(AjoutBorneStatInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 180, 58, 16));
        label_7 = new QLabel(AjoutBorneStatInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 210, 121, 16));
        label_8 = new QLabel(AjoutBorneStatInterface);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 240, 111, 16));
        label_9 = new QLabel(AjoutBorneStatInterface);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 270, 121, 16));
        label_10 = new QLabel(AjoutBorneStatInterface);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 300, 101, 16));
        lineEditDirection = new QLineEdit(AjoutBorneStatInterface);
        lineEditDirection->setObjectName(QString::fromUtf8("lineEditDirection"));
        lineEditDirection->setGeometry(QRect(200, 60, 113, 28));
        lineEditNomTopographique = new QLineEdit(AjoutBorneStatInterface);
        lineEditNomTopographique->setObjectName(QString::fromUtf8("lineEditNomTopographique"));
        lineEditNomTopographique->setGeometry(QRect(200, 90, 113, 28));
        doubleSpinBoxLongitude = new QDoubleSpinBox(AjoutBorneStatInterface);
        doubleSpinBoxLongitude->setObjectName(QString::fromUtf8("doubleSpinBoxLongitude"));
        doubleSpinBoxLongitude->setGeometry(QRect(200, 120, 111, 26));
        doubleSpinBoxLongitude->setMinimum(-1000000.000000000000000);
        doubleSpinBoxLongitude->setMaximum(1000000.000000000000000);
        doubleSpinBoxLatitude = new QDoubleSpinBox(AjoutBorneStatInterface);
        doubleSpinBoxLatitude->setObjectName(QString::fromUtf8("doubleSpinBoxLatitude"));
        doubleSpinBoxLatitude->setGeometry(QRect(200, 150, 111, 26));
        doubleSpinBoxLatitude->setDecimals(2);
        doubleSpinBoxLatitude->setMinimum(-1000000.000000000000000);
        doubleSpinBoxLatitude->setMaximum(1000000.000000000000000);
        lineEditType = new QLineEdit(AjoutBorneStatInterface);
        lineEditType->setObjectName(QString::fromUtf8("lineEditType"));
        lineEditType->setGeometry(QRect(200, 180, 113, 28));
        doubleSpinBoxLectureMetrique = new QDoubleSpinBox(AjoutBorneStatInterface);
        doubleSpinBoxLectureMetrique->setObjectName(QString::fromUtf8("doubleSpinBoxLectureMetrique"));
        doubleSpinBoxLectureMetrique->setGeometry(QRect(200, 210, 111, 26));
        doubleSpinBoxLectureMetrique->setMinimum(1.000000000000000);
        doubleSpinBoxLectureMetrique->setMaximum(1000000.000000000000000);
        spinBoxSegmentRue = new QSpinBox(AjoutBorneStatInterface);
        spinBoxSegmentRue->setObjectName(QString::fromUtf8("spinBoxSegmentRue"));
        spinBoxSegmentRue->setGeometry(QRect(200, 240, 111, 26));
        spinBoxSegmentRue->setMinimum(1);
        spinBoxSegmentRue->setMaximum(1000000);
        spinBoxNumBorne = new QSpinBox(AjoutBorneStatInterface);
        spinBoxNumBorne->setObjectName(QString::fromUtf8("spinBoxNumBorne"));
        spinBoxNumBorne->setGeometry(QRect(200, 270, 111, 26));
        spinBoxNumBorne->setMinimum(1);
        spinBoxNumBorne->setMaximum(9999);
        lineEditCoteRue = new QLineEdit(AjoutBorneStatInterface);
        lineEditCoteRue->setObjectName(QString::fromUtf8("lineEditCoteRue"));
        lineEditCoteRue->setGeometry(QRect(200, 300, 113, 28));
        pushButtonOK = new QPushButton(AjoutBorneStatInterface);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(130, 430, 90, 28));

        retranslateUi(AjoutBorneStatInterface);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), AjoutBorneStatInterface, SLOT(validerValeur()));

        QMetaObject::connectSlotsByName(AjoutBorneStatInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutBorneStatInterface)
    {
        AjoutBorneStatInterface->setWindowTitle(QApplication::translate("AjoutBorneStatInterface", "AjoutBorneStatInterface", nullptr));
        label->setText(QApplication::translate("AjoutBorneStatInterface", "Identifiant :", nullptr));
        label_2->setText(QApplication::translate("AjoutBorneStatInterface", "Direction:", nullptr));
        label_3->setText(QApplication::translate("AjoutBorneStatInterface", "Nom Topographique :", nullptr));
        label_4->setText(QApplication::translate("AjoutBorneStatInterface", "Longitude :", nullptr));
        label_5->setText(QApplication::translate("AjoutBorneStatInterface", "Latitude :", nullptr));
        label_6->setText(QApplication::translate("AjoutBorneStatInterface", "Type :", nullptr));
        label_7->setText(QApplication::translate("AjoutBorneStatInterface", "Lecture Metrique :", nullptr));
        label_8->setText(QApplication::translate("AjoutBorneStatInterface", "Segment de rue :", nullptr));
        label_9->setText(QApplication::translate("AjoutBorneStatInterface", "Num\303\251ro de borne :", nullptr));
        label_10->setText(QApplication::translate("AjoutBorneStatInterface", "C\303\264t\303\251 de la rue :", nullptr));
        pushButtonOK->setText(QApplication::translate("AjoutBorneStatInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutBorneStatInterface: public Ui_AjoutBorneStatInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTBORNESTATINTERFACE_H
