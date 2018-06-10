struct xx {
	int x;
	const int y;
};

struct xx a = {
	.x = 1,
	.y = 2, // legal
};

int main(int argc, char **argv)
{
	struct xx a;
	a.x = 1;
	// a.y = 3; // illegal

}
