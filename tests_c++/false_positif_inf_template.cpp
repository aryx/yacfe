void
nsAccUtils::SetAccAttrsForXULSelectControlItem(nsIDOMNode *aNode,
                                               nsIPersistentProperties *aAttributes)
{
  nsCOMPtr<nsIDOMXULSelectControlItemElement> item(do_QueryInterface(aNode));
  if (!item)
    return;

  nsCOMPtr<nsIDOMXULSelectControlElement> control;
  item->GetControl(getter_AddRefs(control));
  if (!control)
    return;

  PRUint32 itemsCount = 0;
  control->GetItemCount(&itemsCount);

  PRInt32 indexOf = 0;
  control->GetIndexOfItem(item, &indexOf);

  PRUint32 setSize = itemsCount, posInSet = indexOf;
  for (PRUint32 index = 0; index < itemsCount; index++) {
    nsCOMPtr<nsIDOMXULSelectControlItemElement> currItem;
    control->GetItemAtIndex(index, getter_AddRefs(currItem));
    nsCOMPtr<nsIDOMNode> currNode(do_QueryInterface(currItem));

    nsCOMPtr<nsIAccessible> itemAcc;
    nsAccessNode::GetAccService()->GetAccessibleFor(currNode,
                                                    getter_AddRefs(itemAcc));
    if (!itemAcc ||
        nsAccessible::State(itemAcc) & nsIAccessibleStates::STATE_INVISIBLE) {
      setSize--;
     if (index < static_cast<PRUint32>(indexOf))
        posInSet--;
    }
  }

  SetAccGroupAttrs(aAttributes, 0, posInSet + 1, setSize);
}
