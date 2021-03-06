#ifndef CLAVIER_H
#define CLAVIER_H

////////////////////////////////////////////////////////////
/// Gestion des évènements clavier
///
/// \param touche code ascii de la touche
/// \param x position du curseur
/// \param y position du curseur
////////////////////////////////////////////////////////////
void gestionClavier(unsigned char touche, int x, int y);


////////////////////////////////////////////////////////////
/// Gestion des évènements spéciaux
///
/// \param touche code de la touche
/// \param x position du curseur
/// \param y position du curseur
////////////////////////////////////////////////////////////
void gestionSpecialeClavier(int touche, int x, int y);


#endif
