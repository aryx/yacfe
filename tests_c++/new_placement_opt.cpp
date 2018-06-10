morkTable*
morkRowSpace::NewTableWithTid(morkEnv* ev, mork_tid inTid,
  mork_kind inTableKind,
  const mdbOid* inOptionalMetaRowOid) // can be nil to avoid specifying 
{
  morkTable* outTable = 0;
  morkStore* store = mSpace_Store;
  
  if ( inTableKind && store )
  {
    mdb_bool mustBeUnique = morkBool_kFalse;
    nsIMdbHeap* heap = store->mPort_Heap;
    morkTable* table = new(*heap, ev)
      morkTable(ev, morkUsage::kHeap, heap, store, heap, this,
        inOptionalMetaRowOid, inTid, inTableKind, mustBeUnique);

  }                            
}
