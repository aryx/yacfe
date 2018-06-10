struct freelQ_ce {
	struct sk_buff *skb;
	DECLARE_PCI_UNMAP_ADDR(dma_addr);
 	DECLARE_PCI_UNMAP_LEN(dma_len);
};
