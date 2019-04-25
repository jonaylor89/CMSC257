
#include "client.h"

int downloadFile(int sock) {

  int fd; // The fd for the downloaded file
  char buf[MAX];

  while (1) {
    read(sock, buf, MAX);

    if ((strncmp("/cmsc257", buf, 8)) == 0) {
      break; 
    }
  }

  return 0;
}

int main(int argc, char **argv) {

  int sock, conn;
  struct sockaddr_in, server, client;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    exit(1);
  }

  server.sin_family = AD_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(PORT);

  if (connect(sock, (struct sockaddr*)&server, sizeof(server)) != 0) {
    exit(1);
  }

  if (downloadFile(sock) == -1) {
    exit(1);
  }

  close(sock);

  return 0;
}
