//pad: fake
DEFUN ("make-abbrev-table", Fmake_abbrev_table, Smake_abbrev_table, 0, 0, 0,
       doc: /* Create a new, empty abbrev table object.  */)
     (int x)
{
  /* The value 59 is arbitrary chosen prime number.  */
  return Fmake_vector (make_number (59), make_number (0));
}


DEFUN ("make-abbrev-table", Fmake_abbrev_table, Smake_abbrev_table, 0, 0, 0,
       doc: /* Create a new, empty abbrev table object.  */)
     ()
{
  /* The value 59 is arbitrary chosen prime number.  */
  return Fmake_vector (make_number (59), make_number (0));
}

DEFUN ("clear-abbrev-table", Fclear_abbrev_table, Sclear_abbrev_table, 1, 1, 0,
       doc: /* Undefine all abbrevs in abbrev table TABLE, leaving it empty.  */)
     (table)
     Lisp_Object table;
{
  int i, size;

  CHECK_VECTOR (table);
  size = XVECTOR (table)->size;
  abbrevs_changed = 1;
  for (i = 0; i < size; i++)
    XVECTOR (table)->contents[i] = make_number (0);
  return Qnil;
}
