NS_IMETHODIMP nsNntpUrl::GetFolder(nsIMsgFolder **msgFolder)
{
   nsresult rv;

   if (mOriginalSpec.IsEmpty()) {
    // this could be a autosubscribe url (news://host/group)
    // or a message id url (news://host/message-id)
    // either way, we won't have a msgFolder for you
    return NS_ERROR_FAILURE;
   }

   nsCOMPtr <nsINntpService> nntpService = do_GetService(NS_NNTPSERVICE_CONTRACTID, &rv);
   NS_ENSURE_SUCCESS(rv,rv);

}
