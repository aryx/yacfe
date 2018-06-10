static LIST_HEAD(hub_event_list);	/* List of hubs needing
servicing */


static void kick_khubd(struct usb_hub *hub)
{
	unsigned long	flags;

	x=3;
	spin_lock_irqsave(&hub_event_lock, flags);
	if (list_empty(&hub->event_list)) {
		list_add_tail(&hub->event_list, &hub_event_list);
		wake_up(&khubd_wait);
	}
	spin_unlock_irqrestore(&hub_event_lock, flags);
}
