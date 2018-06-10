// pkoi pas expandé ?

void main()
{
	gClientState->selfID = ipcMessageCast<ipcmMessageClientID>(msg)->ClientID();
}
