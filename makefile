 # Utilisation de gcc pour compiler les sources.

CC = gcc

  # Le linker 

LD = gcc

  # Les flags du compilateurs.

CFLAGS = -g -Wall


  # rm 

RM = /bin/rm -f

  # La liste des fichiers objet à générer.

OBJS = main.o cpu.o ram.o

  # Le nom de l'exécutable.

PROG = prog

  

  # Règle de haut niveau pour créer le programme

all: $(PROG)

  

  # Règle pour linker le programme

$(PROG): $(OBJS)

	$(LD) $(OBJS) -o $(PROG)

  

  # Règle pour main.o

main.o: main.c cpu.h ram.h

	$(CC) $(CFLAGS) -c main.c

  

  # Règle pour cpu.o .

cpu.o: cpu.c cpu.h

	$(CC) $(CFLAGS) -c cpu.c

  

  # Règle pour ram.o.

ram.o: ram.c ram.h

	$(CC) $(CFLAGS) -c ram.c

  

  # Nettoyage.

clean:

	$(RM) $(PROG) $(OBJS)
