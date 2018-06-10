
static int __attribute__((bitwise)) x;

static void foo(void)
{
	x = x >> 1;

	//x++;
	return;
}


typedef int __attribute__((bitwise))  pm_request_t;

#define PM_SUSPEND ((__attribute__((force)) pm_request_t) 1)
#define PM_RESUME ((__attribute__((force)) pm_request_t) 2)


static void bar(void)
{
	pm_request_t x = PM_SUSPEND;
	x = PM_RESUME;
	x = 2;
	return;
}
