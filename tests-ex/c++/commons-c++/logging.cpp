#include <commons/logging.h>

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>

/* from README of log4cxx:

Introduction
============
Log4cxx is a port to C++ of the log4j project.
The goal is have the same functionnalities and interfaces of log4j.

Features
========
It's a flexible and highly configurable logging framework
Main features :
- Configurable logging destinations (appenders)
- Configurable logging format (layouts)
- Categorized logging statements through a hierarchy (loggers)
- Advanced filtering (filters)
- Thread safe library
- UTF-16 Unicode support

* Appenders:
  AsyncAppender, ConsoleAppender, DailyRollingFileAppender, FileAppender,
  NTEventLogAppender, ODBCAppender, RollingFileAppender, SMTPAppender,
  SocketAppender, SocketHubAappender, SyslogAppender, TelnetAppender,
  XMLSocketAppender

* Layouts:
  HTMLLayout, PatternLayout, SimpleLayout, TTCCLayout, XMLLayout

* Filters:
  DenyAllFilter, LevelMatchFilter, LevelRangeFilter, StringMatchFilter

* Configurators:
  BasicConfigurator, DOMConfigurator, PropertyConfigurator

* Java like objects with dynamic cast and instanciation. Custom objects can
  be configured through the DOMConfigurator and PropertyConfigurator classes

Supported OS
============
* Linux (tested on Linux Mandrake 10.0)
* FreeBSD
* Windows (MSVC 6.0, MSVC 7.1 or Cygwin)
* Other POSIX OS should be supported but were not tested

*/

namespace commons {

//----------------------------------------------------------------------------
//*** Basically a log4cxx wrapper
//----------------------------------------------------------------------------
Logger mk_Logger(string s)
{ return log4cxx::Logger::getLogger(s); }

void configure_log(string filename)
{ log4cxx::PropertyConfigurator::configure(filename.c_str()); }
void configure_log_console()
{ log4cxx::BasicConfigurator::configure();}

Logger get_root_Logger()
{ return log4cxx::Logger::getRootLogger(); }

void set_log_level(Logger lg, enum LevelLogger lvl)
{
	log4cxx::LevelPtr lvlptr;
	switch(lvl) {
	case ALL: lvlptr = log4cxx::Level::ALL; break;
	case DEBUG: lvlptr = log4cxx::Level::DEBUG; break;
	case INFO: lvlptr = log4cxx::Level::INFO; break;
	case WARN: lvlptr = log4cxx::Level::WARN; break;
	case ERROR: lvlptr = log4cxx::Level::ERROR; break;
	case FATAL: lvlptr = log4cxx::Level::FATAL; break;
	case OFF: lvlptr = log4cxx::Level::OFF; break;
	}
	lg->setLevel(lvlptr);
	
}
//get_root_Logger()->setLevel(log4cxx::Level::getInfo());
//get_root_Logger()->setLevel(log4cxx::Level::DEBUG);


}
