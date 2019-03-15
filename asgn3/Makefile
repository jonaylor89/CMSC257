
CC=gcc
CFLAGS=-Wall
DEPS=asgn3_support.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

asgn3: asgn3.o asgn3_support.o
	$(CC) -o asgn3 asgn3.o asgn3_support.o 


