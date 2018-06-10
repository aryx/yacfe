MaiHyperlink::MaiHyperlink(nsIAccessibleHyperLink *aAcc):
    mHyperlink(aAcc),
    mMaiAtkHyperlink(nsnull)
{
}

MaiHyperlink::~MaiHyperlink()
{
    if (mMaiAtkHyperlink) {
        MAI_ATK_HYPERLINK(mMaiAtkHyperlink)->maiHyperlink = nsnull;
        g_object_unref(mMaiAtkHyperlink);
    }
}
