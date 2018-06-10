#ifndef PERVASIVES_H
#define PERVASIVES_H

/* Why this file ?
 *
 * I dont want to do 'using namespace std;' in header files because
 * then I get all the functions from std. But I dont want to type
 * each time std::string. Also I dont want in each of my file to put
 * a long list of #include just to include stuff that we should always
 * include. Enter pervasives.h that include most of what you want.
 * So by just putting #include <commons/pervasives.h> you get a good
 * environment to start working. The only problem is that you may include
 * too much header, which can slow down compilation, but I prefer to 
 * slow down compilation that slow down me. Moreover one day can use
 * precompiled header, and most of the time you will include anyway
 * lots of include so no need to be clever and try to include only
 * what is necessary.
 * 
 */


#include <cassert>
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>



// related to <stdint.h>, but do it linux way (see include/linux/types.h)
typedef unsigned int		u32;
typedef unsigned int		uint;

//typedef signed char s8;
//typedef unsigned char u8;
//
//typedef signed short s16;
//typedef unsigned short u16;
//
//typedef signed int s32;
//typedef unsigned int u32;
//
//typedef signed long long s64;
//typedef unsigned long long u64;

//typedef unsigned long word;
//typedef word  size_t; ?

#include <exception>
using std::exception;



#include <string>
using std::string; 



#include <sstream>
using std::stringstream;

#include <istream>

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;



#include <list>
#include <map>
#include <vector>
#include <set>
#include <stack>
// multimap?
using std::list;
using std::map;
using std::vector;
using std::set;

#include <ext/hash_map>
using __gnu_cxx::hash_map;

/* bugfix in gcc lib to be able to have string as key in hash_map
 *
 * src: http://gcc.gnu.org/ml/libstdc++/2002-04/msg00107.html
 * "I guess that the reason for not having this declared in the std::string 
 * is that the hash* are extensions to the standard. Maybe something like 
 * the above could be added into the codebase somewhere else?"
 */
namespace __gnu_cxx {
	template<> struct hash< std::string > {
		size_t operator()( const std::string& x ) const 
		{ return hash< const char* >()( x.c_str() ); }
	};
}


#include <algorithm>
#include <iterator>

#include <utility>
using std::pair;


// from boost, but not in ubuntu by default so have to copy it in libs/
#include <libs/foreach.hpp> 
#define FOREACH BOOST_FOREACH

#include <tr1/memory>
//#include <tr1/boost_shared_ptr.h> // does not work 
//using std::tr1::shared_ptr
//#define sptr std::tr1::shared_ptr

using std::auto_ptr;

#endif

