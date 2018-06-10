class nsFeedLoadListener : public nsIStreamListener
{
public:
    nsFeedLoadListener(nsBookmarksService *aBMSVC,
                       nsIRDFDataSource *aInnerBMDataSource,
                       nsIURI *aURI,
                       nsIRDFResource *aLivemarkResource)
        : mBMSVC(aBMSVC), mInnerBMDataSource(aInnerBMDataSource),
          mURI(aURI), mResource(aLivemarkResource), mAborted(PR_FALSE)
    {
        NS_IF_ADDREF(mBMSVC);
    }

    virtual ~nsFeedLoadListener() {
        NS_IF_RELEASE(mBMSVC);
    }

    NS_DECL_ISUPPORTS
    NS_DECL_NSISTREAMLISTENER
    NS_DECL_NSIREQUESTOBSERVER

    void Abort () { mAborted = PR_TRUE; }

};
