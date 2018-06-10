
void main()
{

   for (PRUint32 index = 0; index < length; index ++) {
     nsCOMPtr<nsIAccessibleEvent> accessibleEvent(
       do_QueryInterface(mEventsToFire[index]));
   }
}
