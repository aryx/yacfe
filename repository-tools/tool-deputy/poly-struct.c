struct list { 
	TV(t) data; // TV(T) really means void*
	struct list TP(TV(t)) *next; 
};


// This is how list are defined in linux:
// It use a reverse scheme, the list is embeded in the structure
// so do  struct foo { int x; int y; ... struct list_head list; ... }
// so then no pb of polymorphism but not very elegant and then 
// have to use trick like offsetof or container_of to access the elements
// of the list.
struct list_head {
	struct list_head *next, *prev;
};


struct list TP(int) *int_list; 
struct list TP(float) *float_list;

void main(void) {

	int i = 0; 
	float x = 1;

	// does not even work ...
	int_list->next->data = i; // data has type int
	float_list->next->data = i; // data has type int

}
