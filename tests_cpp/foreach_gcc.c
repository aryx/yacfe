static inline bool
bb_has_abnormal_pred (basic_block bb)
{
  edge e;
  edge_iterator ei;

  FOR_EACH_EDGE (e, ei, bb->preds)
    {
      if (e->flags & EDGE_ABNORMAL)
	return true;
    }
  return false;
}
