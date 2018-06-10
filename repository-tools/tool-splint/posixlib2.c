#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifdef S_SPLINT_S
# include "splint-include/arpa/inet.h"
#else
# include <arpa/inet.h>
#endif
//#include <arpa/inet.h>

#include <netdb.h>
#include <strings.h>


/* pad: :) 
/usr/include/arpa/inet.h:35:27: Parse Error. (For help on parse errors, see
               splint -help parseerrors.)

tofix: cf google, need create some fake splint-include/ files

*/
