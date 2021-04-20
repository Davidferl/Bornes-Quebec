/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutBorneStatInterface.cpp
 * Author: etudiant
 *
 * Created on 19 avril 2021, 22:10
 */

#include "AjoutBorneStatInterface.h"
#include <QMessageBox>

using namespace bornesQuebec;

AjoutBorneStatInterface::AjoutBorneStatInterface ()
{
  widget.setupUi (this);
}

AjoutBorneStatInterface::~AjoutBorneStatInterface () { }

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

