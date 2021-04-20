/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutBorneFontaineInterface.h
 * Author: etudiant
 *
 * Created on 19 avril 2021, 20:47
 */

#ifndef _AJOUTBORNEFONTAINEINTERFACE_H
#define _AJOUTBORNEFONTAINEINTERFACE_H

#include "ui_AjoutBorneFontaineInterface.h"
#include "BorneFontaine.h"

class AjoutBorneFontaineInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutBorneFontaineInterface ();
  virtual ~AjoutBorneFontaineInterface ();
  int reqIdentifiant () const;
  QString reqDirection () const;
  QString reqNomTopographique () const;
  double reqLongitude () const;
  double reqLatitude () const;
  QString reqVille () const;
  QString reqArrondissement () const;
  bornesQuebec::Borne* reqBorne () const;

public slots:
  void validerValeur ();

private:
  Ui::AjoutBorneFontaineInterface widget;
};

#endif /* _AJOUTBORNEFONTAINEINTERFACE_H */
