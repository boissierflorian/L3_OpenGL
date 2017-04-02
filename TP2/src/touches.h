#ifndef TOUCHES_H
#define TOUCHES_H

extern double trans_axeZ;
extern double angle_rotY;
extern double angle_rotX;

extern double kx;
extern double ky;
extern double kz;

extern void gerer_clavier(unsigned char touche, int x, int y);
extern void gerer_sclavier(int touche, int x, int y);

#endif
