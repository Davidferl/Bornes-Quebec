/**
 * \file   AjoutBorneStatInterface.h
 * \brief  Prototype de la classe AjoutBorneStatInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#ifndef _AJOUTBORNESTATINTERFACE_H
#define _AJOUTBORNESTATINTERFACE_H

#include "ui_AjoutBorneStatInterface.h"
#include "BorneStationnement.h"

class AjoutBorneStatInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutBorneStatInterface ();
  virtual ~AjoutBorneStatInterface ();
  bornesQuebec::Borne* reqBorne () const;
public slots:
  void validerValeur ();
private:
  Ui::AjoutBorneStatInterface widget;
};

#endif /* _AJOUTBORNESTATINTERFACE_H */
