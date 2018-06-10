//don't work if have not info. It does not infer because wierd *&, 
//parsing_hack not used to that
//typedef int PRUint8;

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
