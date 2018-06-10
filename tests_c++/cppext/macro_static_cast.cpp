nsresult
txStylesheet::addAttributeSet(txAttributeSetItem* aAttributeSetItem)
{
    nsresult rv = NS_OK;
    txInstruction* oldInstr =
        NS_STATIC_CAST(txInstruction*,
                        mAttributeSets.get(aAttributeSetItem->mName));
}

