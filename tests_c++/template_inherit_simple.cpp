struct ipcCallback : public ipcListNode<ipcCallback>
{
  ipcCallbackFunc  func;
  void            *arg;
};
