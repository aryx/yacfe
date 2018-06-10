NS_IMPL_ADDREF(nsBookmarksService)

NS_IMETHODIMP_(nsrefcnt)
nsBookmarksService::Release()
{
    // We need a special implementation of Release() because our mInner
    // holds a Circular References back to us.
    NS_PRECONDITION(PRInt32(mRefCnt) > 0, "duplicate release");
    --mRefCnt;
    NS_LOG_RELEASE(this, mRefCnt, "nsBookmarksService");

    if (mInner && mRefCnt == 1) {
        nsIRDFDataSource* tmp = mInner;
        mInner = nsnull;
        NS_IF_RELEASE(tmp);
        return 0;
    }
    else if (mRefCnt == 0) {
        delete this;
        return 0;
    }
    else {
        return mRefCnt;
    }
}
