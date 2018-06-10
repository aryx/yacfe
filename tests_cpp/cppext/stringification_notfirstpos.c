static int __init usb_mouse_init(void)
{
	int retval = usb_register(&usb_mouse_driver);
	if (retval == 0)
 		info(DRIVER_VERSION ":" DRIVER_DESC);
	return retval;
}

MODULE_AUTHOR(ET61X251_MODULE_AUTHOR " " ET61X251_AUTHOR_EMAIL);


