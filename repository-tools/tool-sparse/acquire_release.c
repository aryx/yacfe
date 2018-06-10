/* context annotation */

// cf sparse/validation/context.c, lots of examples showing sparse
// handle control flow as it checks release well on all paths

static void a(void) __attribute__((context(0,1)))
{
	__context__(1);
}

static void r(void) __attribute__((context(1,0)))
{
	__context__(-1);
}


static void good_paired1(void)
{
	a();
	r();
}


static void warn_lock1(void)
{
	a();
}

static void ok_lock1(void) __attribute__((context(0,1)))
{
	a();
}

static void foobis(void) __attribute__((context(1,1)))
{
	// argh, sparse says nothing
	a();
	r();
	return;
}


static void foo(void)
{
	a();
	foobis();
	r();
}

static void foo2(void)
{
	foobis(); // says nothing either :(
}




//int lock = 0;
//
//int __context__(lock,1) get_lock() 
//{
//	lock = 1;
//}
//
//int release_lock() __context__(lock,-1) 
//{
//	lock = 0;
//}
//
//int foo() 
//{
//	get_lock();
//	assume_lock();
//	release_lock();
//}
//	
//
//void assume_lock __attribute__((context(lock,1,1))) () 
//{
//	return;
//}
