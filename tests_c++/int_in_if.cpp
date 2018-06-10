void main()
{
	if ( int failures = test_readable_hello(s14) )
	{
		tests_failed += failures;
		cout << "FAILED to keep a promise." << endl;
	}
}

