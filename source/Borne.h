
/**
 * \file   Borne.h
 * \brief Prototype de la classe Borne
 * \author David Ferland
 * \version 0.2
 * \date 22 février 2021
 */

#ifndef BORNE_H
#define BORNE_H
#include <string>
#include "ContratException.h"
#include "validationFormat.h"

/**
 * \class Borne
 * \brief Déclaration de la classe Borne, permet de modéliser les objets Borne
 */

namespace bornesQuebec
{

  class Borne
  {
  public:
    Borne (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
           double p_longitude, double p_latitude);

    virtual
    ~Borne () { };
    int reqIdentifiant () const;
    const std::string& reqDirection () const;
    const std::string& reqNomTopographique () const;
    double reqLongitude () const;
    double reqLatitude () const;
    void asgNomTopographique (const std::string& p_nomTopographique);
    bool operator== (const Borne& p_borne) const;
    virtual std::string reqBorneFormate () const = 0;
    virtual Borne* clone () const = 0;




  private:
    void verifieInvariant () const;
    int m_identifiant;
    std::string m_direction;
    std::string m_nomTopographique;
    double m_longitude;
    double m_latitude;
  };
}
#endif /* BORNE_H */

