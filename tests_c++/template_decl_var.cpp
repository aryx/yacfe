//pad: note that this file generates no parsing error :( because I parse
//the template_decl_var as a   a<b>d; expression statement ...

gint
getIndexInParentCB(AtkObject *aAtkObj)
{
    // We don't use nsIAccessible::GetIndexInParent() because
    // for ATK we don't want to include text leaf nodes as children
    nsAccessibleWrap *accWrap = GetAccessibleWrap(aAtkObj);
    if (!accWrap) {
        return -1;
    }

    nsCOMPtr<nsIAccessible> parent;
    accWrap->GetParent(getter_AddRefs(parent));
    if (!parent) {
        return -1; // No parent
    }

}
