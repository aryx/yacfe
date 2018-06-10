class LinkMapTraversalVisitor : public nsUint32ToContentHashEntry::Visitor
{
public:
  nsCycleCollectionTraversalCallback *mCb;
  virtual void Visit(nsIContent* aContent)
  {
    mCb->NoteXPCOMChild(aContent);
  }
};
