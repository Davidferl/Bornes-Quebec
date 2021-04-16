/**
 * \file   BorneFontaineTesteur.cpp
 * \brief  Testeur de la classe BorneFontaine
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "BorneFontaine.h"
#include "ContratException.h"

using namespace bornesQuebec;

/**
 * \test Test du constructeur de BorneFontaine
 * Cas valides: Creation d'un objet BorneFontaine et verification de l'assignation de tous les attributs
 * Cas invalides:
 *      Si la ville est Québec l'arrondissement ne doit pas être vide
 */
TEST (BorneFontaine, ConstructeurAvecParamValide)
{
  BorneFontaine uneBorneFontaine (312, "Nord", "Rue Verdun", -72.6537, 54.8764, "Québec", "Ste-Foy");
  ASSERT_EQ (312, uneBorneFontaine.reqIdentifiant ());
  ASSERT_EQ ("Nord", uneBorneFontaine.reqDirection ());
  ASSERT_EQ ("Rue Verdun", uneBorneFontaine.reqNomTopographique ());
  ASSERT_EQ (-72.6537, uneBorneFontaine.reqLongitude ());
  ASSERT_EQ (54.8764, uneBorneFontaine.reqLatitude ());
  ASSERT_EQ ("Québec", uneBorneFontaine.reqVille ());
  ASSERT_EQ ("Ste-Foy", uneBorneFontaine.reqArrondissement ());

}

TEST (BorneFontaine, ConstructeurVilleEstPasQuebec)
{
  BorneFontaine uneBorneFontaine (312, "Nord", "Rue Verdun", -72.6537, 54.8764, "Lévis", "");
  ASSERT_EQ (312, uneBorneFontaine.reqIdentifiant ());
  ASSERT_EQ ("Nord", uneBorneFontaine.reqDirection ());
  ASSERT_EQ ("Rue Verdun", uneBorneFontaine.reqNomTopographique ());
  ASSERT_EQ (-72.6537, uneBorneFontaine.reqLongitude ());
  ASSERT_EQ (54.8764, uneBorneFontaine.reqLatitude ());
  ASSERT_EQ ("Lévis", uneBorneFontaine.reqVille ());
  ASSERT_EQ ("", uneBorneFontaine.reqArrondissement ());

}

TEST (BorneFontaine, ConstructeurVilleInvalide)
{
  ASSERT_THROW (BorneFontaine uneBorneFontaine (312, "Nord", "Rue Verdun", -72.6537, 54.8764, "Québec", ""), PreconditionException);
}

/**
 * \class uneBorneFontaine
 * \brief Creation d'une fixture à utiliser pour les methodes publiques de la classe BorneFontaine
 *
 */
class uneBorneFontaine : public ::testing::Test
{
public:

  uneBorneFontaine () :
  borneFontaineValide (312, "Nord", "Rue Verdun", -72.6537, 54.8764, "Québec", "Ste-Foy") { };
  BorneFontaine borneFontaineValide;
};

/**
 * \test Test de la méthode reqVille()
 *      Cas valide: verifier le retour de la ville
 *      Cas invalide: aucun
 */
TEST_F (uneBorneFontaine, reqVille)
{
  ASSERT_EQ ("Québec", borneFontaineValide.reqVille ());
}

/**
 * \test Test de la méthode reqArrondissement()
 *      Cas valide: verifier le retour de l'arrondissement
 *      Cas invalide: aucun
 */
TEST_F (uneBorneFontaine, reqArrondissement)
{
  ASSERT_EQ ("Ste-Foy", borneFontaineValide.reqArrondissement ());
}

/**
 * \test Test de la méthode reqBorneFormate()
 *      Cas valide: verifier le retour de la Borne formatée
 *      Cas invalide: aucun
 */
TEST_F (uneBorneFontaine, reqBorneFormate)
{
  ASSERT_EQ ("Borne-fontaine\n"
             "----------------------------------------------\n"
             "Identifiant de la borne    : 312\n"
             "Direction           : Nord\n"
             "Nom Topographique   : Rue Verdun\n"
             "Longitude           : -72.6537\n"
             "Latitude            : 54.8764\n"
             "Ville               : Québec\n"
             "Arrondissement      : Ste-Foy\n"
             , borneFontaineValide.reqBorneFormate ());
}

/**
 *\test Test de la méthode clone
 *
 */
TEST_F (uneBorneFontaine, cloneBorneFontaine)
{
  ASSERT_EQ (borneFontaineValide.reqBorneFormate (), borneFontaineValide.clone ()->reqBorneFormate ());
  delete borneFontaineValide.clone ();
}
