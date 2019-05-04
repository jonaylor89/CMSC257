/*
 * John Naylor
 * Assignment 5
 * TCP client/server using sockets
 * 5/1/19
 */

#include "client.h"

/**
 *
 * Entry point for the client app
 *
 * This handles the creation of the socket and the connection
 * as well as signal handling for multiprocess connections
 *
 */
int main(int argc, char *argv[]) {
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];
  
  char *ADDR = argv[1];
  char *PORT = argv[2];
  char *filename = argv[3];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(ADDR, PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "[DEBUG] getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  /**
   * Create socket 
   */
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
            p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    /**
     * Connect to server
     */
    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      perror("client: connect");
      close(sockfd);
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "[DEBUG] client: failed to connect\n");
    return 2;
  }

  inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
      s, sizeof s);
  printf("[DEBUG] client: connecting to %s\n", s);

  freeaddrinfo(servinfo); // all done with this structure

  downloadFile(sockfd, filename);

  close(sockfd);

  return 0;
}

