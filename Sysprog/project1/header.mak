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
