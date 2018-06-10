class PluginWindowEvent : public PLEvent {
public:
  PluginWindowEvent();
  void Init(HWND hWnd, ULONG msg, MPARAM mp1, MPARAM mp2);
  void Clear();
  HWND   GetWnd()    { return mWnd; };
  ULONG   GetMsg()    { return mMsg; };
  MPARAM GetWParam() { return mWParam; };
  MPARAM GetLParam() { return mLParam; };
  PRBool GetIsAlloced() { return mIsAlloced; };
  void   SetIsAlloced(PRBool aIsAlloced) { mIsAlloced = aIsAlloced; };
  PRBool InUse() { return (mWnd!=NULL || mMsg!=0); };

protected:
  HWND   mWnd;
  ULONG  mMsg;
  MPARAM mWParam;
  MPARAM mLParam;
  PRBool mIsAlloced;
};
