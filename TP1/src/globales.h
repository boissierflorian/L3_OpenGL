#ifndef GLOBALES_H
#define GLOBALES_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include "geometrie.h"

extern GLfloat taillePoint; ///< Sert aussi d'épaisseur de ligne
extern point2D point;       ///< Point saisi à la souris
extern point2D translation; ///< Translation due au clavier
extern point2D point2;      ///< Extrémité du segment

extern float rouge; ///< Niveau de rouge
extern float vert;  ///< Niveau de vert
extern float bleu;  ///< Niveau de bleu

extern int mode_primitive; ///< 1 Point, 2 Segment et 3 Cercle

#endif
