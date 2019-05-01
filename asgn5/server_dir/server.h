/*
 * John Naylor
 * Assignment 5
 * TCP client/server using sockets
 * 5/1/19
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT "51234"
#define ADDR "127.0.0.1"
#define MAX 50      // Number of bytes at a time
#define BACKLOG 10  // Number of pending connections

// Function to handle client connections
void connHandler(int);
void *get_in_addr(struct sockaddr*);
