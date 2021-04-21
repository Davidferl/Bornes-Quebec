/**
 * \file   AjoutBorneFontaineInterface.h
 * \brief  Prototype de la classe AjoutBorneFontaineInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
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
  bornesQuebec::Borne* reqBorne () const;

public slots:
  void validerValeur ();

private:
  Ui::AjoutBorneFontaineInterface widget;
};

#endif /* _AJOUTBORNEFONTAINEINTERFACE_H */
