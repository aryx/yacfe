struct t1 { int a; };
struct t2 { int a; int b; };


int main(void)
{
	struct t1 *x;
	struct t2 *y = /*(struct t2*)*/ x;
}
