nsresult
IPC_ResolveClientName(const char *aName, PRUint32 *aClientID)
{
  NS_ENSURE_TRUE(gClientState, NS_ERROR_NOT_INITIALIZED);

  ipcMessage *msg;

  nsresult rv = MakeIPCMRequest(new ipcmMessageQueryClientByName(aName), &msg);
  if (NS_FAILED(rv))
    return rv;

  if (IPCM_GetType(msg) == IPCM_MSG_ACK_CLIENT_ID)
    *aClientID = ipcMessageCast<ipcmMessageClientID>(msg)->ClientID();
  else
  {
    LOG(("unexpected IPCM response: type=%x\n", IPCM_GetType(msg)));
    rv = NS_ERROR_UNEXPECTED;
  }
    
  delete msg;
  return rv;
}
