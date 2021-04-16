/**
 * \file   BorneStationnementTesteur.cpp
 * \brief  Testeur de la classe BorneStationnement
 * \author David Ferland
 * \version 0.1
 * \date 05 avril 2021
 */

#include <stdlib.h>
#include <iostream>
#include <gtest/gtest.h>
#include "BorneStationnement.h"
#include "ContratException.h"

using namespace bornesQuebec;

/**
 * \test Test du constructeur de BorneStationnement
 * Cas valides: Creation d'un objet BorneStationnement et verification de l'assignation de tous les attributs
 * Cas invalides:
 *      Le type de borne n'est pas stationnement ou paiement
 *      La lecture metrique est plus petite ou égale à 0
 *      Le numéro de borne à plus que 4 chiffre ou est négatif
 *      Le coté de la rue est invalide
 */
TEST (BorneStationnement, ConstructeurValide)
{
  BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, 18, 452, "Est");
  ASSERT_EQ (2, uneBorneStationnement.reqIdentifiant ());
  ASSERT_EQ ("Ouest", uneBorneStationnement.reqDirection ());
  ASSERT_EQ ("Rue de la Couronne", uneBorneStationnement.reqNomTopographique ());
  ASSERT_EQ (-72.6537, uneBorneStationnement.reqLongitude ());
  ASSERT_EQ (54.8764, uneBorneStationnement.reqLatitude ());
  ASSERT_EQ ("paiement", uneBorneStationnement.reqType ());
  ASSERT_EQ (42.3, uneBorneStationnement.reqLectureMetrique ());
  ASSERT_EQ (18, uneBorneStationnement.reqSegmentRue ());
  ASSERT_EQ (452, uneBorneStationnement.reqNumBorne ());
  ASSERT_EQ ("Est", uneBorneStationnement.reqCoteRue ());
}

TEST (BorneStationnement, ConstructeurInvalideType)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "Orange", 42.3, 18, 452, "Est"), PreconditionException);
}

TEST (BorneStationnement, ConstructeurInvalideLectureMetrique)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", -42.3, 18, 452, "Est"), PreconditionException);
}

TEST (BorneStationnement, ConstructeurInvalideSegmentRue)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, -18, 452, "Est"), PreconditionException);
}

TEST (BorneStationnement, ConstructeurInvalideNumBorne5Chiffres)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, 18, 43452, "Est"), PreconditionException);
}

TEST (BorneStationnement, ConstructeurInvalideNumBorneNegatif)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, 18, -3452, "Est"), PreconditionException);
}

TEST (BorneStationnement, ConstructeurInvalideCoteRue)
{
  ASSERT_THROW (BorneStationnement uneBorneStationnement (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, 18, 452, "Rouge"), PreconditionException);
}

/**
 *\brief Creation d'une fixture a utiliser pour les methodes publiques de la classe de test
 *
 */
class uneBorneStationnement : public ::testing::Test
{
public:

  uneBorneStationnement () :
  borneStationnementValide (2, "Ouest", "Rue de la Couronne", -72.6537, 54.8764, "paiement", 42.3, 18, 452, "Ouest") { };
  BorneStationnement borneStationnementValide;
};

/**
 * \test Test de la méthode reqType()
 *      Cas valide: verifier le retour du type
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqType)
{
  ASSERT_EQ ("paiement", borneStationnementValide.reqType ());
}

/**
 * \test Test de la méthode reqLectureMetrique()
 *      Cas valide: verifier le retour de la distance mesurée
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqLectureMetrique)
{
  ASSERT_EQ (42.3, borneStationnementValide.reqLectureMetrique ());
}

/**
 * \test Test de la méthode reqSegmentRue()
 *      Cas valide: verifier le retour du segment de la rue
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqSegmentRue)
{
  ASSERT_EQ (18, borneStationnementValide.reqSegmentRue ());
}

/**
 * \test Test de la méthode reqNumBorne()
 *      Cas valide: verifier le retour du numéro de borne
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqNumBorne)
{
  ASSERT_EQ (452, borneStationnementValide.reqNumBorne ());
}

/**
 * \test Test de la méthode reqCoteRue()
 *      Cas valide: verifier le retour du coté de la rue
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqCoteRue)
{
  ASSERT_EQ ("Ouest", borneStationnementValide.reqCoteRue ());
}

/**
 * \test Test de la méthode reqBorneFormate()
 *      Cas valide: verifier le retour de la Borne formatée
 *      Cas invalide: aucun
 */
TEST_F (uneBorneStationnement, reqBorneFormate)
{
  ASSERT_EQ ("Borne de stationnement\n"
             "----------------------------------------------\n"
             "Identifiant de la borne    : 2\n"
             "Direction           : Ouest\n"
             "Nom Topographique   : Rue de la Couronne\n"
             "Longitude           : -72.6537\n"
             "Latitude            : 54.8764\n"
             "Distance mesuree    : 42.3\n"
             "Segment de rue      : 18\n"
             "Numero de la borne  : 452\n"
             "Cote de la rue      : Ouest\n"

             , borneStationnementValide.reqBorneFormate ());
}

/**
 *\test Test de la méthode clone
 *
 */
TEST_F (uneBorneStationnement, cloneBorneStationnement)
{
  ASSERT_EQ (borneStationnementValide.reqBorneFormate (), borneStationnementValide.clone ()->reqBorneFormate ());
  delete borneStationnementValide.clone ();
}