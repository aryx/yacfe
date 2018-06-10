void main()
{
  nsHTMLSelectableAccessible::iterator iter(this, mWeakShell);
  nsAFlatCString::const_iterator startiter(events.BeginReading(start));
  nsHTMLSelectableAccessible::iterator iter(this, mWeakShell);

  const nsDependentSubstring filePath(Substring(value, start, len)); 

//  for (nsCOMPtr<nsIContent> selContent(do_QueryInterface(commonParent)));

    nsCOMPtr<nsIDOMHTMLInputElement>
       element(do_QueryInterface(frame->GetContent()));
  nsCOMPtr<nsIStringBundleService>
     bundleService(do_GetService(NS_STRINGBUNDLE_CONTRACTID, &rv));
    nsCOMPtr<nsILocalFile>
        localDir(do_CreateInstance(NS_LOCAL_FILE_CONTRACTID, &rv));

}
