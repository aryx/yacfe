class nsSVGArcConverter
{
public:
  nsSVGArcConverter(float x1, float y1,
                    float x2, float y2,
                    float rx, float ry,
                    float angle,
                    PRBool largeArcFlag,
                    PRBool sweepFlag);
  PRBool GetNextSegment(float *x1, float *y1,
                        float *x2, float *y2,
                        float *x3, float *y3);
protected:
  PRInt32 mNumSegs, mSegIndex;
  float mTheta, mDelta, mT;
  float mSinPhi, mCosPhi;
  float mX1, mY1, mRx, mRy, mCx, mCy;

};
