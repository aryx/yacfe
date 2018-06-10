/* address_space annotation */

static int __attribute__((address_space(1))) *p1;
static int __attribute__((address_space(2))) *p2;


static int foo(void)
{
	p2 = p1;
	return 0;
}
