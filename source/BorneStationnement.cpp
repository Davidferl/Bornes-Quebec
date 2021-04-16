/**
 * \file   BorneStationnement.cpp
 * \brief  Implementation de la classe BorneStationnement
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */


#include "BorneStationnement.h"
#include <sstream>

using namespace bornesQuebec;

/**
 * \brief Constructeur d'un objet BorneStationnement avec paramètres
 * \param[in] p_identifiant l'identifiant de la borne
 * \param[in] p_direction le côté du centre de chaussé ou l'intersection dans le cas d'un terre-plein, point cardinal
 * \param[in] p_nomTopographique le nom topographique (générique, liaison, spécifique, direction) du centre de la chaussée
 * \param[in] p_longitude longitude de l'emplacement de la borne
 * \param[in] p_latitude latitude de l'emplacement de la borne
 * \param[in] p_type type de la borne
 * \param[in] p_lectureMetrique la distance mesurée à partir du début du tronçon dans le sens des numéros d'immeuble
 * \param[in] p_segmentRue identifiant de la voie publique
 * \param[in] p_numBorne le numéro de la borne
 * \param[in] p_coteRue le coté par rapport au centre de la chaussée où est la borne
 * \pre p_type doit être soit "stationnement" ou "paiement"
 * \pre p_lectureMetrique doit être plus grand que 0
 * \pre p_segmentRue doit être plus grand que 0
 * \pre p_numBorne doit être situé entre 0 et 10000
 * \pre p_cote doit être validé par validerPointCardinal
 * \post m_type prend la valeur de p_type
 * \post m_lectureMetrique prend la valeur de p_lectureMetrique
 * \post m_segmentRue prend la valeur de p_segmentRue
 * \post m_numBorne prend la valeur de p_numBorne
 * \post m_coteRue prend la valeur de p_coteRue
 * \return Un objet BorneStationnement
 */
BorneStationnement::BorneStationnement (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
                                        double p_longitude, double p_latitude, const std::string& p_type, double p_lectureMetrique,
                                        int p_segmentRue, int p_numBorne, const std::string& p_coteRue) :
Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude), m_type (p_type), m_lectureMetrique (p_lectureMetrique),
m_segmentRue (p_segmentRue), m_numBorne (p_numBorne), m_coteRue (p_coteRue)
{
  PRECONDITION (p_type == "stationnement" || p_type == "paiement");
  PRECONDITION (p_lectureMetrique > 0);
  PRECONDITION (p_segmentRue > 0);
  PRECONDITION (p_numBorne > 0 && p_numBorne < 10000);
  PRECONDITION (util::validerPointCardinal (p_coteRue) == true);

  POSTCONDITION (m_type == p_type);
  POSTCONDITION (m_lectureMetrique == p_lectureMetrique);
  POSTCONDITION (m_segmentRue == p_segmentRue);
  POSTCONDITION (m_numBorne == p_numBorne);
  POSTCONDITION (m_coteRue == p_coteRue);
  INVARIANTS ();
}

/**
 * \brief Acesseur pour le type de la borne stationnement
 * \return m_type le type de la borne stationnement
 */
const std::string&
BorneStationnement::reqType () const
{
  return m_type;
}

/**
 * \brief Acesseur pour la lecture métrique de la borne stationnement
 * \return m_lectureMetrique la lecture métrique de la borne stationnement
 */
double
BorneStationnement::reqLectureMetrique () const
{
  return m_lectureMetrique;
}

/**
 * \brief Acesseur pour le segment de rue de la borne stationnement
 * \return m_segmentRue le segment de rue de la borne stationnement
 */
int
BorneStationnement::reqSegmentRue () const
{
  return m_segmentRue;
}

/**
 * \brief Acesseur pour le numéro de la borne stationnement
 * \return m_numBorne le numéro de la borne stationnement
 */
int
BorneStationnement::reqNumBorne () const
{
  return m_numBorne;
}

/**
 * \brief Acesseur pour le coté de la rue de la borne stationnement
 * \return m_coteRue le coté de la rue de la borne stationnement
 */
const std::string&
BorneStationnement::reqCoteRue () const
{
  return m_coteRue;
}

/**
 * \brief Méthode virtuelle pour faire une copie en profondeur d'un objet BorneStationnement
 * \return Une copie de l'objet BorneStationnement sur le monceau
 */
Borne*
BorneStationnement::clone () const
{
  return new BorneStationnement (*this);
}

/**
 * \brief Retourne une chaine de caractère qui contient l'information de l'objet BorneStationnement
 * \return Un string qui contient l'information
 */
std::string
BorneStationnement::reqBorneFormate () const
{
  std::ostringstream os;
  os << "Borne de stationnement" << std::endl;
  os << "----------------------------------------------" << std::endl;
  os << Borne::reqBorneFormate ();
  os << "Distance mesuree    : " << reqLectureMetrique () << std::endl;
  os << "Segment de rue      : " << reqSegmentRue () << std::endl;
  os << "Numero de la borne  : " << reqNumBorne () << std::endl;
  os << "Cote de la rue      : " << reqCoteRue () << std::endl;
  return os.str ();
}

/**
 * \brief Teste les invariants de la classe BorneFontaine, s'assure que la borne fontaine est valide
 */
void
BorneStationnement::verifieInvariant () const
{
  INVARIANT (m_type == "stationnement" || m_type == "paiement");
  INVARIANT (m_lectureMetrique > 0);
  INVARIANT (m_segmentRue > 0);
  INVARIANT (m_numBorne > 0 && m_numBorne < 10000);
  INVARIANT (util::validerPointCardinal (m_coteRue) == true);
}