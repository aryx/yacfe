
typedef int (*pointer_func_t)(int);

static int (*pointer_func)(int);

pointer_func_t x2;

pointer_func_t foo(void)
{
	return x2;
}

int main(int i) { 
	foo(2)(2);
}

