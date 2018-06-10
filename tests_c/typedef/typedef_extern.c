
static int ppc_htab_show(struct seq_file *m, void *v);
static ssize_t ppc_htab_write(struct file * file, const char __user * buffer,
			      size_t count, loff_t *ppos);
extern PTE *Hash, *Hash_end;
