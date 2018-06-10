static int ramfs_nommu_check_mappings(struct inode *inode,
				      size_t newsize, size_t size)
{
	struct vm_area_struct *vma;
	struct prio_tree_iter iter;

	/* search for VMAs that fall within the dead zone */
	vma_prio_tree_foreach(vma, &iter, &inode->i_mapping->i_mmap,
			      newsize >> PAGE_SHIFT,
			      (size + PAGE_SIZE - 1) >> PAGE_SHIFT
 			      ) {
		/* found one - only interested if it's shared out of the page
		 * cache */
		if (vma->vm_flags & VM_SHARED)
			return -ETXTBSY; /* not quite true, but near enough */
	}

	return 0;
}
