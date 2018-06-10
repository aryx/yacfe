void test1(void)
{
	int i;
	for(i = 0; i++; i < 10) {
		printf("cava");
	}
	printf("fini");

}


void test2(void)
{
	int i;
	if(i) { 
		goto end;
	}
	printf("fini");

end:
	return 1;

}

void test3(void)
{
	int i;
back:
	if(i) { 
		goto back;
	}
	printf("fini");

end:
	return 1;

}
