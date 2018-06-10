nsScriptSecurityManager::nsScriptSecurityManager(void)
    : mOriginToPolicyMap(nsnull),
      mDefaultPolicy(nsnull),
      mCapabilities(nsnull),
      mIsJavaScriptEnabled(PR_FALSE),
      mIsMailJavaScriptEnabled(PR_FALSE),
      mIsWritingPrefs(PR_FALSE),
      mPolicyPrefsChanged(PR_TRUE)
#ifdef XPC_IDISPATCH_SUPPORT
      , mXPCDefaultGrantAll(PR_FALSE)
#endif
{
    NS_ASSERTION(sizeof(long) == sizeof(void*), "long and void* have different lengths on this platform. This may cause a security failure.");
    mPrincipals.Init(31);
}
