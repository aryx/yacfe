class BookmarkContentSink : public nsIHTMLContentSink
{
public:
  BookmarkContentSink();

  nsresult Init(PRBool aAllowRootChanges,
                nsINavBookmarksService* bookmarkService,
                PRInt64 aFolder,
                PRBool aIsImportDefaults);

};
