/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 18 avril 2021, 17:06
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
