static inline struct dn_fib_info *dn_fib_find_info(const struct dn_fib_info *nfi)
{
	for_fib_info() {
		if (fi->fib_nhs != nfi->fib_nhs)
			continue;
		if (nfi->fib_protocol == fi->fib_protocol &&
			nfi->fib_prefsrc == fi->fib_prefsrc &&
			nfi->fib_priority == fi->fib_priority &&
			memcmp(nfi->fib_metrics, fi->fib_metrics, sizeof(fi->fib_metrics)) == 0 &&
			((nfi->fib_flags^fi->fib_flags)&~RTNH_F_DEAD) == 0 &&
			(nfi->fib_nhs == 0 || dn_fib_nh_comp(fi, nfi) == 0))
				return fi;
	} endfor_fib_info();
	return NULL;
}


static int dn_fib_get_nhs(struct dn_fib_info *fi, const struct rtattr *rta, const struct rtmsg *r)
{
	struct rtnexthop *nhp = RTA_DATA(rta);
	int nhlen = RTA_PAYLOAD(rta);

 	change_nexthops(fi) {
		int attrlen = nhlen - sizeof(struct rtnexthop);
		if (attrlen < 0 || (nhlen -= nhp->rtnh_len) < 0)
			return -EINVAL;

		nh->nh_flags  = (r->rtm_flags&~0xFF) | nhp->rtnh_flags;
		nh->nh_oif    = nhp->rtnh_ifindex;
		nh->nh_weight = nhp->rtnh_hops + 1;

		if (attrlen) {
			nh->nh_gw = dn_fib_get_attr16(RTNH_DATA(nhp), attrlen, RTA_GATEWAY);
		}
		nhp = RTNH_NEXT(nhp);
	} endfor_nexthops(fi);

	return 0;
}
