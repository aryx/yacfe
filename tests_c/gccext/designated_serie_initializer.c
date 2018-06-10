
static struct i2c_driver i2c_driver_bt866 = {
 		.cap.max_send_wr = 1, /* FIXME: 0 Seems not to work */
};

static struct i2c_driver i2c_driver_bt866 = {
	.driver.name = BT866_DEVNAME,
	.id = I2C_DRIVERID_BT866,
	.attach_adapter = bt866_attach,
	.detach_client = bt866_detach,
	.command = bt866_command
};


static void pmf_gpio_set_hw_reset(struct gpio_runtime *rt, int on)
{
 	struct pmf_args args = { .count = 1, .u[0].v = !!on };
	int rc;

}
