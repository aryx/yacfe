#define FOO(a) BAR(a) + 1
#define BAR(a) FOO(a) + 2

void main(int i)
{
	FOO(a)
}
