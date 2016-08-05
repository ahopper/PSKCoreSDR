#
# libpsk.so Makefile (Linux)
#
CC=c++
LINK=c++
OPTIONS=-g -fPIC -O3 -std=gnu++11

INCLUDES=

COMPILE=$(CC) $(INCLUDES)

PROGRAM=libpsk.so

SOURCES= calcimd.cpp \
pskdet.cpp \
pskmod.cpp \
stdafx.cpp \
pskcoresdr.cpp

HEADERS= calcimd.h \
pskdet.h \
pskdettbl.h \
psktables.h \
pskmod.h \
stdafx.h \
targetver.h \
pskcoresdr.h

OBJS= calcimd.o \
pskdet.o \
pskmod.o \
stdafx.o \
pskcoresdr.o

all: $(PROGRAM) $(HEADERS) $(SOURCES)

$(PROGRAM): $(OBJS)
	$(LINK) -shared -z noexecstack -o $(PROGRAM) $(OBJS) $(LIBS)

.cpp.o:
	$(COMPILE) $(OPTIONS) -c -o $@ $<

install: $(PROGRAM)
	cp pskcoresdr.h /usr/local/include
	cp $(PROGRAM) /usr/local/lib

release: $(PROGRAM)
	cp $(PROGRAM) ../pihpsdr.src/release/pihpsdr

clean:
	-rm -f *.o
	-rm -f $(PROGRAM)
	-rm -f $(JAVA_PROGRAM)

