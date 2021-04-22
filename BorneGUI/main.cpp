/**
 * \file   main.cpp
 * \brief  programme principal
 * \author David Ferland
 * \version 0.1
 * \date 18 avril 2021
 */

#include <QApplication>
#include "MWborneGUI.h"
#include <QtGui>

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  MWborneGUI fenetre;
  fenetre.show ();
  return app.exec ();
}
//commit pour montrer que j'ai reussi a faire fonctionner git