struct reg_info {
	const char	*name;
	struct storage	*contains;
	const unsigned char aliases[12];
#define own_regno aliases[0]
};
