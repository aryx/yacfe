struct nsHTTPDownloadEvent : PLEvent {
  nsHTTPDownloadEvent();
  ~nsHTTPDownloadEvent();
  
  nsNSSHttpRequestSession *mRequestSession; // no ownership
  
  nsCOMPtr<nsHTTPListener> mListener;
  PRBool mResponsibleForDoneSignal;
};
