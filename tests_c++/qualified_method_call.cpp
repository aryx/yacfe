void main()
{
     msaaAccessible->accNavigate(NAVDIR_NEXT, varStart, &pvar[*aNumElementsFetched] );
     if (!wasAccessibleFetched)
      msaaAccessible->nsAccessNode::Release(); // this accessible will not be received by the caller


}
