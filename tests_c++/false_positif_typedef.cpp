// /home/pad/software-src/system/mozilla/mailnews/mime/src/mimeenc.cpp
ERROR ce fichier parse bien mais si prend tout le fichier origianl alors pb

static MimeEncoderData *
mime_encoder_init (mime_encoding which,
 				   nsresult (*output_fn) (const char *, PRInt32, void *),
				   void *closure)
{
  MimeEncoderData *data = PR_NEW(MimeEncoderData);
  if (!data) return 0;
  memset(data, 0, sizeof(*data));
  data->encoding = which;
  data->write_buffer = output_fn;
  data->closure = closure;
  return data;
}
