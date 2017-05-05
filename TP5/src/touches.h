#ifndef TOUCHES_H
#define TOUCHES_H

// Zoom
extern double transZ;

// Rotation autour des axes Ox et Oy
extern double rotX;
extern double rotY;

//////////////////////////////////////////////////
// \brief Gestion des événements clavier
//
// \param touche la touche appuyée
// \param x
// \param y
//
//////////////////////////////////////////////////
void gererClavier(unsigned char touche, int x, int y);

#endif
