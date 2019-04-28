/*
 ** client.c -- a stream socket client demo
 */

#include "client.h"

void downloadFile(int conn) {

  char buf[MAX];

  char* fr_name = "TEST.txt";
  int fr = open(fr_name, O_CREAT | O_WRONLY, 0666);
  if(fr == -1) {
    printf("File %s cannot be opened file on client.\n", fr_name);
  } else {

    
    send(conn, fr_name, strlen(fr_name), 0);
    bzero(buf, MAX); 
    int fr_block_sz = 0;
    while((fr_block_sz = recv(conn, buf, MAX, 0))) {

      if(fr_block_sz < 0) {
        printf("%s\n", "Error receiving file from server to client.");
        exit(1);
      }

      int write_sz = write(fr, buf, fr_block_sz);
      if(write_sz < fr_block_sz){
        printf("%s\n", "File write failed on client.");
      } 

      bzero(buf, MAX);
    }
    printf("Ok received from server!\n");
    close(fr);
  }

}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa) {
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[]) {
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int rv;
  char s[INET6_ADDRSTRLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(ADDR, PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
            p->ai_protocol)) == -1) {
      perror("client: socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      perror("client: connect");
      close(sockfd);
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "client: failed to connect\n");
    return 2;
  }

  inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
      s, sizeof s);
  printf("client: connecting to %s\n", s);

  freeaddrinfo(servinfo); // all done with this structure

  downloadFile(sockfd);

  close(sockfd);

  return 0;
}

