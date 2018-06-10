nsresult
nsImageLoadingContent::FireEvent(const nsAString& aEventType)
{
  nsCOMPtr<nsIRunnable> evt =
      new nsImageLoadingContent::Event(presContext, this, aEventType, document);
}

