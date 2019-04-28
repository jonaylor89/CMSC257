/*
 ** server.c -- a stream socket server demo
 */

#include "server.h"

#define BACKLOG 10	 // how many pending connections queue will hold

void connHandler(int conn) {

  int numbytes;
  char buf[MAX];
  char filename[MAX];

  if ((numbytes = recv(conn, buf, MAX-1, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  buf[numbytes] = '\0';

  printf("server: received filename '%s'\n", buf);

  strncpy(filename, buf, MAX);
  
  int fr = open(filename, O_RDONLY);
  if (fr == -1) {
    printf("File %s cannot be openned on server", filename);
    exit(1);
  } else {
    bzero(buf, MAX);
    numbytes = 0;
    while ((numbytes = read(fr, buf, MAX))) {
      if (numbytes < 0) {
        printf("%s\n", "Error reading file");
        close(fr);
        exit(1);
      }

      send(conn, buf, numbytes, 0);

      bzero(buf, MAX);
    }

    printf("File sent to client!\n");
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

int main(void) {
  int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
  struct addrinfo hints, *servinfo, *p;
  struct sockaddr_storage their_addr; // connector's address information
  socklen_t sin_size;
  int yes=1;
  char s[INET6_ADDRSTRLEN];
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // use my IP

  if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  // loop through all the results and bind to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype,
            p->ai_protocol)) == -1) {
      perror("server: socket");
      continue;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
          sizeof(int)) == -1) {
      perror("setsockopt");
      exit(1);
    }

    if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("server: bind");
      continue;
    }

    break;
  }

  freeaddrinfo(servinfo); // all done with this structure

  if (p == NULL)  {
    fprintf(stderr, "server: failed to bind\n");
    exit(1);
  }

  if (listen(sockfd, BACKLOG) == -1) {
    perror("listen");
    exit(1);
  }

  printf("server: waiting for connections...\n");

  while(1) {  // main accept() loop
    sin_size = sizeof their_addr;

    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
    if (new_fd == -1) {
      perror("accept");
      continue;
    }

    if (fork() == 0) {
      // Child code
      inet_ntop(their_addr.ss_family,
          get_in_addr((struct sockaddr *)&their_addr),
          s, sizeof s);
      printf("server: got connection from %s\n", s);

      connHandler(new_fd);

      close(new_fd);
      exit(0);

    } else {
      // Parent code

      close(new_fd);
    }

  }

  return 0;
}
