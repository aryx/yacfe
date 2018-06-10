//static
PRBool
txNodeSorter::calcSortValue(TxObject*& aSortValue, SortKey* aKey,
                            SortData* aSortData, PRUint32 aNodeIndex)
{
    aSortData->mContext->setPosition(aNodeIndex + 1); // position is 1-based

    nsresult rv = aKey->mComparator->createSortableValue(aKey->mExpr,
                                                         aSortData->mContext,
                                                         aSortValue);
    if (NS_FAILED(rv)) {
        aSortData->mRv = rv;
        return PR_FALSE;
    }

    return PR_TRUE;
}
