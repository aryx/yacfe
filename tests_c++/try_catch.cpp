int CBrowseApp::Run() 
{
    int rv = 1;
    try {
        rv = CWinApp::Run();
    }
    catch (CException *e)
    {
        ASSERT(0);
    }
    catch (...)
    {
        ASSERT(0);
    }
    return rv;
}
