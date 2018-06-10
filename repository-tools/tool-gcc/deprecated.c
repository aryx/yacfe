
int __attribute__ ((deprecated)) old_var;

int __attribute__ ((deprecated)) old_fn()
{
	return 0;
}

struct x {
	int __attribute__ ((deprecated)) oldfield;
	int newfield;
};



int foo()
{
	return old_fn();
}

int bar()
{
	return old_var;
}

int foobar()
{
	struct x w;
	w.oldfield = 1;
	w.newfield = 2;
	return 0;
}
