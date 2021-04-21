/**
 * \file   SupprimeBorneInterface.h
 * \brief  Prototype de la classe SupprimeBorneInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
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
