#
# Created by makemake (Ubuntu Sep  7 2011) on Mon Sep 26 16:21:11 2011
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		cc
CXX =		c++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

ALLOCDIR =	/usr/local/pub/wrc/courses/sp1/allocate
CC =		gcc
CFLAGS =	-ggdb -std=c99 -I$(ALLOCDIR)
#
# If you are using a SPARC-based machine (e.g., the compute server
# queeg), change "-lallocate-ubuntu86" to "-lallocate-sparc" below or
# in your Makefile to get the correct version of the library.  (If you
# change it here, you'll need to regenerate your Makefile with 'makemake'
# for it to take effect.)
#
LIBFLAGS =	-L$(ALLOCDIR) -lallocate-ubuntu86
CLIBFLAGS =	$(LIBFLAGS)

########## End of flags from header.mak


CPP_FILES =	
C_FILES =	main.c
PS_FILES =	
S_FILES =	
H_FILES =	allocate.h input.h objects.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	
LOCAL_LIBS =	liballocate-ubuntu86.a

#
# Main targets
#

all:	main 

main:	main.o $(OBJFILES)
	$(CC) $(CFLAGS) -o main main.o $(OBJFILES) $(LOCAL_LIBS) $(CLIBFLAGS)

#
# Dependencies
#

main.o:	allocate.h input.h objects.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) main.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf main 
