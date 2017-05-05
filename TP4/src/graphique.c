#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

#include "touches.h"
#include "defines.h"

double angle_helice = 0.0;
int helice_active = ON;
double angle_roues = 0.0;
int roues_actives = ON;
int anim_avion = ON;

/** 
 * Fonction permettant de dessiner un cube centré sur l'origine 
 * du repère de de taille dimxdimxdim.
 * @param dim la taille du côté du cube.
 */

static void cube(float dim)
{
  glBegin(GL_QUADS);
  /* face avant rouge */
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-dim/2, -dim/2, dim/2);
  glVertex3f( dim/2, -dim/2, dim/2);
  glVertex3f( dim/2,  dim/2, dim/2);
  glVertex3f(-dim/2,  dim/2, dim/2);

  /* face droite verte */
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(dim/2, -dim/2, dim/2);
  glVertex3f(dim/2, -dim/2, -dim/2);
  glVertex3f(dim/2,  dim/2, -dim/2);
  glVertex3f(dim/2,  dim/2, dim/2);

  /* face gauche jaune */
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(-dim/2, -dim/2, dim/2);
  glVertex3f(-dim/2,  dim/2, dim/2);
  glVertex3f(-dim/2,  dim/2, -dim/2);
  glVertex3f(-dim/2, -dim/2, -dim/2);

  /* face arriere blanche */
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(-dim/2, -dim/2, -dim/2);
  glVertex3f(-dim/2,  dim/2, -dim/2);
  glVertex3f( dim/2,  dim/2, -dim/2);
  glVertex3f( dim/2, -dim/2, -dim/2);

  /* face superieure cyan */
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-dim/2, dim/2, dim/2);
  glVertex3f( dim/2, dim/2, dim/2);
  glVertex3f( dim/2, dim/2, -dim/2);
  glVertex3f(-dim/2, dim/2, -dim/2);

  /* face inferieure magenta */
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(-dim/2, -dim/2, dim/2);
  glVertex3f(-dim/2, -dim/2, -dim/2);
  glVertex3f( dim/2, -dim/2, -dim/2);
  glVertex3f( dim/2, -dim/2, dim/2);

  glEnd();
}


/** 
 * Fonction permettant de dessiner le repère du monde sous 
 * forme d'une croix 3D.
 * @param dim la taille de la ligne représentant un demi-axe.
 */
static void repere(float dim)
{
  glBegin(GL_LINES);
  
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(-dim, 0.0, 0.0);
  glVertex3f( dim, 0.0, 0.0);
  glVertex3f(0.0,-dim, 0.0);
  glVertex3f(0.0, dim, 0.0);
  glVertex3f(0.0, 0.0, -dim);
  glVertex3f(0.0, 0.0,  dim);

  glEnd();
}

/**
 * Fonction gérant le redimensionnement de la fenêtre. 
 */
void retailler(GLsizei largeur, GLsizei hauteur)
{
  if (largeur > hauteur)
    glViewport(largeur / 2 - hauteur / 2, 0, hauteur, hauteur);
  else
    glViewport(0, hauteur / 2 - largeur / 2, largeur, largeur);

  glutPostRedisplay();
}

void sphereFer(GLdouble rayon)
{
  glColor3f(1.0f, 1.0f, 0.0f);
  glutWireSphere(rayon, 50, 50);
}

void cone(GLdouble r, GLdouble h, GLuint t, GLuint q)
{
  glColor3f(0.0f, 0.0f, 1.0f);
  glutSolidCone(r, h, t, q);
}

void cylindre(float r, float h, int nb)
{
  GLUquadric* quadric = gluNewQuadric();

  // Problème de mémoire
  if (quadric == 0) return;  
  gluCylinder(quadric, r, r, h, nb, nb);
}

void fuselage()
{
  glColor3f(0.0f, 1.0f, 0.0f);
  cylindre(0.5, 1.5, 50);
  //glColor3f(0.1f, 0.5f, 0.0f);
  glRotatef(-180, 0, 1, 0);
  glutSolidCone(0.5, 0.5f, 50, 50);
  glTranslatef(0, 0, -1.5);
  glutSolidSphere(0.5, 50, 50);
}

/**
 * Crée une pale de l'hélice
 */
void pale()
{
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 0);
  glVertex2f(-0.1, 0.2);
  glVertex2f(0, 0.4);
  glVertex2f(0.1, 0.2);
  glEnd();
}

void helice()
{
  // Le cône
  glColor3f(0, 0, 0);
  glPushMatrix();
  glTranslatef(0, 0, -0.5);
  glRotatef(180, 0, 1, 0);
  glutSolidCone(0.2f, 0.2f, 50, 50);
  
  // Les hélices
  glTranslatef(0, 0, 0.2);
  glRotatef(angle_helice, 0, 0, 1);
  pale();
  glRotatef(180, 0, 0, 1);
  pale();
  glPopMatrix();
}

void roue(float rayonRoue, float rayonPneu, float rayonCone)
{
  if (rayonCone > rayonPneu) rayonCone = rayonPneu;

  glColor3f(1, 0, 0);
  glutSolidTorus(rayonPneu, rayonRoue, 50, 50);
  glColor3f(0, 0, 1);
  glPushMatrix();
  glRotatef(90, 1, 0, 0);
  glutSolidCone(rayonCone, rayonRoue, 50, 50);

  int i;
  for(i = 1; i < 4; i++)
  {
    glRotatef(90 * i, 0, 1, 0);
    glutSolidCone(rayonCone, rayonRoue, 50, 50);
  }
  
  glPopMatrix();
}

void intersections()
{
  glPushMatrix();
  glColor3f(1, 1, 0);
  glRotatef(90, 0, 1, 0);
  glTranslatef(-0.8, -0.2, 0.4);
  cylindre(0.1, 0.3, 50);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 0);
  glRotatef(-90, 0, 1, 0);
  glTranslatef(0.8, -0.2, 0.4);
  cylindre(0.1, 0.3, 50);
  glPopMatrix();
}

void roues()
{
  
  glPushMatrix();
  glRotatef(90, 0, 1, 0);
  glTranslatef(-0.8, -0.2, -0.7);
  glRotatef(angle_roues, 0, 0, 1);
  roue(0.3, 0.1, 0.1);
  glPopMatrix();

  glPushMatrix();
  glRotatef(90, 0, 1, 0);
  glTranslatef(-0.8, -0.2, 0.7);
  glRotatef(angle_roues, 0, 0, 1);
  roue(0.3, 0.1, 0.1);
  glPopMatrix();
}

void ailes()
{
  glColor3f(0, 1, 1);
  glPushMatrix();
  glScalef(1, 0.05, 0.3);
  glTranslatef(-1.0, 5, 1);
  glutSolidSphere(1, 50, 10);
  glPopMatrix();

  glPushMatrix();
  glScalef(1, 0.05, 0.3);
  glTranslatef(1.0, 5, 1);
  glutSolidSphere(1, 50, 10);
  glPopMatrix();
}

void avion()
{
  fuselage();
  helice();
  intersections();
  roues();
  ailes();
}

/**
 * Fonction utilisée pour afficher le monde 3D à visualiser. Cette fonction
 * sera appelée à chaque fois qu'un "rafraichissement" de la fenêtre
 * d'affichage sera nécessaire.
 */
void dessiner(void)
{
  /* effacer l'ecran */
  glClearColor(1.0, 1.0, 1.0, 1.0);
  
  /* raz de la fenetre avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* translation du repère de 5 unités sur l'axe Z */
  /* suivi d'une rotation de 20 degrés autour de l'axe Y */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(0.0, 0.0, -5.f);
  glRotatef(20.0, 0.0, 1.0, 0.0);
  glTranslatef(0.0, 0.0, trans_axeZ);
  glRotatef(angle_rotY, 0.0, 1.0, 0.0);
  glRotatef(angle_rotX, 1.0, 0.0, 0.0);
  glScalef(kx, ky, kz);
  
  /* dessin des objets */
  glColor3f(1.0f, 0.0f, 0.0f);
  repere(2.0);
  avion();
  glPopMatrix();
  glFlush();
  glutSwapBuffers(); 
}

void animer()
{
  if (helice_active == ON) angle_helice = (int) (angle_helice + 1) % 360;
  if (roues_actives == ON) angle_roues = (int) (angle_roues + 1) % 360;
  
  if (helice_active == ON || roues_actives == ON) dessiner();
}
