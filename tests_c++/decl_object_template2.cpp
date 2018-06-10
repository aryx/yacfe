NS_METHOD
nsBrowserDirectoryProvider::Register(nsIComponentManager* aCompMgr,
                                     nsIFile* aPath, const char *aLoaderStr,
                                     const char *aType,
                                     const nsModuleComponentInfo *aInfo)
{
  nsresult rv;

  nsCOMPtr<nsICategoryManager> catMan
     (do_GetService(NS_CATEGORYMANAGER_CONTRACTID));
  if (!catMan)
    return NS_ERROR_FAILURE;

  rv = catMan->AddCategoryEntry(XPCOM_DIRECTORY_PROVIDER_CATEGORY,
                                "browser-directory-provider",
                                kContractID, PR_TRUE, PR_TRUE, nsnull);
  return rv;
}
