#define LBA_CFG_SETUP(d, tok) {				\
    /* Save contents of error config register.  */			\
    error_config = READ_REG32(d->hba.base_addr + LBA_ERROR_CONFIG);		\
\
    /* Save contents of status control register.  */			\
    status_control = READ_REG32(d->hba.base_addr + LBA_STAT_CTL);		\
\
    /* For LBA rev 2.0, 2.1, 2.2, and 3.0, we must disable DMA		\
    ** arbitration for full bus walks.					\
    */									\
	/* Save contents of arb mask register. */			\
	arb_mask = READ_REG32(d->hba.base_addr + LBA_ARB_MASK);		\
\
	/*								\
	 * Turn off all device arbitration bits (i.e. everything	\
	 * except arbitration enable bit).				\
	 */								\
	WRITE_REG32(0x1, d->hba.base_addr + LBA_ARB_MASK);		\
\
    /*									\
     * Set the smart mode bit so that master aborts don't cause		\
     * LBA to go into PCI fatal mode (required).			\
     */									\
    WRITE_REG32(error_config | LBA_SMART_MODE, d->hba.base_addr + LBA_ERROR_CONFIG);	\
}
