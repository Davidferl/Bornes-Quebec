/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SupprimeBorneInterface.h
 * Author: etudiant
 *
 * Created on 20 avril 2021, 15:56
 */

#ifndef _SUPPRIMEBORNEINTERFACE_H
#define _SUPPRIMEBORNEINTERFACE_H

#include "ui_SupprimeBorneInterface.h"

class SupprimeBorneInterface : public QDialog
{
  Q_OBJECT
public:
  SupprimeBorneInterface ();
  virtual ~SupprimeBorneInterface ();
  int reqIdentifiant () const;
private:
  Ui::SupprimeBorneInterface widget;
};

#endif /* _SUPPRIMEBORNEINTERFACE_H */
