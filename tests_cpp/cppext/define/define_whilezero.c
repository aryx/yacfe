#define SET_TIMER							\
 	do {								\
 		mod_timer(&device_timer, jiffies + TIMEOUT_VALUE);	\
 	} while (0)

