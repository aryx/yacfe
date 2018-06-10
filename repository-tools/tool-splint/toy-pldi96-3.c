extern char *gname; 

//pad: truenull is now called nullwhentrue  in recent splint
// and the return value must be bool (in pldi paper the return
// type was ommitted)

// without the nullwhentrue, then splint does not know that isNull(x)
// is really a disguesd if(x == NULL) and so will report a false
// positive.

extern /*@nullwhentrue@*/ bool isNull (/*@null@*/ char *x); 


void setName (/*@null@*/ char *pname) { 
	if (!isNull (pname)) { 
		gname = pname; 
	} 
}
