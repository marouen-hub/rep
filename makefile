 # Utilisation de gcc pour compiler les sources.

CC = gcc

  # Le linker 

LD = gcc

  # Les flags du compilateurs.

CFLAGS = -g -Wall


  # rm 

RM = /bin/rm -f

  # La liste des fichiers objet à générer.

OBJS = main.o modules.o

  # Le nom de l'exécutable.

PROG = prog

  

  # Règle de haut niveau pour créer le programme

all: $(PROG)

  

  # Règle pour linker le programme

$(PROG): $(OBJS)

	$(LD) $(OBJS) -o $(PROG)

  

%.o: %.c

	$(CC) $(CFLAGS) -c $<
# Nettoyage.

clean:

	$(RM) $(PROG) $(OBJS)
