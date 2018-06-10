// when just this file then no pb but if use whole file then pb, wierd

// = File "/home/pad/software-src/devel/git-git/builtin-for-each-ref.c", line 675, column 19,  charpos = 16716

static int cmp_ref_sort(struct ref_sort *s, struct refinfo *a, struct refinfo *b)
{
	struct atom_value *va, *vb;
	int cmp;
 	cmp_type cmp_type = used_atom_type[s->atom]; // pad: pb

	get_value(a, s->atom, &va);
	get_value(b, s->atom, &vb);
	switch (cmp_type) {
	case FIELD_STR:
		cmp = strcmp(va->s, vb->s);
		break;
	default:
		if (va->ul < vb->ul)
			cmp = -1;
		else if (va->ul == vb->ul)
			cmp = 0;
		else
			cmp = 1;
		break;
	}
	return (s->reverse) ? -cmp : cmp;
}
