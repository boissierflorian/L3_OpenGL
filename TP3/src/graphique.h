#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

extern void dessiner(void);

void retailler(GLsizei largeur, GLsizei hauteur);
void cylindre(float r, float h, int nb);
void fuselage();
void pale();
void helice();
void roue(float rayonRoue, float rayonPneu, float rayonCone);
void avion();

#endif
