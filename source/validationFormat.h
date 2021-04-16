/**
 * \file   validationFormat.h
 * \brief Déclaration des fonctions utilisées dans validationFormat.cpp
 * \author David Ferland
 * \date  15 février 2021
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H



namespace util
{
  double convertirChaineEnDouble (const std::string& p_chaine);
  bool valideLigneCVS (const std::string& p_ligne, std::ostringstream& p_parametres);
  bool validerGeom (const std::string& p_geom);
  bool valideStationnementGEOJSON (const std::string& p_enregistrement, std::ostringstream& p_attributs);
  bool validerPointCardinal (const std::string& p_cardinalite);
}

#endif /* VALIDATIONFORMAT_H */

