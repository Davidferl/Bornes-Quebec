/**
 * \file   RegistreBorne.cpp
 * \brief  Implémentation de la classe RegistreBorne
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */


#include "RegistreBorne.h"
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
  for (int i = 0; i < m_vBornes.size (); i++)
    {
      if (m_vBornes[i]->reqIdentifiant () == p_borne.reqIdentifiant ())
        {
          return true;
        }
      else
        {
          return false;
        }
    }
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

    }
  else
    {
      m_vBornes.push_back (p_borne.clone ());
    }

}

/**
 * \brief Libère la mémoire du vecteur de RegistreBorne
 *
 */
void
RegistreBorne::effaceLeRegistre ()
{
  for (int i = 0; i < m_vBornes.size (); i++)
    {
      delete m_vBornes[i];
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
  for (int i = 0; i < p_registreBorne.m_vBornes.size (); i++)
    {
      ajouteBorne (*(p_registreBorne.m_vBornes[i]));
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
RegistreBorne::reqRegistreBorneFormate ()
{
  std::ostringstream os;
  os << "Registre : " << reqNomRegistreBorne () << std::endl;
  for (int i = 0; i < m_vBornes.size (); i++)
    {
      os << m_vBornes[i]->reqBorneFormate ();
      os << "----------------------------------------------\n";
    }
  return os.str ();
}

/**
 * \brief Teste les invariants de la classe RegistreBorne, s'assure que le registre est valide
 */
void
RegistreBorne::verifieInvariant () const
{
  INVARIANT (!m_nomRegistreBorne.empty ());
}