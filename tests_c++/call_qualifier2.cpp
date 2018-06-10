gint
getChildCountCB(AtkObject *aAtkObj)
{
    nsAccessibleWrap *accWrap = GetAccessibleWrap(aAtkObj);
    if (!accWrap || nsAccessibleWrap::MustPrune(accWrap)) {
        return 0;
    }

    PRInt32 count = 0;
    nsCOMPtr<nsIAccessibleHyperText> hyperText;
    accWrap->QueryInterface(NS_GET_IID(nsIAccessibleHyperText), getter_AddRefs(hyperText));
    if (hyperText) {
        // If HyperText, then number of links matches number of children
        hyperText->GetLinkCount(&count);
    }
    else {
        nsCOMPtr<nsIAccessibleText> accText;
        accWrap->QueryInterface(NS_GET_IID(nsIAccessibleText), getter_AddRefs(accText));
        if (!accText) {    // Accessible text that is not a HyperText has no children
            accWrap->GetChildCount(&count);
        }
    }
    return count;
}
