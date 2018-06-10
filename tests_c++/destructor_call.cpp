PR_STATIC_CALLBACK(void)
CompareCacheClearEntry(PLDHashTable *table, PLDHashEntryHdr *hdr)
{
  CompareCacheHashEntryPtr *entryPtr = NS_STATIC_CAST(CompareCacheHashEntryPtr*, hdr);
   entryPtr->~CompareCacheHashEntryPtr();
}


void
nsChromeRegistry::ClearEntry(PLDHashTable *table, PLDHashEntryHdr *entry)
{
  PackageEntry* pentry = NS_STATIC_CAST(PackageEntry*, entry);
  pentry->~PackageEntry();

  mork_usage usage = mNode_Usage; // mNode_Usage before ~morkNode
      this->morkNode::~morkNode(); // first call polymorphic destructor

}
