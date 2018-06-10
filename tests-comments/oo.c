
void main(int i)
{
	pool->free(element, pool->pool_data);	/* Raced */
	goto out;

}
