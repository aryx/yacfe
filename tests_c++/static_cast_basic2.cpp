void main()
{
	int i = static_cast<void*>(2);


    char **temp = static_cast<char **>(realloc(mArgs, (mArgsAllocated + kArgsGrowSize) * sizeof(char *)));
}

