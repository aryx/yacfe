// also the = 0, cos pure method ?

static int
MimeEncrypted_parse_begin (MimeObject *obj)
{
  MimeEncrypted *enc = (MimeEncrypted *) obj;
  MimeDecoderData *(*fn) (nsresult (*) (const char*, PRInt32, void*), void*) = 0;
}
