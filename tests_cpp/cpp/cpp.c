#define FOO(a) foomacro(a)

// dynamic scoping ??? fixpoint ?
#define REC BAR

#define BAR barmacro()




void main(int i)
{

	FOO(1);
	FOO  (1);
	FOO  
		(1);
	FOO  /* some comment */ 	(1);
	FOO + (1);
	BAR();
	BAR;
	FOO

	REC
}
