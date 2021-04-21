/**
 * \file   AjoutBorneFontaineInterface.cpp
 * \brief  Implémentation de la fenêtre AjoutBorneInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#include "AjoutBorneFontaineInterface.h"
#include <QMessageBox>

using namespace bornesQuebec;

/**
 * \brief  Constructeur de la fenêtre AjoutBorneFontaineInterface
 *
 */
AjoutBorneFontaineInterface::AjoutBorneFontaineInterface ()
{
  widget.setupUi (this);
}

/**
 * \brief  Destructeur des objets AjoutBorneInterface
 *
 */
AjoutBorneFontaineInterface::~AjoutBorneFontaineInterface () { }

/**
 * \brief Accesseur pour un objet Borne
 * Crée un objet borneStationnement avec les informations entrées dans la fenêtre AjoutBorneStatInterface
 * \return pointeur vers un objet borneStationnement sur le monceau
 */
Borne*
AjoutBorneFontaineInterface::reqBorne () const
{
  return new BorneFontaine (widget.spinBoxIdentifiant->value (),
                            widget.lineEditDirection->text ().toStdString (),
                            widget.lineEditNomTopographique->text ().toStdString (),
                            widget.doubleSpinBoxLongitude->value (),
                            widget.doubleSpinBoxLatitude->value (),
                            widget.lineEditVille->text ().toStdString (),
                            widget.lineEditArrondissement->text ().toStdString ());
}

/**
 * \brief  Slot qui valide les données entrées par l'usager
 *
 */
void
AjoutBorneFontaineInterface::validerValeur ()
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
  if (BorneFontaine::villeEstQuebec (widget.lineEditVille->text ().toStdString (), widget.lineEditArrondissement->text ().toStdString ()) == false)
    {
      QString message ("Si la ville est Québec l'arrondissement ne doit pas être vide!");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();

}