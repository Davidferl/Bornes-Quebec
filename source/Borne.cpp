/**
 * \file   Borne.cpp
 * \brief  Implémentation de la classe Borne
 * \author David Ferland
 * \version 0.2
 * \date 22 février 2021
 */

#include "Borne.h"
#include <sstream>
using namespace bornesQuebec;

/**
 * \brief Constructeur d'un objet Borne avec paramètres
 * \param[in] p_identifiant l'identifiant de la borne
 * \param[in] p_direction le côté du centre de chaussé ou l'intersection dans le cas d'un terre-plein, point cardinal
 * \param[in] p_nomTopographique le nom topographique (générique, liaison, spécifique, direction) du centre de la chaussée
 * \param[in] p_longitude longitude de l'emplacement de la borne
 * \param[in] p_latitude latitude de l'emplacement de la borne
 * \pre p_identifiant doit être plus grand que 0
 * \pre p_direction doit être validé par validerPointCardinal
 * \pre p_nomTopographie ne doit pas être vide
 * \post m_identifiant doit prendre la valeur de p_identifiant
 * \post m_direction doit prendre la valeur de p_direction
 * \post m_nomTopographique doit prendre la valeur de p_nomTopographique
 * \post m_longitude doit prendre la valeur de p_longitude
 * \post m_latitude doit prendre la valeur de p_latitude
 * \return Un objet Borne
 */
Borne::Borne (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
              double p_longitude, double p_latitude)
: m_identifiant (p_identifiant), m_direction (p_direction), m_nomTopographique (p_nomTopographique),
m_longitude (p_longitude), m_latitude (p_latitude)
{
  PRECONDITION (p_identifiant > 0);
  PRECONDITION (util::validerPointCardinal (p_direction) == true);
  PRECONDITION (!p_nomTopographique.empty ())

  POSTCONDITION (m_identifiant == p_identifiant);
  POSTCONDITION (m_direction == p_direction);
  POSTCONDITION (m_nomTopographique == p_nomTopographique);
  POSTCONDITION (m_longitude == p_longitude);
  POSTCONDITION (m_latitude == p_latitude);
  INVARIANTS ();

}

/**
 * \brief Acesseur pour l'identifiant de la borne
 * \return m_identifiant l'identifiant de l'objet Borne
 */
int
Borne::reqIdentifiant () const
{
  return m_identifiant;
}

/**
 * \brief Acesseur pour la direction
 * \return m_direction la direction de l'objet Borne
 */
const std::string&
Borne::reqDirection () const
{
  return m_direction;
}

/**
 * \brief Acesseur pour le nom topographique
 * \return m_nomTopographique le nom topographique l'objet Borne
 */
const std::string&
Borne::reqNomTopographique () const
{
  return m_nomTopographique;
}

/**
 * \brief Acesseur pour la longitude de la borne
 * \return m_longitude la longitude de l'objet Borne
 */
double
Borne::reqLongitude () const
{
  return m_longitude;
}

/**
 * \brief Acesseur pour la latitude de la borne
 * \return m_latitude la latitude de l'objet Borne
 */
double
Borne::reqLatitude () const
{
  return m_latitude;
}

/**
 * \brief Mutateur pour le nom topographique, modifie m_nomTopographique
 * \param[in] p_nomTopographique le nouveau nom topographique
 */
void
Borne::asgNomTopographique (const std::string& p_nomTopographique)
{
  PRECONDITION (!p_nomTopographique.empty ());
  m_nomTopographique = p_nomTopographique;
  POSTCONDITION (m_nomTopographique == p_nomTopographique);
  INVARIANTS ();
}

/**
 * \brief Retourne une chaine de caractère qui contient l'information de l'objet Borne
 * \return Un string qui contient l'information
 */
std::string
Borne::reqBorneFormate () const
{
  std::ostringstream os;
  os << "Identifiant de la borne    : " << reqIdentifiant () << "\n" << "Direction           : "
          << reqDirection () << "\n" << "Nom Topographique   : " << reqNomTopographique () << "\n"
          << "Longitude           : " << reqLongitude () << "\n" << "Latitude            : " << reqLatitude () << "\n";

  return os.str ();

}

/**
 * \brief Fais la comparaison entre 2 objets Borne
 * \param[in] Un objet Borne
 * \return Un booléens qui indique si les objets sont égaux (true) ou non (false)
 */
bool Borne::operator== (const Borne& p_borne) const
{
  return m_identifiant == p_borne.m_identifiant && m_direction == p_borne.m_direction
          && m_nomTopographique == p_borne.m_nomTopographique && m_longitude == p_borne.m_longitude
          && m_latitude == p_borne.m_latitude;

}

/**
 * \brief Teste les invariants de la classe Borne, s'assure que la borne est valide
 */
void
Borne::verifieInvariant () const
{
  INVARIANT (m_identifiant > 0);
  INVARIANT (util::validerPointCardinal (m_direction) == true);
  INVARIANT (!(m_nomTopographique.empty ()));

}