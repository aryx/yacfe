static const iw_handler zd_standard_iw_handlers[] = {
 	WX(SIOCGIWNAME)		= iw_get_name,
	WX(SIOCSIWFREQ)		= iw_set_freq,
};



static const u32 zd1211b_al2230_table[][3] = {
 	RF_CHANNEL( 1) = { 0x09efc0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL( 2) = { 0x09efc0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL( 3) = { 0x09e7c0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL( 4) = { 0x09e7c0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL( 5) = { 0x05efc0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL( 6) = { 0x05efc0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL( 7) = { 0x05e7c0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL( 8) = { 0x05e7c0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL( 9) = { 0x0defc0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL(10) = { 0x0defc0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL(11) = { 0x0de7c0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL(12) = { 0x0de7c0, 0x8cccd0, 0xb00000, },
	RF_CHANNEL(13) = { 0x03efc0, 0x8cccc0, 0xb00000, },
	RF_CHANNEL(14) = { 0x03e7c0, 0x866660, 0xb00000, },
};
