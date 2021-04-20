/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutBorneFontaineInterface.cpp
 * Author: etudiant
 *
 * Created on 19 avril 2021, 20:47
 */

#include "AjoutBorneFontaineInterface.h"
#include <QMessageBox>

using namespace bornesQuebec;

AjoutBorneFontaineInterface::AjoutBorneFontaineInterface ()
{
  widget.setupUi (this);
}

AjoutBorneFontaineInterface::~AjoutBorneFontaineInterface () { }

int
AjoutBorneFontaineInterface::reqIdentifiant () const
{
  return widget.spinBoxIdentifiant->value ();
}

QString
AjoutBorneFontaineInterface::reqDirection () const
{
  return widget.lineEditDirection->text ();
}

QString
AjoutBorneFontaineInterface::reqNomTopographique () const
{
  return widget.lineEditNomTopographique->text ();
}

double
AjoutBorneFontaineInterface::reqLongitude () const
{
  return widget.doubleSpinBoxLongitude->value ();
}

double
AjoutBorneFontaineInterface::reqLatitude () const
{
  return widget.doubleSpinBoxLatitude->value ();
}

QString
AjoutBorneFontaineInterface::reqVille () const
{
  return widget.lineEditVille->text ();
}

QString
AjoutBorneFontaineInterface::reqArrondissement () const
{
  return widget.lineEditArrondissement->text ();
}

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