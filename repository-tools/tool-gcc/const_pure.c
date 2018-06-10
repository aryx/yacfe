// pad: gcc says nothing :( apparently those annots are for the compiler 
// optimizer, not for the type checker.

int global;

int __attribute__((const))  f (int x)  {

	global++;
	return x * 2;
}

int __attribute__((const))  f2 (int x)  {
	return x * 2;
}


int __attribute__ ((pure)) f3 (int *x)  {
	*x++;
	return *x;
}
