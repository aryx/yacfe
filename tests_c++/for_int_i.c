NS_IMETHODIMP
nsFontEnumeratorBeOS::HaveFontFor(const char* aLangGroup, PRBool* aResult)
{
  NS_ENSURE_ARG_POINTER(aLangGroup); 
  NS_ENSURE_ARG_POINTER(aResult); 
  *aResult = PR_FALSE;

  int32 numFamilies = count_font_families(); 

  for(int i = 0; i < numFamilies; i++) 
  {
    font_family family; 
    uint32 flags; 
    if (get_font_family(i, &family, &flags) == B_OK) 
    {
      if (family && (!aLangGroup || MatchesLangGroup(family,  aLangGroup)))
      {
         *aResult = PR_TRUE;
         return NS_OK;
         
      }
    }
  }
  return NS_OK;
}
