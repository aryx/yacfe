class nsSVGFEMergeNodeElement : public nsSVGFEMergeNodeElementBase,
                                public nsIDOMSVGFEMergeNodeElement
{
  friend nsresult NS_NewSVGFEMergeNodeElement(nsIContent **aResult,
                                          nsINodeInfo *aNodeInfo);
protected:
  nsSVGFEMergeNodeElement(nsINodeInfo* aNodeInfo)
    : nsSVGFEMergeNodeElementBase(aNodeInfo) {}
  nsresult Init();

public:
  NS_DECLARE_STATIC_IID_ACCESSOR(NS_SVG_FE_MERGE_NODE_CID)

  // interfaces:
  NS_DECL_ISUPPORTS_INHERITED

  NS_DECL_NSIDOMSVGFEMERGENODEELEMENT

  NS_FORWARD_NSIDOMSVGELEMENT(nsSVGFEMergeNodeElementBase::)

  NS_FORWARD_NSIDOMNODE(nsSVGFEMergeNodeElementBase::)
  NS_FORWARD_NSIDOMELEMENT(nsSVGFEMergeNodeElementBase::)

  virtual nsresult Clone(nsINodeInfo *aNodeInfo, nsINode **aResult) const;

  nsIDOMSVGAnimatedString* In1() { return mIn1; }

  //pad: here  
  operator nsISupports*() { return static_cast<nsIContent*>(this); }

protected:
  nsCOMPtr<nsIDOMSVGAnimatedString> mIn1;
};
