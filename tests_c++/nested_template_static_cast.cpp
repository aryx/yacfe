PLDHashOperator PR_CALLBACK
BlastFunc(nsAttrHashKey::KeyType aKey, nsIDOMNode *aData, void* aUserArg)
{
  nsCOMPtr<nsIAttribute> *attr =
  static_cast<nsCOMPtr<nsIAttribute>*>(aUserArg);

  *attr = do_QueryInterface(aData);

  NS_ASSERTION(attr->get(),
               "non-nsIAttribute somehow made it into the hashmap?!");

  return PL_DHASH_STOP;
}
