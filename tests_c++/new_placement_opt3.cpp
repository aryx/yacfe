nsIFrame*
NS_NewMathMLForeignFrameWrapper(nsIPresShell* aPresShell, nsStyleContext* aContext)
{
   return new (aPresShell) nsMathMLForeignFrameWrapper(aContext);
}
