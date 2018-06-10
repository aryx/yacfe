int array[5];

int * BOUND(1, 5) p;
//int * BOUND(array, array+5) p;


void main(void)
{
	p = array + 1; // why refused ?
	
}

// SNT = BOUND(__this, __this)
