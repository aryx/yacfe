nsLDAPMessage::~nsLDAPMessage(void)
{
    if (mMsgHandle) {
        int rc = ldap_msgfree(mMsgHandle);

	}
}


nsGIFDecoder2::~nsGIFDecoder2(void)
{
  Close();
}

