/**
 * \file   RegistreBorne.cpp
 * \brief  Implémentation de la classe RegistreBorne
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */


#include "RegistreBorne.h"
#include "BorneException.h"
#include <iostream>
#include <sstream>

using namespace bornesQuebec;

/**
 * \brief Constructeur d'un objet RegistreBorne vide
 * \param[in] p_nomRegistreBorne le nom du registre de bornes
 * \pre p_nomRegistreBorne doit être non-vide
 * \post m_nomRegistreBorne prend la valeur de p_nomRegistreBorne
 * \return Un objet RegistreBorne avec un nom seulement
 */
RegistreBorne::RegistreBorne (const std::string& p_nomRegistreBorne) : m_nomRegistreBorne (p_nomRegistreBorne)
{
  PRECONDITION (!p_nomRegistreBorne.empty ());
  POSTCONDITION (m_nomRegistreBorne == p_nomRegistreBorne);
  INVARIANTS ();
}

/**
 * \brief Constructeur copie d'un objet RegistreBorne
 * \param[in] p_registreBorne objet RegistreBorne que l'on veut copier
 * \return Un objet RegistreBorne identique à celui passé en paramètre
 */
RegistreBorne::RegistreBorne (const RegistreBorne& p_registreBorne) : m_vBornes (0), m_nomRegistreBorne (p_registreBorne.m_nomRegistreBorne)
{
  copierLeRegistre (p_registreBorne);
  INVARIANTS ();
}

/**
 * \brief Destructeur d'un objet RegistreBorne
 *
 */
RegistreBorne::~RegistreBorne ()
{
  effaceLeRegistre ();
}

/**
 * \brief Surchage de l'operateur = pour assigner des objet RegistreBorne
 * \param[in] p_registreBorne objet RegistreBorne que l'on veut assigner
 * \return Un objet RegistreBorne identique à celui passé en paramètre
 */
const RegistreBorne & RegistreBorne::operator= (const RegistreBorne& p_registreBorne)
{
  if (this != &p_registreBorne)
    {
      effaceLeRegistre ();
      copierLeRegistre (p_registreBorne);
      m_nomRegistreBorne = p_registreBorne.m_nomRegistreBorne;
    }
  INVARIANTS ();
  return *this;

}

/**
 * \brief Vérifie si l'objet Borne passé en paramètre est dans le vecteur de l'objet courant
 * \param[in] p_borne objet Borne que l'on veut verifier
 * \return Un booléens qui indique si l'objet Borne est dans le vecteur
 */
bool
RegistreBorne::borneEstDejaPresente (const Borne & p_borne) const
{
  bool bornePresente = false;
  std::vector<Borne*>::const_iterator it;
  for (it = m_vBornes.begin (); it < m_vBornes.end (); it++)
    {
      if ((*it)->reqIdentifiant () == p_borne.reqIdentifiant ())
        {
          bornePresente = true;
        }
    }
  return bornePresente;
}

/**
 * \brief Vérifie si l'identifiant passé en paramètre est dans le vecteur de l'objet courant
 * \param[in] p_identifiant identifiant de borne que l'on veut verifier
 * \return Un booléens qui indique si l'identifiant de borne est dans le vecteur
 */
bool
RegistreBorne::borneEstDejaPresenteID (int p_identifiant) const
{
  bool bornePresente = false;
  std::vector<Borne*>::const_iterator it;
  for (it = m_vBornes.begin (); it < m_vBornes.end (); it++)
    {
      if ((*it)->reqIdentifiant () == p_identifiant)
        {
          bornePresente = true;
        }
    }
  return bornePresente;
}

/**
 * \brief Ajoute un objet Borne dans le vecteur de l'objet courant
 * \param[in] p_borne objet Borne que l'on veut ajouter
 */
void
RegistreBorne::ajouteBorne (const Borne& p_borne)
{
  if (RegistreBorne::borneEstDejaPresente (p_borne) == true)
    {
      throw BorneDejaPresenteException ("Impossible d'ajouter cette borne car elle est deja presente dans le registre");
    }
  else
    {
      m_vBornes.push_back (p_borne.clone ());
    }
  INVARIANTS ();
}

/**
 * \brief Libère la mémoire du vecteur de RegistreBorne
 *
 */
void
RegistreBorne::effaceLeRegistre ()
{
  std::vector<Borne*>::const_iterator it;
  for (it = m_vBornes.begin (); it < m_vBornes.end (); it++)
    {
      delete (*it);
    }
  m_vBornes.clear ();
}

/**
 * \brief Copie le vecteur de l'objet RegistreBorne passé en paramètre dans un nouvel objet Borne
 * \param[in] p_registreBorne objet RegistreBorne  que l'on veut copier
 */
void
RegistreBorne::copierLeRegistre (const RegistreBorne& p_registreBorne)
{
  std::vector<Borne*>::const_iterator it;
  for (it = p_registreBorne.m_vBornes.begin (); it < p_registreBorne.m_vBornes.end (); it++)

    {
      ajouteBorne (*(*it));
    }
}

/**
 * \brief Accesseur pour le nom de l'objet RegistreBorne
 * \return p_nomRegistreBorne nom de l'objet RegistreBorne
 */
const std::string&
RegistreBorne::reqNomRegistreBorne () const
{
  return m_nomRegistreBorne;
}

/**
 * \brief Retourne une chaine de caractère qui contient l'information de l'objet RegistreBorne
 * \return string qui contient l'information des bornes dans l'objet RegistreBorne
 */
std::string
RegistreBorne::reqRegistreBorneFormate () const
{
  std::ostringstream os;
  os << "Registre : " << reqNomRegistreBorne () << std::endl;
  std::vector<Borne*>::const_iterator it;
  for (it = m_vBornes.begin (); it < m_vBornes.end (); it++)
    {
      os << (*it)->reqBorneFormate ();
      os << "----------------------------------------------\n";
    }
  return os.str ();
}

/**
 * \brief methode qui prend un identifiant de borne en entrée et qui supprime la borne du registre
 * \param[in] p_identifiant
 *
 */
void
RegistreBorne::supprimeBorne (int p_identifiant)
{
  if (borneEstDejaPresenteID (p_identifiant) == false)
    {
      throw BorneAbsenteException ("Impossible de supprimer la borne car elle n'est pas dans le registre");
    }
  else
    {
      std::vector<Borne*>::const_iterator it;
      for (it = m_vBornes.begin (); it < m_vBornes.end (); it++)
        {
          if ((*it)->reqIdentifiant () == p_identifiant)
            {
              delete (*it);
              it = m_vBornes.erase (it);
            }
        }
    }
  INVARIANTS ();
}

/**
 * \brief Teste les invariants de la classe RegistreBorne, s'assure que le registre est valide
 */
void
RegistreBorne::verifieInvariant () const
{
  INVARIANT (!m_nomRegistreBorne.empty ());
}
