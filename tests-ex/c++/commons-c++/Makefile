TOP=..
-include $(TOP)/Makefile.common

##############################################################################
# Variables
##############################################################################
INCLUDES=-I$(TOP)/include -I/usr/include/qdbm
SYSLIBS=$(COMMONSYSLIBS)
LIBS=$(TOP)/libs/libmisc_external.a

##############################################################################
# Generic variables
##############################################################################

CFLAGS+= -Wall $(INCLUDES) $(CPPFLAGS)
LDFLAGS+= $(LIBS) $(SYSLIBS)

##############################################################################
# Top rules
##############################################################################

LIB=libcommons
PROGS=commons_test



SRCLIB= compatibility.cpp portability.cpp pervasives.cpp common.cpp \
    logging.cpp unit_testing.cpp dbm_simple.cpp dbm.cpp program_options.cpp \
    cm_timer.cpp cm_hash.cpp cm_status.cpp cm_conf_manager.cpp cm_sysinfo.cpp \
    encrypt.cpp cm_encrypt.cpp cm_license.cpp sigfile.cpp cm_expire.cpp \
    exclude_list.cpp  \
    FSM.o FSM_Driver.o \
    util.cpp

OBJSLIB=$(SRCLIB:.cpp=.o)

all:: $(LIB).a $(LIB).so $(PROGS)

$(LIB).a:  $(OBJSLIB)
	rm -f $(LIB).a
	$(CXXMKLIB) $(LIB).a $(OBJSLIB)

$(LIB).so:  $(OBJSLIB)
	rm -f $(LIB).so
	$(CXXMKLIBSHARED) -o $(LIB).so $(OBJSLIB)

commons_test: commons_test.o $(OBJSLIB) $(LIBS) 
	$(CXX) -o $@ $^ $(COMMONSYSLIBS)
#-lxqdbm -lqdbm -lboost_regex -lboost_serialization -lboost_program_options

all::
	cp $(LIB).so $(TOP)/lib

clean::
	rm -f $(PROGS) $(LIB)


test::
	./commons_test unit_test

##############################################################################
# Developer rules
##############################################################################

checkmem:
	$(CHECKMEM) --gen-suppressions=yes ./commons_test unit_test

checkmem2:
	$(CHECKMEM) --gen-suppressions=yes ./commons_test persistent_hash


.SUFFIXES: .i

commons_after_cpp:
	$(CXX) -E -c $(CFLAGS) commons.cpp

.cpp.i:
	$(CXX) -E -c $(CFLAGS) $*.cpp

##############################################################################
# Generic rules
##############################################################################

.cpp.o:
	$(CXX) -c $(CFLAGS) $*.cpp

beforedepend::

depend:: beforedepend
	$(CXXDEPEND) $(CPPFLAGS) $(INCLUDES) *.cpp > .depend

clean::
	rm -f *.o *.a *.so

-include .depend
