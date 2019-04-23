
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define PORT 51234
#define MAX 50

void clientHandler(int);
