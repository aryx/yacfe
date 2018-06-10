nsMappedAttributes::~nsMappedAttributes()
{
  if (mSheet) {
    mSheet->DropMappedAttributes(this);
  }

  PRUint32 i;
  for (i = 0; i < mAttrCount; ++i) {
     Attrs()[i].~InternalAttr();
  }
}
