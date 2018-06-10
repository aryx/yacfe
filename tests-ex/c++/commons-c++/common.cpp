//* Includes
#include <commons/common.h>

#include <commons/compatibility.h>
#include <commons/portability.h>

#include <cstdlib>

#include <boost/regex.hpp>

#include <commons/unit_testing.h>

/*###########################################################################*/
//* We use
/*###########################################################################*/

/* We use lots of libraries, but in many cases I prefer to define
 * wrappers over those libraries. The reasons are that those libs are
 * often too big so you get lost, they dont provide good exception
 * facility, they usually work on FILE or char* instead of streams
 * and strings, and they dont provide good debugging support. Moreover by
 * defining wrappers we are less dependent to them so if we found later
 * a better replacement, we can change the implementation of the wrapper
 * without disturbing the clients of those wrappers.
 *
 * As stroustrup said, the ISO comittee aimed at providing building
 * blocks for better library, so there is no shame in defining
 * wrappers over most of the C++ library. It was designed for this.
 * Because they designed building blocks, they could not provide safe
 * libraries because some user or library wrapper maker will pay for
 * this. "When you are at the very bottom, if you are slow, everyone
 * else above you is slow". So again, no shame to define wrappers.
 */


//** Linux syscalls 



//** C library (should avoid to use it)

//*** glibc
// see http://www.gnu.org/software/libc/manual/

// #include <assert.h>     /* assert */
// #include <stdint.h>     /* uint32_t etc */
// #include <stdlib.h>     /* exit, system */
// #include <stdio.h>      /* printf */
// #include <string.h>     /* strlen, strtok */
// #include <time.h>       /* time_t */
// #include <unistd.h> ??
// #include <sys/errno.h>  /* perror */
// #include <sys/param.h>  /* attempt to define endianness */
// #include <sys/stat.h> ??
// #include <sys/timeb.h>
// #include <sys/types.h> ??

// #ifdef linux
// # include <endian.h>    /* attempt to define endianness */
// #endif

// #include <getopt.h> 


//*** Other C libraries





//** C++ library (std:: namespace)

// from: http://en.wikipedia.org/wiki/C++_standard_library
// from: http://www.cplusplus.com/reference/
// see also http://cppreference.com/
// see also http://www.sgi.com/tech/stl/

// The standard C++ library is a collection of functions, constants,
// classes, objects and templates that extends the C++ language
// providing basic functionality to perform several tasks, like
// classes to interact with the operating system, data containers,
// manipulators to operate with them and algorithms commonly needed.

//*** C++ wrapper of the C library (essentially just wrap in std namespace)

// The elements of the C language library are also included as a
// subset of the C++ Standard library. These cover many aspects, from
// general utility functions and macros to input/output functions and
// dynamic memory management functions. They are divided in several
// files. Our reference at this moment covers the following header
// files of the C library:

// cassert	C Diagnostics Library (header)
// cctype	Character handling functions (header) (isalpha, etc)
// cerrno	C Errors (header)
// cfloat	Characteristics of floating-point types (header)
// climits	Sizes of integral types (header)
// clocale	C localization library (header)
// cmath	C numerics library (header)
// csetjmp	Non local jumps (header)
// csignal	C library to handle signals (header)
// cstdarg	Variable arguments handling (header)
// cstddef	C Standard definitions (header) (size_t, etc)
// cstdio	C library to perform Input/Output operations (header)
// cstdlib	C Standard General Utilities Library (bsearch, qsort, atof, getenv)
// cstring	C Strings (header) (memset, strdup, strlen, strcpy, etc)
// ctime	C Time Library (header)

// cwctype
// cwchar

//*** I/O Stream library

// iosfwd
// iostream
// ios
// streambuf
// istream
// ostream
// iomanip
// sstream
// fstream


//*** String library


//*** Locales, unicode

// locale
// clocale

//*** Numeric, complex
// complex
// valarray
// numeric

//*** Possible exceptions, cf <stdexcept>

// exception
//  logic_error
//   length_error
//   out_of_range
//   invalid_argument
//   domain_error
//  runtime_error
//   overflow_error
//   underflow_error
//   range_error
//  bad_alloc
//  bad_cast
//  bad_typeid
//  ios_base::failure


//*** STL library 

// The standard template library defines the following container types:
// containers, iterators, algorithms, function objects, adaptaters

// vector	Vector (class template)
// deque	Double ended queue (class template)
// list	    List (class template)
// stack	LIFO stack (class template)
// queue	FIFO queue (class template)
// priority_queue	Priority queue (class template)
// set	    Set (class template)
// multiset	Multiple-key set (class template)
// map	    Map (class template)
// multimap	Multiple-key map (class template)
// bitset	Bitset (class template)
// 

// It also provides several algorithms to operate on ranges:
// algorithm
// iterator
// functionnal
// memory (allocators for containers, and auto_ptr)

//*** Misc

// utility (pair?)
// exception
// stdexcept
// limits
// new
// typeinfo (RTTI)




//** The Gnu extensions to the C++ library (__gnu_cxx:: namespace)

// #include <ext/hash_map>  
// hash_set ? hash_multiset, hash_multimap ?
// rope (better strings ?)

//** TR1 library (std::tr1 namespace)
// reference counting smart pointers shared_ptr
// function callback type
// hash
// regexps
// tuples
// array
// random numbers

// type_traits (is_builtin, has_virtual_destructor, is_empty_class, etc)




//** Boost library ?

// string and text processing 
//   printf like lib
//   regexps
//   tokens
//   parsing
// containers
// maths
// testing
// data structures (union, tuple)
// function objects and higher order programming (lambda)
// traits
// graph
// TMP, MPL, template metaprogramming, metaprogramming library, 
// social engineering
// memory 
//   pool
//   smart pointers
// date, time
// filesystem
// program options





//** The C++0x library ?

//*** new headers for C compatibility: 

// <ccomplex>, 
// <cfenv>, 
// <cinttypes>, 
// <cstdbool>, 
// <cstdint>, 
// <ctgmath>.


//*** new header

// <array>, 
// <random>, 
// <regex>, 
// <tuple>, 
// <type_traits>, 
// <unordered_map>, 
// <unordered_set>. 




//** GUI ? 
//** Communication ? 
//** Database ? 
//** Persistency ? Serialization ?
//** Concurrency ? threads ?
//** Distribution ? MPI ?

//** Logging, cf logging.cpp
//** Unit Test, cf unit_testing.cpp



/*###########################################################################*/
//* Prelude
/*###########################################################################*/

namespace commons {

/*###########################################################################*/
//* Devel oriented functions 
/*###########################################################################*/

/*****************************************************************************/
//** Debugging/logging
/*****************************************************************************/

void pr2(const string& s) { cerr << s << endl; }

/*****************************************************************************/
//** Profiling (cpu/mem)
/*****************************************************************************/


/*****************************************************************************/
//** Test, and regression testing
/*****************************************************************************/


/*****************************************************************************/
//** Persistence
/*****************************************************************************/

/*****************************************************************************/
//** String_of and (pretty) printing
/*****************************************************************************/

/*****************************************************************************/
//** Composition/Control
/*****************************************************************************/

/*****************************************************************************/
//** Error managment
/*****************************************************************************/
// macro __HERE__ in header


// src: http://www.decompile.com/cpp/faq/file_and_line_error_string.htm
//#define STRINGIFY(x) #x
//#define TOSTRING(x) STRINGIFY(x)
//old: #define __HERE__  __FILE__ ":" TOSTRING(__LINE__)

// old: put DEBUG(printf(.....));), but sux. better is to use a gcc extension:
// #define MyPRINT(format, a...) printf(format, ##a)



string here(const char* file, unsigned int line, const char *func)
{ return string(file) + ":" + i_to_s(line)     + ":" + string(func); }


exception::exception(string where)
: std::exception(), where(where), backtrace(portability::backtrace()) 
{ 
}

const char* 
exception::what() const throw()
{
	string realname_class = string(typeid(this).name());
	this->classname = portability::demangle(realname_class);
	this->classname.append(" (" + realname_class + ")");
	return this->classname.c_str();
}

string 
exception::diagnostic()
{
	return 
		string("Exception: ") + string(this->what()) + "\n" +
		string("Where: ") + this->where + "\n" +
		string("Backtrace: ") + "\n" + this->backtrace + "\n";
}

const char* 
exception_with_msg::msg_c_str(string prefix) const throw()
{ 
	this->tmp = "";
	this->tmp.append(prefix);
	this->tmp.append(this->msg);
	return this->tmp.c_str(); 
}

const char* 
exception_with_msg::what() const throw()
{
	return this->msg_c_str("exception_with_msg:");
	//return (string("Failwith:") + msg).c_str();
}



// class Todo in header
// class Impossible in header
// class SysError in header


/*****************************************************************************/
//** Equality
/*****************************************************************************/


/*###########################################################################*/
//* And now basic types
/*###########################################################################*/

/*****************************************************************************/
//** Bool
/*****************************************************************************/

/*****************************************************************************/
//** Char
/*****************************************************************************/

/*****************************************************************************/
//** Num
/*****************************************************************************/

bool is_even(int n) { return (n % 2 == 0); } 
bool is_odd(int n)  { return !is_even(n); } 
//return (n % 2 != 0)

/*****************************************************************************/
//** Numeric/overloading
/*****************************************************************************/


/*****************************************************************************/
//** Tuples
/*****************************************************************************/

/*****************************************************************************/
//** Maybe
/*****************************************************************************/

/*****************************************************************************/
//** Strings
/*****************************************************************************/
string i_to_s(int x) 
{
	std::stringstream ss;
	ss << x;
	return ss.str();
}

int s_to_i(const string& s)
{
	// not safe, atoi() does not return special value when s is not an int
	return std::atoi(s.c_str()); 
}

int s_to_i_safe(const string& s)
{
	int i;
	std::stringstream myStream(s);
	if (myStream >> i) return i;
	else throw Failwith(__HERE__, "s_to_i not integer");
}


vector<string> 
split(const string& str1, const string& delim)
{
    //src: google split string c++
	//slow because constantly copy substring into str
	vector<string> results;
	string str = str1;
	
    size_t cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos )	{
		if(cutAt > 0)
			results.push_back(str.substr(0,cutAt));
		str = str.substr(cutAt+1);
	}
	if(str.length() > 0)
		results.push_back(str);
	return results;

}


//src: accelerated c++, good, but slower than boost version
vector<string> 
split_accelerated(const string& s)
{

	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters `['original value of `i', `i)'
	while (i != s.size()) {
		// ignore leading blanks
		// invariant: characters in range `['original `i', current `i)' are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range `['original `j', current `j)' is a space
		while (j != s.size() && !isspace(s[j]))
			++j;

		// if we found some nonwhitespace characters
		if (i != j) {
			// copy from `s' starting at `i' and taking `j' `\-' `i' chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}

	}
	return ret;
}

// src: google split string
vector<string> 
split_misc(const string& s)
{
	//does not work 

	//std::istringstream is(str);
	//return vector(std::istream_iterator<string>(is),
	//			  std::istream_iterator<string>());
	throw Todo(__HERE__);
	
}

// from beyond C++, boost
vector<string> 
split(const string& s)
{
  static boost::regex re(" +");
  vector<string> vec;
  boost::sregex_token_iterator it(s.begin(),s.end(),re,-1);
  boost::sregex_token_iterator end;
  while (it!=end) 
	  vec.push_back(*it++);

  //assert(vec.size()==std::count(s.begin(),s.end(),'/')+1);
  return vec;
}
void test_split() {
	vector<string> a = split("this is a    big melon");
	vector<string> b;
	b.push_back("this");
	b.push_back("is");
	b.push_back("a");
	b.push_back("big");
	b.push_back("melon");
	
	UNIT_ASSERT(a == b);
}
UNIT_TEST_LIGHTWEIGHT(test_split);



string 
join(vector<string> &str, string delim)
{
	throw Todo(__HERE__);
}


/*****************************************************************************/
//** Regexp
/*****************************************************************************/

/*****************************************************************************/
//** Filenames
/*****************************************************************************/



/*****************************************************************************/
//** Dates
/*****************************************************************************/

/*****************************************************************************/
//** Lines/Words/Strings
/*****************************************************************************/

/*****************************************************************************/
//** Process/Files
/*****************************************************************************/

vector<string> 
cat(filename file)
{
	vector<string> res;
	string s;
	std::ifstream fin(file.c_str());
	if(fin.fail()) throw FileOpenError(__HERE__, file);
	while(std::getline(fin,s)) {
		res.push_back(s);
	}
	if (!fin.eof()) throw FileOpenError(__HERE__, file);
	return res;
}

std::FILE * 
fopen(const char *path, const char *mode)
{
  std::FILE *file = std::fopen(path, mode);
  if (file == NULL) 
	  throw FileOpenError(__HERE__, string(path));

  return file;
}

void erase(const char *path)
{
  std::fclose(fopen(path,"wt"));
}

string temp_file_name()
{
	char* readonly_tmpl = "/tmp/temp_XXXXXX";
	char  tmpl[40];
	assert(std::strlen(readonly_tmpl) < 40);

	// cant use directly readonly_tmpl because it points to a read only
	// region and mkstemp need to modify its argument
	std::strcpy(tmpl, readonly_tmpl);
	int descriptor = mkstemp(tmpl);
	if(descriptor == -1)
		throw SysError(__HERE__,"cant create temporary name");

	string res(tmpl);
	close(descriptor);

	return res;

	//old: according to gcc, tmpnam and tempnam are considered unsafe

	//use tmpnam
    //char buffer [L_tmpnam];
	//char * pointer;
	//pointer = std::tmpnam(buffer);
	//if(pointer==NULL)
	//	throw SysError(__HERE__,"cant create temporary name");

	//use tempnam
	//char* str = tempnam(NULL/*default tmp dir*/, "temp_");
	//if(str == NULL)
	//	throw SysError(__HERE__,"cant create temporary name");
	//string res(str);
}



bool y_or_no()
{
	string answer;
	cin >> answer;
	if(answer == "y" || answer == "Y" || answer == "yes") return true;
	if(answer == "n" || answer == "N" || answer == "no")  return false;
	throw Failwith(__HERE__, "must give either y or n");
}

int command(string cmd) 
{
	return std::system(cmd.c_str());
}

int command_y_or_no(string cmd) 
{
	cout << "executing:" + cmd + " . Are you sure ? [y/n]" << endl;
	if(y_or_no())
		return command(cmd);
	else 
		return 0;
}

string getenv(string key)
{
	char* val = std::getenv(key.c_str());
	if(val == NULL) throw NotFound(__HERE__, key);
	else return string(val);
}

vector<string> cmd_to_vector(string cmd)
{
	string tmpfile = temp_file_name();
	command(cmd + " > " + tmpfile);
	vector<string> res = cat(tmpfile);
	command("rm -f " + tmpfile);
	return res;
}

vector<filename> glob(string pattern)
{
	return cmd_to_vector("ls -1 " + pattern);
}

// was in SnippetFetch.cpp, I just transformed it to use string so less
// memory leak risk.
string extract_lines_file(const string& filename, int from, int to)
{
	string res;

    FILE * f = fopen(filename.c_str(), "r");
    if(f == NULL)
        throw FileOpenError(__HERE__,filename);
    
    size_t  line_size = 0;
    ssize_t read_size = 0;
    char    *line     = NULL;
    int     curr_line = 1;

    //cerr << "file: " << file << " [" << from << "," << to << "]" << endl;
    while((read_size = getline(&line, &line_size, f)) != -1) { 

        if(curr_line < from && from != -1) {
            curr_line++;
            continue;        
        }               

        if(curr_line > to && to != -1)
            break;       
        
        line[read_size] = '\0';
		
		res.append(line);
        curr_line++;
    }
    if(line)
        free(line);
	fclose(f);
	
    return res;
}


/*###########################################################################*/
//* And now collection like types
/*###########################################################################*/

/*****************************************************************************/
//** List
/*****************************************************************************/

/*****************************************************************************/
//** Arrays
/*****************************************************************************/

/*****************************************************************************/
//** Set. Can also use Hashtbl.
/*****************************************************************************/

/*****************************************************************************/
//** Assoc. Can also use Hashtbl.
/*****************************************************************************/

/*****************************************************************************/
//** Hashtbl
/*****************************************************************************/

/*****************************************************************************/
//** Hash sets
/*****************************************************************************/

/*****************************************************************************/
//** Stack
/*****************************************************************************/

/*****************************************************************************/
//** Binary tree
/*****************************************************************************/

/*****************************************************************************/
//** Graph
/*****************************************************************************/

/*###########################################################################*/
//* And now misc functions
/*###########################################################################*/

/*****************************************************************************/
//** Locations, parsing
/*****************************************************************************/

// class file_location in header

/*****************************************************************************/
//** Misc/test
/*****************************************************************************/

}
