class txAttributeTransaction : public txOutputTransaction
{
public:
    txAttributeTransaction(const nsAString& aName, PRInt32 aNsID,
                           const nsAString& aValue)
        : txOutputTransaction(eAttributeTransaction),
          mName(aName),
          mNsID(aNsID),
          mValue(aValue)
    {
    }
    nsString mName;
    PRInt32 mNsID;
    nsString mValue;
};
