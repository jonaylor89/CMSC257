
CC=gcc
CFLAGS=-Wall
DEPS = server.h server_support.h
OBJ = server.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

