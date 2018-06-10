std::set<ObjectCalcer*> getAllChildren( const std::vector<ObjectCalcer*> objs )
{
  std::set<ObjectCalcer*> ret;
  // objects to iterate over...
  std::set<ObjectCalcer*> cur( objs.begin(), objs.end() );
  while( !cur.empty() )
  {
    // contains the objects to iterate over the next time around...
    std::set<ObjectCalcer*> next;
   for( std::set<ObjectCalcer*>::iterator i = cur.begin();
         i != cur.end(); ++i )
    {
      ret.insert( *i );
      std::vector<ObjectCalcer*> children = (*i)->children();
      next.insert( children.begin(), children.end() );
    };
    cur = next;
  };
  return ret;
}
