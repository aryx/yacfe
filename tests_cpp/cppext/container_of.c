static struct o2nm_cluster *to_o2nm_cluster(struct config_item *item)
{
	return item ?
 		container_of(to_config_group(item), struct o2nm_cluster,
			     cl_group)
		: NULL;
}
