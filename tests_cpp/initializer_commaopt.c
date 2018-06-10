struct _ClientInfo
{
	const char *clientstring;
	guint16 clientid;
	guint16 major;
	guint16 minor;
	guint16 point;
	guint16 build;
	guint32 distrib;
	const char *country; /* two-letter abbrev */
	const char *lang; /* two-letter abbrev */
};

/* Needs to be checked */
#define CLIENTINFO_AIM_3_5_1670 { \
	"AOL Instant Messenger (SM), version 3.5.1670/WIN32", \
	0x0004, \
	0x0003, 0x0005, \
	0x0000, 0x0686, \
	0x0000002a, \
	"us", "en", \
}

/* Needs to be checked */
/* Latest winaim without ssi */
#define CLIENTINFO_AIM_4_1_2010 { \
	"AOL Instant Messenger (SM), version 4.1.2010/WIN32", \
	0x0004, \
	0x0004, 0x0001, \
	0x0000, 0x07da, \
	0x0000004b, \
	"us", "en", \
}
