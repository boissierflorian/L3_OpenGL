#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>

/** 
 * Fonction permettant de dessiner un cube centr� sur l'origine 
 * du rep�re de de taille dimxdimxdim.
 * @param dim la taille du c�t� du cube.
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
 * Fonction permettant de dessiner le rep�re du monde sous 
 * forme d'une croix 3D.
 * @param dim la taille de la ligne repr�sentant un demi-axe.
 */
static void repere(float dim)
{
  glBegin(GL_LINES);
  
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(-dim, 0.0, 0.0);
  glVertex3f( dim, 0.0, 0.0);
  glVertex3f(0.0,-dim, 0.0);
  glVertex3f(0.0, dim, 0.0);
  glVertex3f(0.0, 0.0, -dim);
  glVertex3f(0.0, 0.0,  dim);

  glEnd();
}

/**
 * Fonction g�rant le redimensionnement de la fen�tre. 
 */
void retailler(GLsizei largeur, GLsizei hauteur)
{
  if (largeur > hauteur)
    glViewport(largeur / 2 - hauteur / 2, 0, hauteur, hauteur);
  else
    glViewport(0, hauteur / 2 - largeur / 2, largeur, largeur);

  glutPostRedisplay();
}

/**
 * Fonction utilis�e pour afficher le monde 3D � visualiser. Cette fonction
 * sera appel�e � chaque fois qu'un "rafraichissement" de la fen�tre
 * d'affichage sera n�cessaire.
 */

void dessiner(void)
{
  /* effacer l'ecran */
  glClearColor(0.0, 0.0, 0.0, 1.0);

  /* raz de la fenetre avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* translation du rep�re de 5 unit�s sur l'axe Z */
  /* suivi d'une rotation de 20 degr�s autour de l'axe Y */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.f);
  glRotatef(20.0, 0.0, 1.0, 0.0);

  /* dessin des objets */
  cube(2.0);  
  repere(2.0);
  
  glFlush();
}
