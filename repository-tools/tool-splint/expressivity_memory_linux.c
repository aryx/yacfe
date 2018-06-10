//pad: can splint satisfy such requirements ? 
//see that path_release for instance is used only in 
//one branch


/**
 * nameidata_to_filp - convert a nameidata to an open filp.
 * @nd: pointer to nameidata
 * @flags: open flags
 *
 * Note that this function destroys the original nameidata
 */
struct file *nameidata_to_filp(struct nameidata *nd, int flags)
{
	struct file *filp;

	/* Pick up the filp from the open intent */
	filp = nd->intent.open.file;
	/* Has the filesystem initialised the file for us? */
	if (filp->f_path.dentry == NULL)
		filp = __dentry_open(nd->dentry, nd->mnt, flags, filp, NULL);
	else
		path_release(nd);
	return filp;
}

//pad: same here, can splint say different things depending if error 
// or not ?


/*
 * dentry_open() will have done dput(dentry) and mntput(mnt) if it returns an
 * error.
 */
struct file *dentry_open(struct dentry *dentry, struct vfsmount *mnt, int flags)
{
	int error;
	struct file *f;

	error = -ENFILE;
	f = get_empty_filp();
	if (f == NULL) {
		dput(dentry);
		mntput(mnt);
		return ERR_PTR(error);
	}

	return __dentry_open(dentry, mnt, flags, f, NULL);
}
EXPORT_SYMBOL(dentry_open);
