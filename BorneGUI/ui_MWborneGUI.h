/********************************************************************************
** Form generated from reading UI file 'MWborneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWBORNEGUI_H
#define UI_MWBORNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWborneGUI
{
public:
    QAction *actionSupprimer_une_borne;
    QAction *actionQuitter;
    QAction *actionBorne_Fontaine;
    QAction *actionBorne_de_Stationnement;
    QWidget *centralwidget;
    QListWidget *listWidgetRegistre;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjout_d_une_borne_au_registre;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MWborneGUI)
    {
        if (MWborneGUI->objectName().isEmpty())
            MWborneGUI->setObjectName(QString::fromUtf8("MWborneGUI"));
        MWborneGUI->resize(800, 600);
        actionSupprimer_une_borne = new QAction(MWborneGUI);
        actionSupprimer_une_borne->setObjectName(QString::fromUtf8("actionSupprimer_une_borne"));
        actionQuitter = new QAction(MWborneGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionBorne_Fontaine = new QAction(MWborneGUI);
        actionBorne_Fontaine->setObjectName(QString::fromUtf8("actionBorne_Fontaine"));
        actionBorne_de_Stationnement = new QAction(MWborneGUI);
        actionBorne_de_Stationnement->setObjectName(QString::fromUtf8("actionBorne_de_Stationnement"));
        centralwidget = new QWidget(MWborneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidgetRegistre = new QListWidget(centralwidget);
        listWidgetRegistre->setObjectName(QString::fromUtf8("listWidgetRegistre"));
        listWidgetRegistre->setGeometry(QRect(5, 11, 791, 551));
        MWborneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MWborneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjout_d_une_borne_au_registre = new QMenu(menuMenu);
        menuAjout_d_une_borne_au_registre->setObjectName(QString::fromUtf8("menuAjout_d_une_borne_au_registre"));
        MWborneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(MWborneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MWborneGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjout_d_une_borne_au_registre->menuAction());
        menuMenu->addAction(actionSupprimer_une_borne);
        menuMenu->addAction(actionQuitter);
        menuAjout_d_une_borne_au_registre->addAction(actionBorne_Fontaine);
        menuAjout_d_une_borne_au_registre->addAction(actionBorne_de_Stationnement);

        retranslateUi(MWborneGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MWborneGUI, SLOT(close()));
        QObject::connect(actionBorne_Fontaine, SIGNAL(triggered()), MWborneGUI, SLOT(dialogAjoutBorneFontaine()));
        QObject::connect(actionBorne_de_Stationnement, SIGNAL(triggered()), MWborneGUI, SLOT(dialogAjoutBorneStat()));
        QObject::connect(actionSupprimer_une_borne, SIGNAL(triggered()), MWborneGUI, SLOT(dialogSupprimerBorne()));

        QMetaObject::connectSlotsByName(MWborneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *MWborneGUI)
    {
        MWborneGUI->setWindowTitle(QApplication::translate("MWborneGUI", "MWborneGUI", nullptr));
        actionSupprimer_une_borne->setText(QApplication::translate("MWborneGUI", "Supprimer une borne", nullptr));
        actionQuitter->setText(QApplication::translate("MWborneGUI", "Quitter", nullptr));
        actionBorne_Fontaine->setText(QApplication::translate("MWborneGUI", "Borne Fontaine", nullptr));
        actionBorne_de_Stationnement->setText(QApplication::translate("MWborneGUI", "Borne de Stationnement", nullptr));
        menuMenu->setTitle(QApplication::translate("MWborneGUI", "Op\303\251rations", nullptr));
        menuAjout_d_une_borne_au_registre->setTitle(QApplication::translate("MWborneGUI", "Ajout d'une borne au registre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWborneGUI: public Ui_MWborneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWBORNEGUI_H
