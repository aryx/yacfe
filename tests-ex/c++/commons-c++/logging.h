#ifndef LOGGING_H
#define LOGGING_H

#include <commons/pervasives.h>

// Have to include them because my wrapper CPP macros reference
// other CPP macros of those libraries so have at least to include
// the files that defined those macros.
#include <log4cxx/logger.h>

namespace commons {

//----------------------------------------------------------------------------
//*** Basically a log4cxx wrapper
//----------------------------------------------------------------------------
// see hello.cpp for example of use

typedef log4cxx::LoggerPtr Logger;
Logger mk_Logger(string s);

#define LOG_DEBUG LOG4CXX_DEBUG
#define LOG_INFO  LOG4CXX_INFO
#define LOG_WARN  LOG4CXX_WARN
#define LOG_ERROR LOG4CXX_ERROR
#define LOG_FATAL LOG4CXX_FATAL

void configure_log(string log4_config_file);
void configure_log_console() ;

enum LevelLogger { ALL, DEBUG, INFO, WARN, ERROR, FATAL, OFF };

Logger get_root_Logger();
void set_log_level(Logger lg, enum LevelLogger lvl);

}
#endif
