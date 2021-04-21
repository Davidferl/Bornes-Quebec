/**
 * \file   SupprimeBorneInterface.cpp
 * \brief  Implémentation de la fenêtre SupprimeBorneInterface
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#include "SupprimeBorneInterface.h"

/**
 * \brief Constructeur de la fenêtre SupprimeBorneInterface
 *
 */
SupprimeBorneInterface::SupprimeBorneInterface ()
{
  widget.setupUi (this);
}

/**
 * \brief Destructeur de la fenêtre SupprimeBorneInterface
 *
 */
SupprimeBorneInterface::~SupprimeBorneInterface () { }

/**
 * \brief Accesseur qui retourne l'identifiant de bornes entré par l'utilisateur
 *
 */
int
SupprimeBorneInterface::reqIdentifiant () const
{
  return widget.spinBoxIdentifiant->value ();
}