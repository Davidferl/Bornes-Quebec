/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutBorneStatInterface.h
 * Author: etudiant
 *
 * Created on 19 avril 2021, 22:10
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
