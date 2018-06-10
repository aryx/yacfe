void afs_break_callbacks(struct afs_server *server, size_t count,
			 struct afs_callback callbacks[])
{
	_enter("%p,%zu,", server, count);

	ASSERT(server != NULL);
 	ASSERTCMP(count, <=, AFSCBMAX);

 	ASSERTCMP(count, <=, AFSCBMAX);
 	ASSERTRANGE(wb->first, <=, index, <=, wb->last);

	for (; count > 0; callbacks++, count--) {
		_debug("- Fid { vl=%08x n=%u u=%u }  CB { v=%u x=%u t=%u }",
		       callbacks->fid.vid,
		       callbacks->fid.vnode,
		       callbacks->fid.unique,
		       callbacks->version,
		       callbacks->expiry,
		       callbacks->type
		       );
		afs_break_one_callback(server, &callbacks->fid);
	}

	_leave("");
	return;
}
