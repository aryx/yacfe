#define devdbg(usbnet, fmt, arg...) \
	printk(KERN_DEBUG "%s: " "\n" , (usbnet)->net.name, arg ## arg)
