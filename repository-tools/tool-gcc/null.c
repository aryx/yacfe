#include <stdlib.h>

char* mystrcpy(char *dst, const char *src)
	__attribute((__nonnull__(1,2)));

int main()
{
	char *s1;
	char *s2;
	char *s3 = NULL;

	s1 = malloc(10);
	mystrcpy(s1, s3);
	mystrcpy(s1, s2);
	mystrcpy(s1, NULL); // only one detected

	return 0;
}
