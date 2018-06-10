CC = CC
can_stubs : cercle.o segment.o point.o carre.o rectangle.o figures.o
	CC fenetre.o cercle.o segment.o point.o carre.o rectangle.o can_stubs.cc can_ui.o figures.o -o can_stubs  -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR4 -L/usr/local/guide/lib -L/usr/openwin/lib -lsocket -lnsl -lguidexv -lguide -lxview -lolgx -lX11 -lintl
 
figures.o : figures.c figures.h
	CC -c figures.c   -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
point.o : point.c point.h
	CC -c point.c   -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
segment.o : segment.c segment.h
	CC -c segment.c -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
rectangle.o : rectangle.c rectangle.h
	CC -c rectangle.c -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
carre.o : carre.c carre.h
	CC -c carre.c    -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
cercle.o : cercle.c cercle.h
	CC -c cercle.c -I/usr/local/guide/include -I/usr/openwin/include -DMAIN -DSVR
 
