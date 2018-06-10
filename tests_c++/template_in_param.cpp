static void
MarkOrphans(const nsTArray<nsIFormControl*> aArray)
{
  PRUint32 length = aArray.Length();
  for (PRUint32 i = 0; i < length; ++i) {
    nsCOMPtr<nsINode> node = do_QueryInterface(aArray[i]);
    NS_ASSERTION(node, "Form control must be nsINode");
    node->SetFlags(MAYBE_ORPHAN_FORM_ELEMENT);
  }
}
