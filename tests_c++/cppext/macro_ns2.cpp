MOZCE_SHUNT_API void mozce_assert(int inExpression)
{
    MOZCE_PRECHECK

#ifdef DEBUG
    mozce_printf("mozce_assert called\n");
#endif

    if(0 == inExpression)
    {
        DebugBreak();
    }
}

MOZCE_SHUNT_API HRESULT mozce_OleSetClipboard(IDataObject * pDataObj);
