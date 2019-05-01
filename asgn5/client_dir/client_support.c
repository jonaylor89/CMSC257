
#include "client.h"


/**
 *
 * Procedure to download a file from a server
 *
 * First sends the server the filename of it wants to download
 * then Receives the server's response 50 ybtes at a time
 *
 */
void downloadFile(int conn) {

  char buf[MAX];

  char* fr_name = "TEST.txt";

  /**
   * Open the file to write the download
   */
  int fr = open(fr_name, O_CREAT | O_WRONLY, 0666);
  if(fr == -1) {
    printf("[DEBUG] File %s cannot be opened file on client.\n", fr_name);
  } else {

    
    /**
     * Send the server the filename
     */
    send(conn, fr_name, strlen(fr_name), 0);
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

      /**
       * Write the bytes received to the open file
       */
      int write_sz = write(fr, buf, fr_block_sz);
      if(write_sz < fr_block_sz){
        printf("[DEBUG] %s\n", "File write failed on client.");
      } 

      bzero(buf, MAX);
    }
    printf("[DEBUG] Ok received from server!\n");
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

