/* splint -help parseerrors

Splint supports some of the GNU (gcc) compiler extensions, if the
+gnuextensions flag is set. 

Missing type definitions --- an undefined type name will usually lead
to a parse error. [...] you may need to either manually define the
problematic type (e.g., add -Dmlink_t=int to your .splintrc file [...]


At last resort, +trytorecover can be used to make Splint attempt to continue
after a parse error.  This is usually not successful and the author does not
consider assertion failures when +trytorecover is used to be bugs.

*/

// ***********************************************************************
// ***********************************************************************

#define __null /*@null@*/

//default?
#define __notnulll /*@notnull@*/


// ***********************************************************************
// ***********************************************************************
#define __only /*@only@*/

//default for param ?
#define __temp /*@temp@*/

//default for globals ?
#define __dependent /*@dependent@*/

#define __owned /*@owned@*/

#define __keep /*@keep@*/

// ***********************************************************************
// ***********************************************************************
#define __unused /*@unused@*/

#define __out /*@out@*/

