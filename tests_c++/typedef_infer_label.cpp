PRBool
nsEventListenerManager::HasListenersFor(const nsAString& aEventName)
{
  nsCOMPtr<nsIAtom> atom = do_GetAtom(NS_LITERAL_STRING("on") + aEventName);
  PRUint32 type = nsContentUtils::GetEventId(atom);

  const EventTypeData* typeData = nsnull;
  const EventDispatchData* dispData = nsnull;
  if (type != NS_USER_DEFINED_EVENT) {
    for (PRUint32 i = 0; i < NS_ARRAY_LENGTH(sEventTypes); ++i) {
     typeData = &sEventTypes[i];
     for (PRInt32 j = 0; j < typeData->numEvents; ++j) {
       dispData = &(typeData->events[j]);
       if (type == dispData->message) {
         goto found;
       }
     }
     typeData = nsnull;
     dispData = nsnull;
    }
  }
found:

  PRUint32 count = mListeners.Length();
  for (PRUint32 i = 0; i < count; ++i) {
    nsListenerStruct* ls = &mListeners.ElementAt(i);
    if (ls->mTypeAtom == atom ||
        EVENT_TYPE_DATA_EQUALS(ls->mTypeData, typeData)) {
      return PR_TRUE;
    }
  }
  return PR_FALSE;
}
