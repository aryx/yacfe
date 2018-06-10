//----------------------------------------------------------------------------------------
NS_IMETHODIMP nsFileSpecImpl::IsFile(PRBool *_retval)
//----------------------------------------------------------------------------------------
{
	TEST_OUT_PTR(_retval)
	*_retval = mFileSpec.IsFile();
	return mFileSpec.Error();
}
