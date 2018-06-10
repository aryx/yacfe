struct RectListBuilder : public nsLayoutUtils::RectCallback {
  nsPresContext*    mPresContext;
  nsClientRectList* mRectList;
  nsresult          mRV;

  RectListBuilder(nsPresContext* aPresContext, nsClientRectList* aList) 
    : mPresContext(aPresContext), mRectList(aList),
      mRV(NS_OK) {}

  virtual void AddRect(const nsRect& aRect) {
    nsRefPtr<nsClientRect> rect = new nsClientRect();
    if (!rect) {
      mRV = NS_ERROR_OUT_OF_MEMORY;
      return;
    }
    
    SetClientRect(aRect, mPresContext, rect);
    mRectList->Append(rect);
  }
};
