

PRStatus RCFileIO::Connect(const RCNetAddr&, const RCInterval&)
{ PR_SetError(PR_INVALID_METHOD_ERROR, 0); return PR_FAILURE; }

PRStatus RCFileIO::Connect(const RCNetAddr*, const RCInterval*)
{ PR_SetError(PR_INVALID_METHOD_ERROR, 0); return PR_FAILURE; }
