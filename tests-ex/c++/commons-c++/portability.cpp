#include <commons/pervasives.h> 

#include <commons/portability.h> 

#include <execinfo.h>  // for backtrace
#include <cxxabi.h> // for demangling

namespace portability{

const int BACKTRACE_ELEMENTS = 100;

string backtrace()
{
	stringstream out;

	void *addresses[BACKTRACE_ELEMENTS];
	char **strings;

	int size = ::backtrace(addresses, BACKTRACE_ELEMENTS);
	strings = ::backtrace_symbols(addresses, size);
	//glibc manual: only the return value need to be freed, not
	//the individual strings, so no need for free(strings[i]);

	//printf("Stack frames: %d\n", size);
	for(int i = 0; i < size; i++)
	{
		//printf("%d: %X\n", i, (int)addresses[i]);
		//printf("%s\n", strings[i]); }

		//out << i << ":" << addresses[i] << ":" << strings[i] << endl;
		out << strings[i] << endl;

	}
	if(strings)
		free(strings);

	return out.str();
}

string demangle(string name)
{
	int status;
	char* realname;
	realname = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
	string classname = realname;
	free(realname);
	return classname;
}


} // end namespace
