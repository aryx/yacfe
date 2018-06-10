const txXPathNode& txForwardContext::getContextNode()
{
    return mContextNode;
}

const txXPathNode& txNodeSetContext::getContextNode()
{
    return mContextSet->get(mPosition - 1);
}
