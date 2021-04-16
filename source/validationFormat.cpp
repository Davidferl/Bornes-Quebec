
/**
 * \file   validationFormat.cpp
 * \brief  Code source qui valide les informations sur une borne
 * \author David Ferland
 * \date   15 février 2021
 */


#include <iostream>
#include <sstream>
#include <algorithm>
#include "validationFormat.h"

using namespace std;

bool
util::valideLigneCVS (const string& p_ligne, ostringstream& p_parametres)
{
  bool verif = true;
  istringstream ss (p_ligne);
  string info;
  string tabInfo[9] = {""};
  int nbmot = 0;
  while (getline (ss, info, '|'))
    {
      tabInfo[nbmot] = info;
      nbmot++;
    }
  if (nbmot != 9)
    {
      verif = false;
    }

  if (tabInfo[0].empty ())
    {
      verif = false;
    }

  for (int i = 0; i < nbmot; i++)
    {
      if (i == 8)
        {
          p_parametres << tabInfo[i];
        }
      else
        {
          p_parametres << tabInfo[i] << ",";
        }
    }
  return verif;
}

bool
util::validerGeom (const string& p_geom)
{
  istringstream is (p_geom);
  int compteur = 0;


  string point;
  is >> point;
  if (point == "POINT")
    {
      compteur++;
    }

  string longitude;
  is >> longitude;
  if (longitude.find ('(') != string::npos)
    {
      compteur++;
    }

  string latitude;
  is >> latitude;

  if (latitude.find (')') != string::npos)
    {
      compteur++;
    }

  longitude.erase (longitude.begin ());
  latitude.erase (prev (latitude.end ()));

  double longitudeCheck = convertirChaineEnDouble (longitude);
  double latitudeCheck = convertirChaineEnDouble (latitude);
  if (to_string (longitudeCheck).length () == 9)
    {
      compteur++;
    }

  if (to_string (latitudeCheck).length () == 9)
    {
      compteur++;
    }

  bool verif = false;

  if (compteur == 5)
    {
      verif = true;
    }

  return verif;
}

double
util::convertirChaineEnDouble (const string& p_chaine)
{
  string chaineFormate = p_chaine;
  //on remplace la , en .
  for (unsigned int i = 0; i < chaineFormate.length (); i++)
    {
      if (chaineFormate[i] == ',')
        {
          chaineFormate[i] = '.';
        }
    }
  istringstream is (chaineFormate);
  double chaineConvertiEnDouble;
  is >> chaineConvertiEnDouble;
  return chaineConvertiEnDouble;
}

bool
util::valideStationnementGEOJSON (const string& p_enregistrement, ostringstream& p_attributs)
{

  istringstream is (p_enregistrement);

  string info;
  string tabInfo[20] = {""};
  string tabSortie [8] = {""};
  int nbmot = 0;
  while (getline (is, info, ':'))
    {
      tabInfo[nbmot] = info;
      nbmot++;
    }

  istringstream s0 (tabInfo[6]);

  string id;
  s0 >> id;
  id.erase (remove (id.begin (), id.end (), '"'), id.end ());
  tabSortie[0] = id;

  istringstream s1 (tabInfo[7]);

  string cote_rue;
  s1 >> cote_rue;
  cote_rue.erase (remove (cote_rue.begin (), cote_rue.end (), '"'), cote_rue.end ());
  tabSortie[1] = cote_rue;

  istringstream s2 (tabInfo[8]);

  string lect_me;
  s2 >> lect_me;
  lect_me.erase (remove (lect_me.begin (), lect_me.end (), '"'), lect_me.end ());
  tabSortie[2] = lect_me;

  istringstream s3 (tabInfo[9]);

  string segment_ru;
  s3 >> segment_ru;
  segment_ru.erase (remove (segment_ru.begin (), segment_ru.end (), '"'), segment_ru.end ());
  tabSortie[3] = segment_ru;

  istringstream s4 (tabInfo[10]);

  string direction;
  s4 >> direction;
  direction.erase (remove (direction.begin (), direction.end (), '"'), direction.end ());
  tabSortie[4] = direction;

  istringstream s5 (tabInfo[11]);

  string nom_topog1;
  s5 >> nom_topog1;

  string nom_topog2;
  s5 >> nom_topog2;

  string nom_topog = nom_topog1 + " " + nom_topog2;
  nom_topog.erase (remove (nom_topog.begin (), nom_topog.end (), '"'), nom_topog.end ());
  tabSortie[5] = nom_topog;

  istringstream s6 (tabInfo[12]);

  string no_borne;
  s6 >> no_borne;
  no_borne.erase (remove (no_borne.begin (), no_borne.end (), '"'), no_borne.end ());
  tabSortie[6] = no_borne;

  istringstream s8 (tabInfo[15]);


  string geom;
  s8.ignore ();
  char buffer[256];
  s8.getline (buffer, 256);
  geom = buffer;
  geom.erase (remove (geom.begin (), geom.end (), '"'), geom.end ());
  geom.pop_back ();
  tabSortie[7] = geom;

  for (int i = 0; i < 8; i++)
    {

      p_attributs << tabSortie[i];

    }

  return true;
}

bool
util::validerPointCardinal (const string& p_cardinalite)
{
  if (p_cardinalite.empty () || p_cardinalite == "Nord" || p_cardinalite == "Est" || p_cardinalite == "Sud" || p_cardinalite == "Ouest")
    return true;
  else
    return false;
}


