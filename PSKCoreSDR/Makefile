#
# libpsk.so Makefile (Linux)
#
CC=gcc
LINK=gcc
OPTIONS=-g -fPIC -O3

INCLUDES=

COMPILE=$(CC) $(INCLUDES)

PROGRAM=libpsk.so

SOURCES= CalcIMD.cpp \
PskDet.cpp \
stdafx.cpp \
PSKCoreSDR.cpp

HEADERS= CalcIMD.h \
PskDet.h \
PskDetTbl.h \
PskTables.h \
stdafx.h \
targetver.h \
PSKCoreSDR.h

OBJS= CalcIMD.o \
PskDet.o \
stdafx.o \
PSKCoreSDR.o

all: $(PROGRAM) $(HEADERS) $(SOURCES)

$(PROGRAM): $(OBJS)
	$(LINK) -shared -z noexecstack -o $(PROGRAM) $(OBJS) $(LIBS)

.cpp.o:
	$(COMPILE) $(OPTIONS) -c -o $@ $<

install: $(PROGRAM)
	cp test_psk.h /usr/local/include
	cp $(PROGRAM) /usr/local/lib

release: $(PROGRAM)
	cp $(PROGRAM) ../pihpsdr.src/release/pihpsdr

clean:
	-rm -f *.o
	-rm -f $(PROGRAM)
	-rm -f $(JAVA_PROGRAM)

