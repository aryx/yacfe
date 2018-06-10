#define CS_CHECK(fn, ret) \
  do { last_fn = (fn); if ((last_ret = (ret)) != 0) goto cs_failed; } while (0)

void main(int i)
{

	CS_CHECK(GetFirstTuple, pcmcia_get_first_tuple(link, &tuple));

}
