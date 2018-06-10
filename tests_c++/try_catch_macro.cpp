STDMETHODIMP
CAccessibleHyperlink::get_valid(boolean *aValid)
{
//__try {
  try {
  *aValid = false;

  nsCOMPtr<nsIAccessibleHyperLink> acc(do_QueryInterface(this));
  if (!acc)
    return E_FAIL;

  PRBool isValid = PR_FALSE;
  nsresult rv = acc->GetValid(&isValid);
  if (NS_FAILED(rv))
    return GetHRESULT(rv);

  *aValid = isValid;
  return S_OK;

 } 
 catch(nsAccessNodeWrap::FilterA11yExceptions(::GetExceptionCode(), GetExceptionInformation())) { }
 //__except(nsAccessNodeWrap::FilterA11yExceptions(::GetExceptionCode(), GetExceptionInformation())) { }

}
