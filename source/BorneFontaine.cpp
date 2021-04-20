/**
 * \file   BorneFontaine.cpp
 * \brief  Implementation de la classe BorneFontaine
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#include "BorneFontaine.h"
#include <sstream>


using namespace bornesQuebec;

/**
 * \brief Constructeur d'un objet BorneFontaine avec paramètres
 * \param[in] p_identifiant l'identifiant de la borne
 * \param[in] p_direction le côté du centre de chaussé ou l'intersection dans le cas d'un terre-plein, point cardinal
 * \param[in] p_nomTopographique le nom topographique (générique, liaison, spécifique, direction) du centre de la chaussée
 * \param[in] p_longitude longitude de l'emplacement de la borne
 * \param[in] p_latitude latitude de l'emplacement de la borne
 * \param[in] p_ville où se situe la borne fontaine
 * \param[in] p_arrondissement arrondissement de la location de la borne fontaine
 * \pre L'arrondissement ne doit pas être vide si la ville est Québec (vérifié par la méthode villeEstQuebec)
 * \post m_ville prend la valeur de p_ville
 * \post m_arrondissement prend la valeur de p_arrondissement
 * \return Un objet BorneFontaine
 */
BorneFontaine::BorneFontaine (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
                              double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement)
: Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude), m_ville (p_ville), m_arrondissement (p_arrondissement)
{
  PRECONDITION (BorneFontaine::villeEstQuebec (p_ville, p_arrondissement) == true);
  POSTCONDITION (m_ville == p_ville);
  POSTCONDITION (m_arrondissement == p_arrondissement);
  INVARIANTS ();
}

/**
 * \brief Méthode statique pour verifier les paramètres du constructeur de BorneFontaine
 * \param[in] p_ville ville où se situe la borne fontaine
 * \param[in] p_arrondissement arrondissement de la location de la borne fontaine
 * \return Un booléen qui approuve ou non les paramètres du constructeur de BorneFontaine
 */
bool
BorneFontaine::villeEstQuebec (const std::string& p_ville, const std::string& p_arrondissement)
{
  if (p_ville == "Québec" && !p_arrondissement.empty ())
    {
      return true;
    }
  else if (p_ville != "Québec")
    {
      return true;
    }
  else
    {

      return false;
    }
}

/**
 * \brief Acesseur pour la ville où se trouve la borne
 * \return m_ville la ville où se trouve la borne
 */
const std::string&
BorneFontaine::reqVille () const
{

  return m_ville;
}

/**
 * \brief Acesseur pour l'arrondissement où se trouve la borne
 * \return m_arrondissement l'arrondissement où se trouve la borne
 */
const std::string&
BorneFontaine::reqArrondissement () const
{

  return m_arrondissement;
}

/**
 * \brief Retourne une chaine de caractère qui contient l'information de l'objet BorneFontaine
 * \return Un string qui contient l'information
 */
std::string
BorneFontaine::reqBorneFormate () const
{
  std::ostringstream os;
  os << "Borne-fontaine" << std::endl;
  os << "----------------------------------------------" << std::endl;
  os << Borne::reqBorneFormate ();
  os << "Ville                                     : " << reqVille () << std::endl;
  os << "Arrondissement              : " << reqArrondissement () << std::endl;
  return os.str ();
}

/**
 * \brief Méthode virtuelle pour faire une copie en profondeur d'un objet BorneFontaine
 * \return Une copie de l'objet BorneFontaine sur le monceau
 */
Borne*
BorneFontaine::clone () const
{
  return new BorneFontaine (*this);
}

/**
 * \brief Teste les invariants de la classe BorneFontaine, s'assure que la borne fontaine est valide
 */
void
BorneFontaine::verifieInvariant () const
{
  INVARIANT (villeEstQuebec (m_ville, m_arrondissement) == true);
}


