void main(int i)
{
	item_foreach() {
		if (item_is_tag('X'))
			choice = item_n();
		if (item_is_selected()) {
			choice = item_n();
			break;
		}
	}

}
