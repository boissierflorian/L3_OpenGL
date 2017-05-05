#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

//////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////
#include <glut.h>


//////////////////////////////////////////////////
// Structure d'un point 3D
//////////////////////////////////////////////////
typedef struct point3D {
  float x;
  float y;
  float z;
} point3D;


//////////////////////////////////////////////////
// \brief Gère le redimensionnement de la fenêtre
//
// \param largeur la largeur de la fenêtre
// \param hauteur la hauteur de la fenêtre
//
//////////////////////////////////////////////////
void retailler(GLsizei largeur, GLsizei hauteur);


//////////////////////////////////////////////////
// \brief Fonction d'affichage
//
//////////////////////////////////////////////////
void dessiner();


//////////////////////////////////////////////////
// \brief Fonction d'affichage
//
// \param t Une translation
// \param contour Le contour du polygone
// \param nbsom Le nombre de points présents dans le contour
//
//////////////////////////////////////////////////
void extrude(point3D t, point3D contour[], int nbsom);


//////////////////////////////////////////////////
// \brief Test de la fonction précédente
//
//////////////////////////////////////////////////
void test_extrude();

#endif
