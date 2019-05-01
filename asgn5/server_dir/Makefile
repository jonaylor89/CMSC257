
CC=gcc
CFLAGS=-Wall
DEPS = server.h 
OBJ = server.o server_support.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

