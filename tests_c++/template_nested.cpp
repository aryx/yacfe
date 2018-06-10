HRESULT CIEHtmlButtonElement::FinalConstruct( )
{
    return CComCreator<CComAggObject<CIEHtmlElement> >::CreateInstance(GetControllingUnknown(),
        IID_IUnknown, reinterpret_cast<void**>(&m_pHtmlElementAgg));
}
