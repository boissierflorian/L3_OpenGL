#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

extern void dessiner(void);

extern double angle_helice;
extern int helice_active;
extern double angle_roues;
extern int roues_actives;
extern int anim_avion;

void retailler(GLsizei largeur, GLsizei hauteur);
void cylindre(float r, float h, int nb);
void fuselage();
void pale();
void helice();
void roue(float rayonRoue, float rayonPneu, float rayonCone);
void avion();
void animer();

#endif
