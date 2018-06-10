typedef struct
{
	unsigned char reserved1[0x38];
	HADDR  hwaddr;
	unsigned char reserved2[0x1c2];
} DMAHWADDR;


static HADDR
*read_hw_addr(int target, unsigned char *buffer)
{
	HADDR *ret = 0;
	unsigned char cmd_buffer[5];

	if (send_first(target, READSECTOR))
		goto bad;
	setup_dma(buffer, READ, 1);
	cmd_buffer[0] = cmd_buffer[1] = cmd_buffer[2] = cmd_buffer[4] = 0;
	cmd_buffer[3] = 1;
	if (send_1_5(5, cmd_buffer, 1) ||
	    !acsi_wait_for_IRQ(TIMEOUTDMA) ||
	    get_status())
		goto bad;
	ret = phys_to_virt((unsigned long)&(((DMAHWADDR *)buffer)->hwaddr));
	dma_cache_maintenance((unsigned long)buffer, 512, 0);
bad:
	return (ret);
}
