nsAccessibleWrap::nsAccessibleWrap(nsIDOMNode* aNode,
                                   nsIWeakReference *aShell)
    : mAtkObject(nsnull)
{

}

void nsAccessibleWrap::ShutdownAtkObject()
{
    if (mAtkObject) {
       if (IS_MAI_OBJECT(mAtkObject)) {
             MAI_ATK_OBJECT(mAtkObject)->accWrap = nsnull;
        }
        SetMaiHyperlink(nsnull);
        g_object_unref(mAtkObject);
        mAtkObject = nsnull;
    }
}
