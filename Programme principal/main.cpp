/**
 * \file   main.cpp
 * \brief  Contient la fonction principale du programme
 * \author David Ferland
 * \version 0.1
 * \date 6 avril 2021, 19:42
 */

#include <cstdlib>
#include "Borne.h"
#include "RegistreBorne.h"
#include <iostream>
#include "BorneFontaine.h"
#include "BorneStationnement.h"


using namespace std;
using namespace bornesQuebec;

/**
 * \fn int main (void)
 * \brief Fonction principale du programme
 *
 * Elle demande les attributs d'un objet BorneFontaine à l'usager et
 * construit un objet BorneFontaine avec ceux-ci. Ensuit, elle demande
 * les attribut d'un objet BorneStationnement et construit un obje borne
 * de stationnement avec ceux-ci. Elle place ces objets dans un objet
 * RegistreBorne et les affichent à la console.
 *
 */
int
main ()
{
  RegistreBorne unNouveauRegistre ("Nouveau");
  cout << unNouveauRegistre.reqNomRegistreBorne () << endl;

  int borneFontaineID;
  do
    {
      cout << "Entrez l'identifiant de la borne fontaine" << endl;
      cin >> borneFontaineID;
    }
  while (borneFontaineID <= 0);

  string borneFontaineDirection;
  do
    {
      cout << "Entrez la direction de la borne fontaine" << endl;
      cin >> borneFontaineDirection;
    }
  while (util::validerPointCardinal (borneFontaineDirection) == false);

  string borneFontaineNomTopo;
  char buffer[256];
  do
    {
      cout << "Entrez le nom topographique de la borne fontaine" << endl;
      cin.ignore ();
      cin.getline (buffer, 255);
      borneFontaineNomTopo = buffer;
    }
  while (borneFontaineNomTopo.empty ());

  double borneFontaineLongitude;
  cout << "Entrez la longitude de la borne fontaine" << endl;
  cin >> borneFontaineLongitude;

  double borneFontaineLatitude;
  cout << "Entrez la latitude de la borne fontaine" << endl;
  cin >> borneFontaineLatitude;

  string borneFontaineVille;
  cout << "Entrez la ville où se trouve la borne fontaine" << endl;
  cin >> borneFontaineVille;

  string borneFontaineArrondissement;
  if (borneFontaineVille == "Québec")
    {
      do
        {
          cout << "Entrez l'arrondissement où se trouve la borne fontaine" << endl;
          cin.ignore ();
          cin.getline (buffer, 255);
          borneFontaineArrondissement = buffer;
        }
      while (borneFontaineArrondissement.empty ());
    }
  else
    {
      cout << "Entrez l'arrondissement où se trouve la borne fontaine" << endl;
      cin.ignore ();
      cin.getline (buffer, 255);
      borneFontaineArrondissement = buffer;
    }

  BorneFontaine borneFontaineValide (borneFontaineID, borneFontaineDirection,
                                     borneFontaineNomTopo, borneFontaineLongitude,
                                     borneFontaineLatitude, borneFontaineVille,
                                     borneFontaineArrondissement);

  unNouveauRegistre.ajouteBorne (borneFontaineValide);

  int borneStationnementID;
  do
    {
      cout << "Entrez l'identifiant de la borne stationnement" << endl;
      cin >> borneStationnementID;
    }
  while (borneStationnementID <= 0);

  string borneStationnementDirection;
  do
    {
      cout << "Entrez la direction de la borne stationnement" << endl;
      cin >> borneStationnementDirection;
    }
  while (util::validerPointCardinal (borneStationnementDirection) == false);

  string borneStationnementNomTopo;
  do
    {
      cout << "Entrez le nom topographique de la borne stationnement" << endl;
      cin.ignore ();
      cin.getline (buffer, 255);
      borneStationnementNomTopo = buffer;
    }
  while (borneStationnementNomTopo.empty ());

  double borneStationnementLongitude;
  cout << "Entrez la longitude de la borne stationnement" << endl;
  cin >> borneStationnementLongitude;

  double borneStationnementLatitude;
  cout << "Entrez la latitude de la borne stationnement" << endl;
  cin >> borneStationnementLatitude;

  string borneStationnementType;
  do
    {
      cout << "Entrez le type de borne de stationnement" << endl;
      cin >> borneStationnementType;
    }
  while ((borneStationnementType != "stationnement") && (borneStationnementType != "paiement"));

  double borneStationnementLectMet;
  do
    {
      cout << "Entrez la lecture metrique de la borne stationnement" << endl;
      cin >> borneStationnementLectMet;
    }
  while (borneStationnementLectMet <= 0);

  int borneStationnementSegmentRue;
  do
    {
      cout << "Entrez le segment de la rue de la borne stationnement" << endl;
      cin >> borneStationnementSegmentRue;
    }
  while (borneStationnementSegmentRue <= 0);

  int borneStationnementNumBorne;
  do
    {
      cout << "Entrez le numéro de la borne de stationnement" << endl;
      cin>>borneStationnementNumBorne;
    }
  while (borneStationnementNumBorne < 0 || borneStationnementNumBorne > 9999);

  string borneStationnementCoteRue;
  do
    {
      cout << "Entrez le coté de la rue de la borne de stationnement" << endl;
      cin >> borneStationnementCoteRue;
    }
  while (util::validerPointCardinal (borneStationnementCoteRue) == false);

  BorneStationnement borneStationnementValide (borneStationnementID, borneStationnementDirection,
                                               borneStationnementNomTopo, borneStationnementLongitude,
                                               borneStationnementLatitude, borneStationnementType,
                                               borneStationnementLectMet, borneStationnementSegmentRue,
                                               borneStationnementNumBorne, borneStationnementCoteRue);

  unNouveauRegistre.ajouteBorne (borneStationnementValide);

  cout << unNouveauRegistre.reqRegistreBorneFormate ();

  return 0;
}

