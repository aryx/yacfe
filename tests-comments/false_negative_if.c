

if ( mib->fddiPORTPCMState != oldstate ) {
		/* a real state change took place */
		DB_SNMP ("PCM from %d to %d\n", oldstate, mib->fddiPORTPCMState);
}
