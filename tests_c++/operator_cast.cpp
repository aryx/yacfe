Value::operator nsISupports*() const
{
    NS_ASSERTION(mType == eISupports, "not an nsISupports");
    return (mType == eISupports) ? mISupports : 0;
}


Value::operator const PRUnichar*() const
{
    NS_ASSERTION(mType == eString, "not a string");
    return (mType == eString) ? mString : 0;
}
