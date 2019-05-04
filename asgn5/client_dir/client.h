/*
 * John Naylor
 * Assignment 5
 * TCP client/server using sockets
 * 5/1/19
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 50

void downloadFile(int, char*);
