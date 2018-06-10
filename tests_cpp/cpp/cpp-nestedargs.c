#define FOO(a,b) fn(a,b)

void main(int i)
{
	FOO(f(0), f(1,2));
}
