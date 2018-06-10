#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <commons/pervasives.h>

#include <boost/program_options.hpp>

namespace commons {

//----------------------------------------------------------------------------
//*** Basically a boost::program_options wrapper
//----------------------------------------------------------------------------
// see hello.cpp for example of use

namespace po = boost::program_options;



typedef po::options_description ProgramOptionsDescription;

// to be used in the add_options() call, cf hello.cpp
template<typename T>
po::typed_value<T>* 
cmdline_option(T* v) 
{ 
	return po::value(v);
}

template<typename T>
po::typed_value<T>* 
cmdline_bool(T* v) 
{ 
	return po::bool_switch(v);
}


class ProgramOptionsMap : public po::variables_map {
public:
	bool has(string key) { return this->count(key); }
};

class ProgramOptions 
{
public:
	ProgramOptionsMap options;
	vector<string> args;
};

ProgramOptions 
parse_cmdline(int argc, char** argv, ProgramOptionsDescription desc);

void 
usage_and_exit(string usage_str, ProgramOptionsDescription desc);


}

#endif
