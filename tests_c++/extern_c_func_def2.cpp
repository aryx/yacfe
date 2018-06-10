extern "C" int
typeinfo_GetMethodData(const char *ifaceName, int methIndex,
                       const nsXPTMethodInfo **info)
{
    nsIInterfaceInfo *iinfo;
    nsresult res;
    *info = 0;

    res = infomgr->GetInfoForName(ifaceName, &iinfo);
    if (NS_FAILED(res))
        return res;

    return iinfo->GetMethodInfo(methIndex, info);
}
