void
nsPermissionManager::RemoveTypeStrings()
{
  for (PRUint32 i = NUMBER_OF_TYPES; i--; ) {
    if (mTypeArray[i]) {
      PL_strfree(mTypeArray[i]);
      mTypeArray[i] = nsnull;
    }
  }
}
