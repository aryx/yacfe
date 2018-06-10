// of course can do foo(); foo();  but most of the time it's 
// a mistake.
// for instance in sparse src I found this:

  sort_list (&l, int_cmp);
  // Sort already sorted stuff.
  sort_list (&l, int_cmp);


//I think it's a bug
