/* if add this (which generate a conflict anyway in grammar), then
   get regression on this file.
 | TypedefIdent TColCol TIdent { mk_e(Ident  (fst $3)) [snd $3] (*TODO*) }
*/

typedef int PRUint8;


static PRUint16
ReadUint16(const PRUint8 *&buf)
{
  PRUint16 x;
#ifdef IS_BIG_ENDIAN
   x = ((PRUint16) buf[1]) | ((PRUint16) buf[0] << 8);
#else
  x = ((PRUint16) buf[0]) | ((PRUint16) buf[1] << 8);
#endif
  buf += sizeof(x);
  return x;
}
