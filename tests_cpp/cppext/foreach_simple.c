int dialog_checklist(const char *title, const char *prompt, int height,
		     int width, int list_height)
{
	int i, x, y, box_x, box_y;
	int key = 0, button = 0, choice = 0, scroll = 0, max_choice;
	WINDOW *dialog, *list;

	/* which item to highlight */
	item_foreach() {
		if (item_is_tag('X'))
			choice = item_n();
		if (item_is_selected()) {
			choice = item_n();
			break;
		}
	}

}
