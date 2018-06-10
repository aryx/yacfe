.KEEP_STATE:

CC = gcc -g


SOURCES = graphe.c gener.c

OBJ = $(SOURCES:%.c=%.o) analyse.o princ.o lexico.o

comp : $$(OBJ)
	pc $(OBJ) $(BIB) -o tp6
