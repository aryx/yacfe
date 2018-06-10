void main()
{
    for (icaltimetype next = icalrecur_iterator_next(recur_iter);
         !icaltime_is_null_time(next);
         next = icalrecur_iterator_next(recur_iter))
    {
         icaltimetype const dtNext(ensureDateTime(next));
	}
}

