//tofix: ? free(gname) before the affectation ?

extern /*@only@*/ char *gname; 

void setName (/*@temp@*/ char *pname) { 
	gname = pname; 
}
