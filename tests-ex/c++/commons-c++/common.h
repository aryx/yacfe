//* Includes
#ifndef COMMONS_COMMON_H
#define COMMONS_COMMON_H

#include <commons/pervasives.h>

namespace commons {

/*###########################################################################*/
//* Prelude
/*###########################################################################*/

/* Some of the following functions should be in their respective
 * sections but because some functions in some sections use functions
 * in other sections, and because I don't want to take care of the
 * order of those sections, of those dependencies, I put the functions
 * causing dependency problem here. Sometime can also use forward
 * declaration to avoid the problem.
 */

#if defined(__cplusplus)
#define BEGINCPP extern "C" {
#define ENDCPP }
#else
#define BEGINCPP
#define ENDCPP
#endif

/* ex:
BEGINCPP
void   erase(const char *path);
ENDCPP
*/

/*###########################################################################*/
//* A better pervasive, what should be in the standard
/*###########################################################################*/

typedef string filename; 


/* 
 * Can we do more ? such as count the number of objects created, copied,
 * destroyed ? or provide generic functionnalities useful for all classes ?
 *
 * we use the virtual func + template + (future) template specialisation to 
 * handle all types
 *
 * src: http://java.sun.com/j2se/1.5.0/docs/api/java/lang/Object.html
 */
class object { 
public:
	virtual string toString() = 0;

	virtual void debug() { cout << this->toString() << endl; }
	virtual void d() { this->debug(); }

	virtual ~object() {}
};
template <typename T> 
void debug(const T& x) { x.debug(); }

//class debugable { } // <=> class object

//class copyable { } 

// =~ copyable, but for classes that have derived classes
class cloneable {
public:
	virtual cloneable* clone() = 0;
	virtual ~cloneable() {}
};
template<typename T> 
T* clone(const T* tp)   { return tp->clone(); }

//class equalable { }
//class showable { }
//class ordable { }
//class numable { }



//obsolete: the boost serialization seems better
class serializable {
public:
	virtual string serialize() = 0;
	virtual void deserialize(string) = 0;

	virtual ~serializable() {}
};



//src: effective c++ v3. obsolete? boost:noncopyable provides same service ?
class uncopyable {
protected:                                   
  uncopyable() {}
  ~uncopyable() {}
private:
  uncopyable(const uncopyable&);
  uncopyable& operator=(const uncopyable&);
};



class unequalable {
private:
  bool operator==(const unequalable& b);
};



// src: accelerated c++, better pointers handling memory and polymorphism
// requirment: T must have a clone()
template <typename T> class Handle {
public:
	Handle(): p(0) { }
	Handle(const Handle& s): p(0) 
		{ if (s.p) p = s.p->clone(); }
	    // can also do for builtin { if (s.p) p = clone(s.p); }
	Handle& operator=(const Handle&);
	~Handle() { delete p; }

	Handle(T* t): p(t) { }

	operator bool() const { return p; }
	T& operator*() const; // throw NullHandle
	T* operator->() const; // throw NullHandle

private:
	T* p;
};



/* Autogenerate the setter/getter.
 * Would be cool if could with CPP have a capitalize function to not require
 * the programmer to supply __methodbase
 */
#define SET_GET(__field,__methodbase,__type)       \
  get##__methodbase() { return __field; }               \
  set##__methodbase(__type __x) { __field = __x; } 




/*###########################################################################*/
//* Devel oriented functions
/*###########################################################################*/

/*****************************************************************************/
//** Debugging/logging (cf also commons/logging.h)
/*****************************************************************************/
void pr2(const string& s);

#define DEBUG_Y

#ifdef DEBUG_Y
#define DEBUG(x) x
#else
#define DEBUG(x)
#endif

// compile time assert, trick using fake array with negative value
// src: tony hoare slides on assertions practice at microsoft
#define CASSERT(x)extern	dummy[(x)?1:-1]

/*****************************************************************************/
//** Profiling (cpu/mem)
/*****************************************************************************/

/*****************************************************************************/
//** Test (cf also commons/unit_testing.h)
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

/* src: http://gcc.gnu.org/egcs-1.1/c++features.html
 * __FUNCTION__ and __PRETTY_FUNCTION__ are now treated as variables
 * by the parser; previously they were treated as string constants. So
 * code like `printf (__FUNCTION__ ": foo")' must be rewritten to
 * `printf ("%s: foo", __FUNCTION__)'. This is necessary for templates.
 *
 * according to assert.h __PRETTY_FUNCTION__ is defined only for gcc > 2.6
 */
#define __HERE__  commons::here(__FILE__, __LINE__, __PRETTY_FUNCTION__)

string here(const char* file, unsigned int line, const char *func);

//----------------------------------------------------------------------------
//*** Base classes for exception, better than standard one: have backtrace info
//----------------------------------------------------------------------------

//src: http://www-128.ibm.com/developerworks/library/l-cppexcep.html?ca=dnt-68
class exception : public std::exception, public object
{
public:
	exception(string where);
	virtual ~exception() throw() { }

	virtual const char* what() const throw();

	virtual string diagnostic();
	virtual string toString()    { return this->diagnostic(); }

public:
	string where;
	string backtrace;
private:
	mutable string classname;
};

class exception_with_msg : public exception
{
public:
	string msg;
	mutable string tmp;

	exception_with_msg(string where, string msg) : exception(where), msg(msg){}
	virtual ~exception_with_msg() throw() { }
	virtual const char* what() const throw();

	virtual const char* msg_c_str(string prefix) const throw();
};


//----------------------------------------------------------------------------
//*** Basic exceptions
//----------------------------------------------------------------------------

class Todo : public exception
{
public:
	Todo(string where) : exception(where) { }
	virtual const char* what() const throw() { return "Todo";	}
};

class Impossible : public exception
{
public:
	Impossible(string where) : exception(where) { }
	virtual const char* what() const throw() { return "Impossible";	}
};

class Timeout : public exception
{
public:
	Timeout(string where) : exception(where) { }
	virtual const char* what() const throw() { return "Timeout";	}
};





class SysError : public exception_with_msg
{
public:
	SysError(string where, string msg) : exception_with_msg(where,msg) { }
	virtual ~SysError() throw() { }
	virtual const char* what() const throw() { 
		return this->msg_c_str("SysError: ");
	}
};

// rename FileNotFound ?
class FileOpenError : public SysError
{
public:
	FileOpenError(string where, string msg) : SysError(where,msg) { }
	virtual ~FileOpenError() throw() { }
	virtual const char* what() const throw() { 
		return this->msg_c_str("FileOpenError: ");
	}
};
//should not be needed. Bad practice.
class NotOpened : public exception
{
public:
	NotOpened(string where) : exception(where) { }
	virtual const char* what() const throw() { return "NotOpened";	}
};

class EndOfFile : public exception
{
public:
	EndOfFile(string where) : exception(where) { }
	virtual const char* what() const throw() { return "EndOfFile";	}
};




class EndOfIter : public exception
{
public:
	EndOfIter(string where) : exception(where) { }
	virtual const char* what() const throw() { return "EndOfIter";	}
};



class BadFormat : public exception_with_msg {
public:
	BadFormat(string where, string s) : exception_with_msg(where, s){ }
	~BadFormat() throw() { }
	virtual const char* what() const throw() 
	{ return this->msg_c_str("BadFormat: "); }
};

class UserError : public exception_with_msg {
public:
	UserError(string where, string s) : exception_with_msg(where, s){ }
	~UserError() throw() { }
	virtual const char* what() const throw() 
	{ return this->msg_c_str("UserError: "); }
};


class NotFound : public exception_with_msg
{
public:
	NotFound(string where, string msg) : exception_with_msg(where,msg) { }
	virtual ~NotFound() throw() { }
	virtual const char* what() const throw() { 
		return this->msg_c_str("NotFound:");
	}
	
};


struct NullHandle : public exception {
	NullHandle(string where) : exception(where) { }
};

class Failwith : public exception_with_msg
{
public:
	Failwith(string where, string msg) : exception_with_msg(where,msg) { }
	virtual ~Failwith() throw() { }
	virtual const char* what() const throw() { 
		return this->msg_c_str("Failwith: ");
		//return (string("Failwith:") + msg).c_str();
	}
};


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
bool is_even(int n);
bool is_odd(int n);


/*****************************************************************************/
//** Tuples
/*****************************************************************************/

/*****************************************************************************/
//** Maybe
/*****************************************************************************/

/*****************************************************************************/
//** String
/*****************************************************************************/

string i_to_s(int x);
int    s_to_i(const string& x); 
int    s_to_i_safe(const string& x); // throw Failwith

template <typename T> 
string x_to_s(T& x);

vector<string> 
split(const string& str, const string& delim);

vector<string> 
split(const string& str);

string 
join(vector<string> &str, string delim);

/*****************************************************************************/
//** Regexp
/*****************************************************************************/

/*****************************************************************************/
//** Filename
/*****************************************************************************/

/*****************************************************************************/
//** Dates
/*****************************************************************************/

/*****************************************************************************/
//** Lines/Words/Strings
/*****************************************************************************/

/*****************************************************************************/
//** Process/File
/*****************************************************************************/

vector<string> cat(filename file);

// read on cin
bool y_or_no(); // throw FailWith

string getenv(string key); //throw NotFound

int command(string cmd);
int command_y_or_no(string cmd);

vector<string> cmd_to_vector(string cmd);

// to be safe the new tmp file is also created so you have to erase it yourself
string temp_file_name();

vector<filename> glob(string);


// must try to avoid to use it. Use fstream.
std::FILE * 
fopen(const char* path, const char* mode);//throw FileOpenError

/* convention: -1 means from very start or until very end
 * was previously SnippetFetch
 */
string extract_lines_file(const string& filename, 
						  int from_line, int to_line);// throw FileOpenError


/*###########################################################################*/
//* And now collection like types
/*###########################################################################*/

/*****************************************************************************/
//** List
/*****************************************************************************/

/*****************************************************************************/
//** Array
/*****************************************************************************/

/*****************************************************************************/
//** Set
/*****************************************************************************/

/*****************************************************************************/
//** Assoc
/*****************************************************************************/

/*****************************************************************************/
//** Hash
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
//* And now misc functions, types
/*###########################################################################*/

/*****************************************************************************/
//** Locations, parsing
/*****************************************************************************/

class FileLocation : public commons::object {
public:
	string path;

	int line;
	int column;

	//int charpos;

	FileLocation(string path, int line, int column) 
	: path(path), line(line), column(column) 
	{ }

	~FileLocation() { }

	virtual string toString() { return ("FileLocation:" + path) ; }
};
	

/*****************************************************************************/
//** Misc/test
/*****************************************************************************/


/*###########################################################################*/
//* Implementation (for templates and inline functions)
/*###########################################################################*/


template <typename T> 
string x_to_s(T& x)
{
	std::stringstream ss;
	ss << x;
	return ss.str();
}

//----------------------------------------------------------------------
template <class T>
Handle<T>& Handle<T>::
operator=(const Handle& rhs)
{
	if (&rhs != this) {
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}
	return *this;
}

template <class T>
T& Handle<T>::
operator*() const
{
	if (p) 	
		return *p;
	throw NullHandle(__HERE__);
}

template <class T>
T* Handle<T>::
operator->() const
{
	if (p)
		return p;
	throw NullHandle(__HERE__);
}


}
#endif
