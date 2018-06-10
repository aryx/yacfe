PRBool
txXPathNode::operator==(const txXPathNode& aNode) const
{
    if (mIndex != aNode.mIndex) {
        return PR_FALSE;
    }

    // Hopefully it's ok to access mContent through mDocument.
    return (mDocument == aNode.mDocument);
}
