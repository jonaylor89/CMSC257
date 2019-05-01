/*
 * John Naylor
 * Assignment 5
 * TCP client/server using sockets
 * 5/1/19
 */

#include "server.h"

/**
 * Get sockaddr, IPv4 or IPv6:
 */
void *get_in_addr(struct sockaddr *sa) {
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

/**
 * Connection Handler
 *
 * Takes in a conn file descriptor that is treated
 * as the client where communication occurs.
 *
 * First it waits to be sent a given filename 
 * and proceeds to send the file associated with the filename
 * afterward.
 */
void connHandler(int conn) {

  int numbytes;
  char buf[MAX];
  char filename[MAX];

  /**
   * Receive the filename
   */
  if ((numbytes = recv(conn, buf, MAX-1, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  buf[numbytes] = '\0';

  printf("[DEBUG] server: received filename '%s'\n", buf);

  strncpy(filename, buf, MAX);
  
  /**
   * Open the file to be sent
   */
  int fr = open(filename, O_RDONLY);
  if (fr == -1) {
    printf("[DEBUG] File %s cannot be openned on server", filename);
    exit(1);
  } else {
    bzero(buf, MAX);
    numbytes = 0;

    /**
     * While the file still has data, read it in 50 byte chunks
     */
    while ((numbytes = read(fr, buf, MAX))) {
      if (numbytes < 0) {
        printf("[DEBUG] %s\n", "Error reading file");
        close(fr);
        exit(1);
      }

      /**
       * Send those 50 byte chunk to client
       */
      send(conn, buf, numbytes, 0);

      bzero(buf, MAX);
    }

    printf("%s", "[DEBUG] File sent to client!\n");
    close(fr);
  }

}


