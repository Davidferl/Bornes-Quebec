/**
 * \file   AjoutBorneStatInterface.cpp
 * \brief  Implémentation de la fenêtre AjoutBorneStatInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#include "AjoutBorneStatInterface.h"
#include <QMessageBox>

using namespace bornesQuebec;

/**
 * \brief  Constructeur de la fenêtre AjoutBorneInterface
 *
 */
AjoutBorneStatInterface::AjoutBorneStatInterface ()
{
  widget.setupUi (this);
}

/**
 * \brief  Destructeur des objets AjoutBorneInterface
 *
 */
AjoutBorneStatInterface::~AjoutBorneStatInterface () { }

/**
 * \brief Accesseur pour un objet Borne
 * Crée un objet borneStationnement avec les informations entrées dans la fenêtre AjoutBorneStatInterface
 * \return pointeur vers un objet borneStationnement sur le monceau
 */
Borne*
AjoutBorneStatInterface::reqBorne () const
{
  return new BorneStationnement (widget.spinBoxIdentifiant->value (),
                                 widget.lineEditDirection->text ().toStdString (),
                                 widget.lineEditNomTopographique->text ().toStdString (),
                                 widget.doubleSpinBoxLongitude->value (),
                                 widget.doubleSpinBoxLatitude->value (),
                                 widget.lineEditType->text ().toStdString (),
                                 widget.doubleSpinBoxLectureMetrique->value (),
                                 widget.spinBoxSegmentRue->value (),
                                 widget.spinBoxNumBorne->value (),
                                 widget.lineEditCoteRue->text ().toStdString ());
}

/**
 * \brief  Slot qui valide les données entrées par l'usager
 *
 */
void
AjoutBorneStatInterface::validerValeur ()
{
  if (widget.lineEditNomTopographique->text ().isEmpty ())
    {
      QString message ("Le nom topographique ne doit pas être vide!");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (util::validerPointCardinal (widget.lineEditDirection->text ().toStdString ()) == false)
    {
      QString message ("La direction doit être un point cardinal!");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (widget.lineEditType -> text ().toStdString () != "stationnement" && widget.lineEditType -> text ().toStdString () != "paiement")
    {
      QString message ("Le type de la borne doit être soit paiement ou stationnement!");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (util::validerPointCardinal (widget.lineEditCoteRue->text ().toStdString ()) == false)
    {
      QString message ("Le côté de la rue doit être un point cardinal!");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}

