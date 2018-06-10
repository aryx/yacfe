#include <commons/unit_testing.h>

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResultCollector.h>


/* from cppunit website: 

CppUnit is a C++ unit testing framework. It started its life as a port
of JUnit to C++ by Michael Feathers. For a quick tour of unit
testing with CppUnit, see the Cookbook in the latest
documentation. For an introduction to unit testing, see
UnitTest, ProgrammerTest, and CodeUnitTestFirst at
the C2.com wiki.

Features:

* XML output with hooks for additional data (XSL format avaliable in
  release 1.10.2 needs some FiXing)
* Compiler-like text output to integrate with an IDE
* Helper macros for easier test suite declaration
* Hierarchical test fixture support
* Test registry to reduce recompilation need
* Test plug-in for faster compile/test cycle (self testable dynamic library)
* Protector to encapsulate test execution (allow capture of exception
  not derived from std::exception)
* MfcTestRunner, 
* QtTestRunner, a Qt based graphic test runner
* QxTestRunner, a Qt4 based graphic test runner
* CursesTestRunner
* WxWidgetsTestRunner (formerly: WxWindowsTestRunner)


from FAQ concerning libraries:

The ar utility strips out some of the static variable information used
by CppUnit. So if you create a static library (.a), the
CppUnit::TestFactoryRegistry won't return any tests for classes in
that static library. The solution is to either compile your test
classes in to a dynamic library (.so) or to link your test runner
directly with the individual object (.o) files.

Note that you could just explicitly add the test fixtures from a
static library to test runner class, bypassing the factory registry
entirely

*/



namespace commons {

//----------------------------------------------------------------------------
//*** Basically a CppUnit wrapper
//----------------------------------------------------------------------------

bool unit_test_run(vector<UnitTest*> &suite)
{

	CppUnit::TextUi::TestRunner runner;

	FOREACH(UnitTest* &s, suite) {
		runner.addTest(s);
	}

	bool success = runner.run("", false);
	return success;

//	// Create the event manager and test controller
//	CPPUNIT_NS::TestResult controller;
//
//	// Add a listener that colllects test result
//	CPPUNIT_NS::TestResultCollector result;
//	controller.addListener( &result );        
//
//	// Add a listener that print dots as test run.
//	CPPUNIT_NS::BriefTestProgressListener progress;
//	controller.addListener( &progress );      
//
//	// Add the top suite to the test runner
//	CPPUNIT_NS::TestRunner runner;
//	runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
//	runner.run( controller );
//
//	// Print test in a compiler compatible format.
//	CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
//	outputter.write(); 
//	outputter.printFailuresList();
//	outputter.printFailureReport();
//
//	return result.wasSuccessful() ? 0 : 1;


	//CppUnit::BriefTestProgressListener listener;
	//runner.eventManager().addListener(&listener);
	// Change the default outputter to a compiler error format outputter
	//runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
    //                                                   std::cerr ) );

}

bool unit_test_run_default()
{
	UnitTest * suite = 
		CppUnit::TestFactoryRegistry::getRegistry().makeTest();
	vector<UnitTest*> vec;
	vec.push_back(suite);
	return unit_test_run(vec);
}

}
