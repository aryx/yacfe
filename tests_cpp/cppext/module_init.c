static void exit_ext2_fs(void)
{
	unregister_filesystem(&ext2_fs_type);
	destroy_inodecache();
	exit_ext2_xattr();
}

module_init(init_ext2_fs)
module_exit(exit_ext2_fs)
