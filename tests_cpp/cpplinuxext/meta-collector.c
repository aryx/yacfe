META_COLLECTOR(int_protocol)
{
	/* Let userspace take care of the byte ordering */
	dst->value = skb->protocol;
}
