#ifndef UNIT_TESTING_H
#define UNIT_TESTING_H

#include <commons/pervasives.h>

// Have to include them because my wrapper CPP macros reference
// other CPP macros of those libraries so have at least to include
// the files that defined those macros.
#include <cppunit/extensions/HelperMacros.h>

namespace commons {

//----------------------------------------------------------------------------
//*** basically a CppUnit wrapper
//----------------------------------------------------------------------------

// see hello.cpp for example of use

#define UNIT_TEST_BEGIN CPPUNIT_TEST_SUITE
#define UNIT_TEST_END CPPUNIT_TEST_SUITE_END
#define UNIT_TEST CPPUNIT_TEST

#define UNIT_TEST_REGISTRATION CPPUNIT_TEST_SUITE_REGISTRATION

#define UNIT_ASSERT CPPUNIT_ASSERT

class UnitTestFixture : public CppUnit::TestFixture {
};

typedef CppUnit::Test UnitTest;

bool unit_test_run_default();
bool unit_test_run(vector<UnitTest*>& vec);

#define UNIT_TEST_LIGHTWEIGHT(funcname) \
class class_##funcname : public commons::UnitTestFixture { \
 UNIT_TEST_BEGIN(class_##funcname); \
 UNIT_TEST(test_##funcname); \
 UNIT_TEST_END(); \
public: \
	void setUp() { } \
	void tearDown() { } \
    void test_##funcname() { funcname(); } \
};\
UNIT_TEST_REGISTRATION(class_##funcname);


}

#endif

