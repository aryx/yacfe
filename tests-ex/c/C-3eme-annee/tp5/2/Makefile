.KEEP_STATES:

princ: liste.o princ.o service.o
	gcc -o princ -g liste.o princ.o service.o

liste.o: liste.c
	gcc -c -g liste.c -o liste.o

service.o: service.c
	gcc -c -g service.c -o service.o

princ.o: princ.c
	gcc -c -g princ.c