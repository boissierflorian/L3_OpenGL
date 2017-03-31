# définition des dossiers d'inclusion des bibliothèques .h
INCLUDE= -I /usr/include/GL

# définition des librairies à utiliser lors de l'étape de l'édition des liens
LIB= -lglut -lGLU -lGL -lm

# définition du compilateur à utiliser
CC=gcc

# définition des options de compilation à utiliser
# -g : en vue d'autoriser l'utilisation du débugger
# -Wall : afficher le maximum de messages d'erreurs
OPTION= -g -Wall

tp1:	tp1.o graphique.o clavier.o souris.o
	$(CC) -o tp1 tp1.o graphique.o clavier.o souris.o $(LIB)
tp1.o: 	tp1.c
	$(CC) -c tp1.c $(INCLUDE) $(OPTION)
graphique.o:	graphique.c
	$(CC) -c graphique.c $(INCLUDE)
clavier.o:	clavier.c
	$(CC) -c clavier.c $(INCLUDE)
souris.o:	souris.c
	$(CC) -c souris.c $(INCLUDE)

# cible d'effacement des fichiers objets et de l'éxécutable
clean :
	rm -r *.o tp1 *~
