void* nsDequeIterator::operator++() {
  NS_ASSERTION(mIndex<mDeque.mSize,
    "You have reached the end of the Internet."\
    "You have seen everything there is to see. Please go back. Now."
  );
#ifndef TIMELESS_LIGHTWEIGHT
  if (mIndex>=mDeque.mSize) return 0;
#endif
  return mDeque.ObjectAt(++mIndex);
}
