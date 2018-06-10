class DummyThread : public BaseDummyThread {
public:
	DummyThread(nsIThreadManager *aTM) { rc = NS_OK; tm = aTM; }
	NS_METHOD Run() {
		tm->EnterMonitor(tm);
		tm->Wait(tm, (PRUint32)0);
		rc = NS_ERROR_FAILURE; //we shoudn't ever get here
		tm->ExitMonitor(tm);
		return NS_OK; 
	}
};

