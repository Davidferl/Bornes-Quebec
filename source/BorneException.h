/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * \file   BorneException.h
 * \brief
 * \author David Ferland
 * \date 16 avril 2021, 15:50
 */

#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H

#include <stdexcept>

/**
 * \class BorneException
 * \brief Déclaration de la classe BorneException
 * Cette classe hérite de runtime_error et crée des exceptions pour les Bornes
 */
class BorneException : public std::runtime_error
{
public:

  BorneException (const std::string& p_raison) : std::runtime_error (p_raison) { }
};

/**
 * \class BorneDejaPresenteException
 * \brief Déclaration de la classe BorneDejaPresenteException
 * Cette classe hérite de BorneException et crée des exceptions de type BorneDejaPresente
 */
class BorneDejaPresenteException : public BorneException
{
public:

  BorneDejaPresenteException (const std::string& p_raison) : BorneException (p_raison) { }
};

/**
 * \class BorneAbsenteException
 * \brief Déclaration de la classe AbsenteException
 * Cette classe hérite de BorneException et crée des exceptions de type BorneAbsente
 */
class BorneAbsenteException : public BorneException
{
public:

  BorneAbsenteException (const std::string& p_raison) : BorneException (p_raison) { }
};
#endif /* BORNEEXCEPTION_H */

