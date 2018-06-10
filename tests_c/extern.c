extern int x;

//static int x; // error
// empty // ok, except at linking time
//int x; // ok



int main(void)
{
	return x;
}
