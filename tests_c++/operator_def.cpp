void RCNetAddr::operator=(const RCNetAddr& his) { address = his.address; }


const RCNetAddr* RCHostLookup::operator[](PRUintn which)
{
    RCNetAddr* addr = NULL;
    if (which < max_index)
        addr = &address[which];
    return addr;
}  /* RCHostLookup::operator[] */
