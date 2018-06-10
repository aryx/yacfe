// pad: this generated at one point a index out of bound when printing
// error message because the parse error was in ASSERTCMP and
// that find_next_synchro didn't look if the synchro token 
// was part of an expansion of part of the original file. 
// In the former case, then checkpoint2 in parse_c.ml refer to 
// a place in standard.h and so everything get screwed ...

// in fact the bug triggered only when the #endif was badly parsed
// and so get 
// PB: not found closing ifdef in fuzzy parsing
// and then it generates error. "Boule de neige".

void afs_clear_inode(struct inode *inode)
{
	struct afs_permits *permits;
	struct afs_vnode *vnode;

	vnode = AFS_FS_I(inode);

	_enter("{%x:%u.%d} v=%u x=%u t=%u }",
	       vnode->fid.vid,
	       vnode->fid.vnode,
	       vnode->fid.unique,
	       vnode->cb_version,
	       vnode->cb_expiry,
	       vnode->cb_type);

	_debug("CLEAR INODE %p", inode);

	ASSERTCMP(inode->i_ino, ==, vnode->fid.vnode);

	afs_give_up_callback(vnode);

	if (vnode->server) {
		spin_lock(&vnode->server->fs_lock);
		rb_erase(&vnode->server_rb, &vnode->server->fs_vnodes);
		spin_unlock(&vnode->server->fs_lock);
		afs_put_server(vnode->server);
		vnode->server = NULL;
	}

	ASSERT(list_empty(&vnode->writebacks));
	ASSERT(!vnode->cb_promised);

#ifdef AFS_CACHING_SUPPORT
	cachefs_relinquish_cookie(vnode->cache, 0);
	vnode->cache = NULL;
#endif

	mutex_lock(&vnode->permits_lock);
	permits = vnode->permits;
	rcu_assign_pointer(vnode->permits, NULL);
	mutex_unlock(&vnode->permits_lock);
	if (permits)
		call_rcu(&permits->rcu, afs_zap_permits);

	_leave("");
}
