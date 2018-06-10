nsresult nsAccessible::AppendFlatStringFromSubtree(nsIContent *aContent, nsAString *aFlatString)
{
  static PRBool isAlreadyHere; // Prevent recursion which can cause infinite loops
  if (isAlreadyHere) {
    return NS_OK;
  }

  isAlreadyHere = PR_TRUE;

  nsCOMPtr<nsIPresShell> shell = GetPresShell();
  NS_ENSURE_TRUE(shell, NS_ERROR_FAILURE);

  nsIFrame *frame = shell->GetPrimaryFrameFor(aContent);
  PRBool isHidden = (!frame || !frame->GetStyleVisibility()->IsVisible());
  nsresult rv = AppendFlatStringFromSubtreeRecurse(aContent, aFlatString,
                                                   isHidden);

  isAlreadyHere = PR_FALSE;

  if (NS_SUCCEEDED(rv) && !aFlatString->IsEmpty()) {
    nsAString::const_iterator start, end;
    aFlatString->BeginReading(start);
    aFlatString->EndReading(end);

    PRInt32 spacesToTruncate = 0;
    while (-- end != start && *end == ' ')
      ++ spacesToTruncate;

    if (spacesToTruncate > 0)
      aFlatString->Truncate(aFlatString->Length() - spacesToTruncate);
  }

  return rv;
}
