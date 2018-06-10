static ctl_table arlan_conf_table2[] =
{

	ARLAN_SYSCTL_TABLE_TOTAL(2)

#ifdef ARLAN_PROC_SHM_DUMP
 	{
		.ctl_name	= 150,
		.procname	= "arlan2-txRing",
		.data		= &arlan_drive_info,
		.maxlen		= ARLAN_STR_SIZE,
		.mode		= 0400,
		.proc_handler	= &arlan_sysctl_infotxRing,
	},
#endif
};
