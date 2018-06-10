struct AutoCompleteIntermediateResult
{
  AutoCompleteIntermediateResult(const nsString& aUrl, const nsString& aTitle,
                                 PRInt32 aVisitCount, PRInt32 aPriority) :
    url(aUrl), title(aTitle), visitCount(aVisitCount), priority(aPriority) {}
  nsString url;
  nsString title;
  PRInt32 visitCount;
  PRInt32 priority;
};


struct nsNavHistoryExpireRecord {
  nsNavHistoryExpireRecord(mozIStorageStatement* statement);

  PRInt64 visitID;
  PRInt64 pageID;
  PRTime visitDate;
  nsCString uri;
  PRInt64 faviconID;
  PRBool hidden;
  PRBool bookmarked;
  PRBool erased; // set to true if/when the history entry is erased
};
