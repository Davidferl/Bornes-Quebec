/**
 * \file   MWBorneGUI.cpp
 * \brief  Implémentation de la fenêtre principale de borneGUI
 * \author David Ferland
 * \version 0.2
 * \date 18 avril 2021
 */

#include "MWborneGUI.h"
#include "BorneFontaine.h"
#include "AjoutBorneFontaineInterface.h"
#include "AjoutBorneStatInterface.h"
#include "SupprimeBorneInterface.h"
#include <string>
#include "BorneException.h"
#include <QMessageBox>

using namespace bornesQuebec;

MWborneGUI::~MWborneGUI () { }

MWborneGUI::MWborneGUI (QWidget *parent) : QMainWindow (parent), m_registre ("Registre de bornes du Québec 2021")
{
  widget.setupUi (this);
  afficherRegistre (m_registre);

}

void
MWborneGUI::afficherRegistre (RegistreBorne p_registre)
{
  widget.listWidgetRegistre->clear ();
  widget.listWidgetRegistre->addItem (QString::fromStdString ((p_registre).reqRegistreBorneFormate ()));
}

void
MWborneGUI::dialogAjoutBorneFontaine ()
{

  AjoutBorneFontaineInterface saisieBorneFontaine;
  if (saisieBorneFontaine.exec () == QDialog::Accepted)

    {
      Borne* p = nullptr;
      try
        {
          p = saisieBorneFontaine.reqBorne ();
          m_registre.ajouteBorne (*p);
        }
      catch (BorneDejaPresenteException& e)
        {

          QString message = e.what ();
          QMessageBox::information (this, "ERREUR", message);
        }
      delete p;
    }
  afficherRegistre (m_registre);

}

void
MWborneGUI::dialogAjoutBorneStat ()
{
  AjoutBorneStatInterface saisieBorneStat;
  if (saisieBorneStat.exec () == QDialog::Accepted)
    {
      Borne* p = nullptr;
      try
        {
          p = saisieBorneStat.reqBorne ();
          m_registre.ajouteBorne (*p);
        }
      catch (BorneDejaPresenteException& e)
        {
          QString message = e.what ();
          QMessageBox::information (this, "ERREUR", message);
        }
      delete p;
    }
  afficherRegistre (m_registre);

}

void
MWborneGUI::dialogSupprimerBorne ()
{
  SupprimeBorneInterface saisieBorneSupprime;
  if (saisieBorneSupprime.exec () == QDialog::Accepted)
    {
      try
        {
          int ID = saisieBorneSupprime.reqIdentifiant ();
          m_registre.supprimeBorne (ID);
        }
      catch (BorneAbsenteException& e)
        {
          QString message = e.what ();
          QMessageBox::information (this, "ERREUR", message);
        }
    }
  afficherRegistre (m_registre);
}