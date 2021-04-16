/**
 * \file   BorneFontaine.h
 * \brief  Prototype de la classe BorneFontaine
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H

#include "Borne.h"

/**
 * \class BorneFontaine
 * \brief Déclaration de la classe BorneFontaine, permet de modéliser les objets BorneFontaine
 */

namespace bornesQuebec
{

  class BorneFontaine : public bornesQuebec::Borne
  {
  public:
    BorneFontaine (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
                   double p_longitude, double p_latitude, const std::string& p_ville, const std::string& p_arrondissement);
    const std::string& reqVille () const;
    const std::string& reqArrondissement () const;
    static bool villeEstQuebec (const std::string& p_ville, const std::string& p_arrondissement);
    virtual Borne* clone () const;
    virtual std::string reqBorneFormate () const;

  private:
    std::string m_ville;
    std::string m_arrondissement;
    void verifieInvariant () const;

  };
}
#endif /* BORNEFONTAINE_H */

