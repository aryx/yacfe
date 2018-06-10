int __attribute__((weak)) ipath_enable_wc(struct ipath_devdata *dd)
{
	return -EOPNOTSUPP;
}


static void __attribute__((__unused__))
dbg_qh (const char *label, struct ehci_hcd *ehci, struct ehci_qh *qh)
{
}
