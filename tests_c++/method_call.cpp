nsresult
BookmarkParser::ParseResource(nsIRDFResource *arc, nsString& url, nsIRDFNode** aResult)
{
    *aResult = nsnull;

    if (arc == kNC_URL)
    {
        // Now do properly replace %22's; this is particularly important for javascript: URLs
        static const char kEscape22[] = "%22";
        PRInt32 offset;
        while ((offset = url.Find(kEscape22)) >= 0)
        {
            url.SetCharAt('\"',offset);
            url.Cut(offset + 1, sizeof(kEscape22) - 2);
        }

        // XXX At this point, the URL may be relative. 4.5 called into
        // netlib to make an absolute URL, and there was some magic
        // "relative_URL" parameter that got sent down as well. We punt on
        // that stuff.

        // hack fix for bug # 21175:
        // if we don't have a protocol scheme, add "http://" as a default scheme
        if (url.FindChar(PRUnichar(':')) < 0)
        {
            url.Assign(NS_LITERAL_STRING("http://") + url);
        }
    }

    nsresult                    rv;
    nsCOMPtr<nsIRDFResource>    result;
    rv = gRDF->GetUnicodeResource(url, getter_AddRefs(result));
    if (NS_FAILED(rv)) return rv;
    return result->QueryInterface(NS_GET_IID(nsIRDFNode), (void**) aResult);
}
