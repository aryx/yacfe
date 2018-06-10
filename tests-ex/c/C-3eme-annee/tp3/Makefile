.KEEP_STATE:

CPPFLAGS = -I$(HOME)/C/tp2

BIB  = -lm

CC = gcc

SOURCES = comp.c princ.c

OBJ = $(SOURCES:%.c=%.o)

comp : $$(OBJ)
	$(LINK.c) $(OBJ) $(BIB) -o comp
