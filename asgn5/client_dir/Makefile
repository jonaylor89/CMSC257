
CC=gcc
CFLAGS=-Wall
DEPS = client.h 
OBJ = client_support.o client.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

