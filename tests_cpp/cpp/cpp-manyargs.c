#define FOO(a,b...) a + b

void main(int i)
{
	FOO(1,2,3,4,5);
}
