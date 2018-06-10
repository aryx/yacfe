nsresult
txHTMLOutput::startDocument()
{
    // XXX Should be using mOutputFormat.getVersion
    *mOut << DOCTYPE_START << "html " << PUBLIC;
    *mOut << " \"-//W3C//DTD HTML 4.0 Transitional//EN\"";
    *mOut << " \"http://www.w3.org/TR/REC-html40/loose.dtd\"";
    *mOut << DOCTYPE_END << endl;

    return NS_OK;
}
