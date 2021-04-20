/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MWborneGUI.h
 * Author: etudiant
 *
 * Created on 18 avril 2021, 17:16
 */

#ifndef _MWBORNEGUI_H
#define _MWBORNEGUI_H

#include "ui_MWborneGUI.h"
#include "Borne.h"
#include "RegistreBorne.h"
#include "BorneFontaine.h"

class MWborneGUI : public QMainWindow
{
  Q_OBJECT
public:

  MWborneGUI (QWidget *parent = 0);
  virtual ~MWborneGUI ();
  void afficherRegistre (bornesQuebec::RegistreBorne p_registre);


public slots:
  void dialogAjoutBorneFontaine ();
  void dialogAjoutBorneStat ();
  void dialogSupprimerBorne ();


private:
  Ui::MWborneGUI widget;
  bornesQuebec::RegistreBorne m_registre;

};

#endif /* _MWBORNEGUI_H */
