void *
nsTransactionReleaseFunctor::operator()(void *aObject)
{
  nsTransactionItem *item = (nsTransactionItem *)aObject;
  delete item;
  return 0;
}
