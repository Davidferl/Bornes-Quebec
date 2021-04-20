/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SupprimeBorneInterface.cpp
 * Author: etudiant
 *
 * Created on 20 avril 2021, 15:56
 */

#include "SupprimeBorneInterface.h"

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