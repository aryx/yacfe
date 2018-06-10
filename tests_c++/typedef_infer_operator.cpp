nsStringArray& 
nsStringArray::operator=(const nsStringArray& other)
{
  // Copy the pointers
  nsVoidArray::operator=(other);

  // Now copy the strings
  for (PRInt32 i = Count() - 1; i >= 0; --i)
  {
    nsString* oldString = NS_STATIC_CAST(nsString*, other.ElementAt(i));
    mImpl->mArray[i] = new nsString(*oldString);
  }

  return *this;
}
