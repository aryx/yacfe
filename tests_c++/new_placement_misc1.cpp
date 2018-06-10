nsMappedAttributes::nsMappedAttributes(const nsMappedAttributes& aCopy)
  : mAttrCount(aCopy.mAttrCount),
    mSheet(aCopy.mSheet),
    mRuleMapper(aCopy.mRuleMapper)
{
  NS_ASSERTION(mBufferSize >= aCopy.mAttrCount, "can't fit attributes");

  PRUint32 i;
  for (i = 0; i < mAttrCount; ++i) {
     new (&Attrs()[i]) InternalAttr(aCopy.Attrs()[i]);
  }
}
