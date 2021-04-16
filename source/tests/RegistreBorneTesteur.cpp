/**
 * \file   RegistreBorneTesteur.cpp
 * \brief  Testeur de la classe RegistreBorne
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "RegistreBorne.h"
#include "ContratException.h"
#include "BorneFontaine.h"

using namespace bornesQuebec;

/**
 * \test Test du constructeur de RegistreBorne avec un nom
 * Cas valides: Creation d'un objet RegistreBorne et verification de l'assignation de son nom
 * Cas invalides:
 *      Le nom est vide
 */
TEST (RegistreBorne, ConstructeurNom)
{
  RegistreBorne unRegistreBorne ("premierRegistre");
  ASSERT_EQ ("premierRegistre", unRegistreBorne.reqNomRegistreBorne ());
}

TEST (RegistreBorne, ConstructeurNomInvalide)
{
  ASSERT_THROW (RegistreBorne unRegistreBorne (""), PreconditionException);
}

/**
 * \class RegsitreBorneFixture
 * \brief Creation d'une fixture a utiliser pour les methodes publiques de la classe RegsitreBorne
 *
 */
class RegistreBorneFixture : public ::testing::Test
{
public:

  RegistreBorneFixture () :
  RegistreBorneNomValide ("premierRegistre"), uneBorneFontaine (312, "Nord", "Rue Verdun", -72.6537, 54.8764, "Québec", "Ste-Foy"),
  unAutreRegistreBorne ("Autre Registre") { };
  RegistreBorne RegistreBorneNomValide;
  BorneFontaine uneBorneFontaine;
  RegistreBorne unAutreRegistreBorne;


};

/**
 * \test Test de la méthode reqNomRegistreBorne()
 *      Cas valide: verifier le retour de du nom du registre
 *      Cas invalide: aucun
 */
TEST_F (RegistreBorneFixture, reqNomRegistreBorne)
{
  ASSERT_EQ ("premierRegistre", RegistreBorneNomValide.reqNomRegistreBorne ());
}

/**
 * \test Test de la méthode reqRegsitreBorneFormate()
 *      Cas valide: verifier le retour de la borne formatee
 *      Cas invalide: aucun
 */
TEST_F (RegistreBorneFixture, reqRegistreBorneFormate)
{

  ASSERT_EQ ("Registre : premierRegistre\n", RegistreBorneNomValide.reqRegistreBorneFormate ());
}

/**
 * \test Test du constructeur copie
 *      Cas valide: verifier que la borne à été copié
 *      Cas invalide: aucun
 */
TEST_F (RegistreBorneFixture, ConstructeurCopie)
{

  RegistreBorne RegistreBorneCopie (RegistreBorneNomValide);
  EXPECT_EQ (RegistreBorneNomValide.reqRegistreBorneFormate (), RegistreBorneCopie.reqRegistreBorneFormate ());
}

/**
 * \test Test de la méthode ajouteBorne()
 *      Cas valide: verifier que la borne à été ajouter au registre
 *      Cas invalide: aucun
 */
TEST_F (RegistreBorneFixture, ajouteBorne)
{

  RegistreBorneNomValide.ajouteBorne (uneBorneFontaine);
  ASSERT_EQ (RegistreBorneNomValide.reqRegistreBorneFormate (),
             "Registre : premierRegistre\n" + uneBorneFontaine.reqBorneFormate () + "----------------------------------------------\n");
}

/**
 * \test Test de l'opérateur d'assignation
 *      Cas valide: verifier que le Regsitre à été copié
 *      Cas invalide: aucun
 */
TEST_F (RegistreBorneFixture, OperateurAssignation)
{
  RegistreBorneNomValide.ajouteBorne (uneBorneFontaine);
  unAutreRegistreBorne = RegistreBorneNomValide;
  ASSERT_EQ (unAutreRegistreBorne.reqRegistreBorneFormate (),
             "Registre : premierRegistre\n" + uneBorneFontaine.reqBorneFormate () + "----------------------------------------------\n");
}

/*TEST_F (RegistreBorneFixture, ajouteBorneDejaPresenteThrow)
{
RegistreBorneNomValide.ajouteBorne (uneBorneFontaine);
ASSERT_THROW (RegistreBorneNomValide.ajouteBorne (uneBorneFontaine), BorneEstDejaPresenteException);
}*/
