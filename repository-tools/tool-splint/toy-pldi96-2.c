
//tofix: add this null
extern /*@null@*/ char *gname; 

// adding the null below force you to add the previous one
void setName (/*@null@*/ char *pname) { 
	gname = pname; 
} 

