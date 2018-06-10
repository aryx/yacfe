void MidFree(void *address) throw()
{
  #ifdef _SZ_ALLOC_DEBUG
  if (address != 0)
    fprintf(stderr, "\nFree_Mid; count = %10d", --g_allocCountMid);
  #endif
  if (address == 0)
    return;
  ::VirtualFree(address, 0, MEM_RELEASE);
}
