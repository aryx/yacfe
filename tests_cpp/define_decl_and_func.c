#define BLOCKING 1024

#define DEFINE_ALLOCATOR(name, type)				\
static unsigned int name##_allocs;				\
void *alloc_##name##_node(void)					\
{								\
	static int nr;						\
	static type *block;					\
	void *ret;						\
								\
	if (!nr) {						\
		nr = BLOCKING;					\
		block = xmalloc(BLOCKING * sizeof(type));	\
	}							\
	nr--;							\
	name##_allocs++;					\
	ret = block++;						\
	memset(ret, 0, sizeof(type));				\
	return ret;						\
}


void main()
{
}
