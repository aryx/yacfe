int  __attribute__ ((warn_unused_result)) too_check_result () {
	return -1;
}

int  __attribute__ ((unused)) possibly_unused () {
	return 0;
}

int  __attribute__ ((used)) possibly_unused_but_still_generate_code () {
	return 0;
}

int  really_unused () {
	return 0;
}


int foo ()
{
	int x = too_check_result(); 
	int y = too_check_result(); 

	int z = possibly_unused(); 
	int w = possibly_unused_but_still_generate_code(); 


	if (x < 0) return -1;
	too_check_result ();
	return y;
}


int main() {
	foo(); // no warning :( no interprocedural analysis, no propagation
	return 0;
}
