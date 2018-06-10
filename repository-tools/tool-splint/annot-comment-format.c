// apparently must be exactly / *@null@* / without extra space otherwise 
// splint does not detect the comment as an annot

//tofix: remove space
extern /*  @null@*/ char *gname; 

void setName (/*@null@*/ char *pname) { 
	gname = pname; 
} 
