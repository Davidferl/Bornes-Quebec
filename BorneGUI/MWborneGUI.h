/**
 * \file   MWborneGUI.h
 * \brief  Prototype de la classe MWborneGUI
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
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
