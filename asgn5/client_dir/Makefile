
CC=gcc
CFLAGS=-Wall
DEPS = client.h 
OBJ = client.o client_support.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

