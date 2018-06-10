void main()
{
  for (nsCOMPtr<nsIContent> walkUpContent(do_QueryInterface(mDOMNode));
       walkUpContent;
       walkUpContent = walkUpContent->GetParent()) {
    nsIAtom *tag = walkUpContent->Tag();
	}
}
