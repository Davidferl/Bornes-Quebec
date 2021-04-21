/**
 * \file   RegistreBorne.h
 * \brief  Prototype de la classe RegistreBorne
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H
#include "Borne.h"
#include <vector>

/**
 * \class RegistreBorne
 * \brief Déclaration de la classe RegistreBorne
 */
namespace bornesQuebec
{

  class RegistreBorne
  {
  public:
    RegistreBorne (const std::string& p_nomRegistreBorne);
    RegistreBorne (const RegistreBorne& p_registreBorne);
    ~RegistreBorne ();
    const RegistreBorne& operator= (const RegistreBorne& p_registreBorne);
    const std::string& reqNomRegistreBorne () const;
    void ajouteBorne (const Borne& p_borne);
    std::string reqRegistreBorneFormate () const;
    void supprimeBorne (int p_identifiant);


  private:
    std::string m_nomRegistreBorne;
    std::vector<Borne*> m_vBornes;
    bool borneEstDejaPresente (const Borne& p_borne) const;
    bool borneEstDejaPresenteID (int p_identifiant) const;
    void effaceLeRegistre ();
    void copierLeRegistre (const RegistreBorne& p_registreBorne);
    void verifieInvariant () const;


  };
}
#endif /* REGISTREBORNE_H */

