/**
 * \file   SupprimeBorneInterface.cpp
 * \brief  Implémentation de la fenêtre SupprimeBorneInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#include "SupprimeBorneInterface.h"

/**
 * \brief
 *
 */
SupprimeBorneInterface::SupprimeBorneInterface ()
{
  widget.setupUi (this);
}

SupprimeBorneInterface::~SupprimeBorneInterface () { }

int
SupprimeBorneInterface::reqIdentifiant () const
{
  return widget.spinBoxIdentifiant->value ();
}