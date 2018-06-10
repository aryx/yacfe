// excellent example, show so many mistakes this simple code can entail :)

// pad: apparently current splint does not say anything about this program :(
// default are not good ?

extern char *gname; 

void setName (char *pname) { 
	gname = pname; 
} 
//Figure 1: sample.c
