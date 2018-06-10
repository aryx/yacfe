// = File "/home/pad/kernels/git/linux-2.6/drivers/infiniband/hw/amso1100/c2_provider.h", line 53, column 2,  charpos = 1926

DECLARE_PER_CPU(struct quicklist, quicklist)[CONFIG_NR_QUICK];

struct c2_buf_list {
	void *buf;
 	DECLARE_BITMAP(ctx_bitmap, IOMMU_NUM_CTXS);
	DECLARE_PCI_UNMAP_ADDR(mapping)
 	DECLARE_PCI_UNMAP_LEN(maplen)

};

struct mixer_build {
	struct snd_usb_audio *chip;
	struct usb_mixer_interface *mixer;
	unsigned char *buffer;
	unsigned int buflen;
 	DECLARE_BITMAP(unitbitmap, 256);
	struct usb_audio_term oterm;
	const struct usbmix_name_map *map;
	const struct usbmix_selector_map *selector_map;
};


struct myri10ge_rx_buffer_state {
	struct sk_buff *skb;
 	 DECLARE_PCI_UNMAP_ADDR(bus)
	 DECLARE_PCI_UNMAP_LEN(len)
};

struct myri10ge_rx_buffer_state {
	struct sk_buff *skb;
 	 DECLARE_PCI_UNMAP_ADDR(bus)
	 DECLARE_PCI_UNMAP_LEN(len)
};

