struct net_device *
islpci_setup(struct pci_dev *pdev)
{
	islpci_private *priv;
	struct net_device *ndev = alloc_etherdev(sizeof (islpci_private));

}
