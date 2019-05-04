/*
 * John Naylor
 * Assignment 5
 * TCP client/server using sockets
 * 5/1/19
 */

#include "client.h"


/**
 *
 * Procedure to download a file from a server
 *
 * First sends the server the filename of it wants to download
 * then Receives the server's response 50 bybtes at a time
 *
 */
void downloadFile(int conn, char *fr_name) {

  char buf[MAX];

  /**
   * Open the file to write the download
   */
  int fr = open(fr_name, O_CREAT | O_WRONLY, 0666);
  if(fr == -1) {
    printf("[DEBUG] File %s cannot be opened file on client.\n", fr_name);
  } else {

  // 80 is an arbitrary number, pls don't overflow me
   char command[80];
   snprintf(command, 80, "get %s", fr_name);
   printf("[DEBUG] Command: %s\n", command);
    
    /**
     * Send the server the filename
     */
    send(conn, command, strlen(command), 0);
    bzero(buf, MAX); 
    int fr_block_sz = 0;

    /**
     * Receive the bytes from the server 50 bytes at a time
     */
    while((fr_block_sz = recv(conn, buf, MAX, 0))) {

      if(fr_block_sz < 0) {
        printf("[DEBUG] %s\n", "Error receiving file from server to client.");
        exit(1);
      }

      char *end = strstr(buf, "/cmsc257");

      /**
       * Write the bytes received to the open file
       */

      if (end != NULL) {
        fr_block_sz = end - buf; 
      }

      int write_sz = write(fr, buf, fr_block_sz);
      if(write_sz < fr_block_sz){
        printf("[DEBUG] %s\n", "File write failed on client.");
      } 

      bzero(buf, MAX);
    }
    printf("[DEBUG] File received from server!\n");
    close(fr);
  }

}

/**
 * get sockaddr, IPv4 or IPv6:
 */
void *get_in_addr(struct sockaddr *sa) {
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


