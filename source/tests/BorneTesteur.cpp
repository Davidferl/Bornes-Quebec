/**
 * \file   BorneTesteur.cpp
 * \brief  Testeur de la classe Borne
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "Borne.h"
#include "ContratException.h"

using namespace bornesQuebec;

class BorneTest : public Borne
{
public:

  BorneTest (int p_identifiant, const std::string& p_direction, const std::string& p_nomTopographique,
             double p_longitude, double p_latitude)
  : Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude) { }

  virtual std::string
  reqBorneFormate () const override
  {
    return Borne::reqBorneFormate ();
  }

  virtual Borne*
  clone () const override
  {
    return nullptr;
  }
};

/**
 * \test Test du constructeur de Bornes
 * Cas valides: Creation d'un objet Borne et verification de l'assignation de tous les attributs
 * Cas invalides:
 *      Identitifiant > 0
 *      Direction invalide
 *      Nom Topographique vide
 */

TEST (Borne, ConstructeurAvecParamValide)
{
  BorneTest uneBorne (5432, "Sud", "Boulevard Charest", 22.8632, -13.5321);
  ASSERT_EQ (5432, uneBorne.reqIdentifiant ());
  ASSERT_EQ ("Sud", uneBorne.reqDirection ());
  ASSERT_EQ ("Boulevard Charest", uneBorne.reqNomTopographique ());
  ASSERT_EQ (22.8632, uneBorne.reqLongitude ());
  ASSERT_EQ (-13.5321, uneBorne.reqLatitude ());
}

TEST (Borne, ConstructeurInvalideIdentifiant)
{
  ASSERT_THROW (BorneTest uneBorne (-42, "Sud", "Boulevard Charest", 22.8632, -13.5321), PreconditionException);
}

TEST (Borne, ConstructeurInvalideDirection)
{
  ASSERT_THROW (BorneTest uneBorne (32, "Orange", "Boulevard Charest", 22.8632, -13.5321), PreconditionException);
}

TEST (Borne, ConstructeurInvalideNomTopographique)
{
  ASSERT_THROW (BorneTest uneBorne (32, "Sud", "", 22.8632, -13.5321), PreconditionException);
}

/**
 *\brief Creation d'une fixture a utiliser pour les methodes publiques de la classe de test
 *
 */
class uneBorne : public ::testing::Test
{
public:

  uneBorne () :
  borne (32, "Est", "Boulevard Charest", 22.8632, -13.5321), secondeBorne (32, "Est", "Boulevard Charest", 22.8632, -13.5321),
  troisiemeBorne (24, "Sud", "Boulevard Laurier", 25.3213, -45.2144) { }
  BorneTest borne;
  BorneTest secondeBorne;
  BorneTest troisiemeBorne;

};

/**
 * \test Test de la méthode reqIdentifiant()
 *      Cas valide: verifier le retour de l'identifiant
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqIdentifiant)
{
  ASSERT_EQ (32, borne.reqIdentifiant ());
}

/**
 * \test Test de la méthode reqDirection()
 *      Cas valide: verifier le retour de la direction
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqDirection)
{
  ASSERT_EQ ("Est", borne.reqDirection ());
}

/**
 * \test Test de la méthode reqNomTopographique()
 *      Cas valide: verifier le retour du nom topographique
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqNomTopographique)
{
  ASSERT_EQ ("Boulevard Charest", borne.reqNomTopographique ());
}

/**
 * \test Test de la méthode reqLongitude()
 *      Cas valide: verifier le retour de la longitude
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqLongitude)
{
  ASSERT_EQ (22.8632, borne.reqLongitude ());
}

/**
 * \test Test de la méthode reqLatitude()
 *      Cas valide: verifier le retour de la latitude
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqLatitude)
{
  ASSERT_EQ (-13.5321, borne.reqLatitude ());
}

/**
 * \test Test de la méthode asgNomTopographique()
 *      Cas valide: le nouveau nom topographique est assigné
 *      Cas invalide: nom topographique invalide
 */
TEST_F (uneBorne, asgNomTopographique)
{
  borne.asgNomTopographique ("Boulevard de l'ormière");
  ASSERT_EQ ("Boulevard de l'ormière", borne.reqNomTopographique ());
}

TEST_F (uneBorne, asgNomTopographiqueInvalide)
{
  ASSERT_THROW (borne.asgNomTopographique (""), PreconditionException);

}

/**
 * \test Test de la surchage de l'opérateur ==
 *      Cas valide: les 2 bornes sont égales
 *      Cas invalide: les 2 bornes ne sont pas égales
 */
TEST_F (uneBorne, DeuxBornesEgales)
{
  ASSERT_EQ (true, borne == secondeBorne);
}

TEST_F (uneBorne, DeuxBornesInegales)
{
  ASSERT_EQ (false, borne == troisiemeBorne);
}

/**
 * \test Test de la méthode reqBorneFormate()
 *      Cas valide: verifier le retour de la borne formaté
 *      Cas invalide: aucun
 */
TEST_F (uneBorne, reqBorneFormate)
{
  ASSERT_EQ (
             "Identifiant de la borne    : 32\n"
             "Direction           : Est\n"
             "Nom Topographique   : Boulevard Charest\n"
             "Longitude           : 22.8632\n"
             "Latitude            : -13.5321\n"
             , borne.reqBorneFormate ());
}
