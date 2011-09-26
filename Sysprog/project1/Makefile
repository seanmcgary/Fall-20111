IDIR = .
CC=gcc
CFLAGS=-I$(IDIR)

DEPS = input.h objects.h allocate.h
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
