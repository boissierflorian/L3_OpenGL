

# LINUX
#---------------------------------------------------------------------

# définition des répertoires d'inclusion des bibliothèques .h
INCLUDE= -I /usr/include/GL

# définition des librairies à utiliser lors de l'étape d'édition de liens
LIB=  -lglut -lGLU -lGL  -lm 

# définition du compilateur à utiliser 
CC=gcc

# définition des options de compilation à utiliser
# -g : en vue d'autoriser l'utilisation du débugger
# -Wall : afficher le maximum de messages d'erreurs
OPT= -g -Wall


# définition des cibles de compilation

tp3d:	tp3d.o graphique.o
	$(CC) -o tp3d tp3d.o graphique.o $(OPT)  $(LIB)

tp3d.o:	tp3d.c
	$(CC) -c tp3d.c  $(OPT) $(INCLUDE)

graphique.o:	graphique.c
	$(CC) -c graphique.c  $(OPT) $(INCLUDE)

# cible d'effacement des fichiers objets et de l'exécutable

clean:
	rm -f *.o tp3d

