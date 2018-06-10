void nsFileSpec::operator = (const nsFilePath& inPath)
//----------------------------------------------------------------------------------------
{
    mPath = (const char*)inPath;
    mError = NS_OK;
}
