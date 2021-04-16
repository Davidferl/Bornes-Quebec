/**
 * \file   BorneStationnement.h
 * \brief  Prototype de la classe BorneStationnement
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */


#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H

#include "Borne.h"

/**
 * \class BorneStationnement
 * \brief Déclaration de la classe BorneStationnement, permet de modéliser les objets BorneStationnement
 */

namespace bornesQuebec
{

  class BorneStationnement : public bornesQuebec::Borne
  {
  public:
    BorneStationnement (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
                        double p_longitude, double p_latitude, const std::string& p_type, double p_lectureMetrique,
                        int p_segmentRue, int p_numBorne, const std::string& p_coteRue);

    const std::string& reqType () const;
    double reqLectureMetrique () const;
    int reqSegmentRue () const;
    int reqNumBorne () const;
    const std::string& reqCoteRue () const;
    virtual std::string reqBorneFormate () const;
    virtual Borne* clone () const;

  private:
    std::string m_type;
    double m_lectureMetrique;
    int m_segmentRue;
    int m_numBorne;
    std::string m_coteRue;
    void verifieInvariant () const;



  };
}
#endif /* BORNESTATIONNEMENT_H */

