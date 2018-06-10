#define FTR_GPIO(name, bit)					\
 static void ftr_gpio_set_##name(struct gpio_runtime *rt, int on)\
{								\
	int v;							\
								\
	if (unlikely(!rt)) return;				\
								\
	if (name##_mute_gpio < 0)				\
		return;						\
								\
	v = pmac_call_feature(PMAC_FTR_READ_GPIO, NULL,		\
			      name##_mute_gpio,			\
			      0);				\
								\
	/* muted = !on... */					\
	v = SWITCH_GPIO(name##_mute, v, !on);			\
								\
	pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL,		\
			  name##_mute_gpio, v);			\
								\
	rt->implementation_private &= ~(1<<bit);		\
	rt->implementation_private |= (!!on << bit);		\
}								\
