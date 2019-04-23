
#include "server.h"

void connHandler(int client) {

  char buf[MAX];

  while (true) {
    write(client, "/cmsc257", 8);

    break;
  }

}

int main(int argc, char **argv) {

  int sock, conn;
  struct sockaddr_in server, client;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons(PORT);

  if ((listen(sock, 5)) != 0) {
    exit(1);
  }

  len = sizeof(client);

  conn = accept(sock, (struct sockaddr*)&client, &len);
  if (conn < 0) {
    exit(1);
  }

  clientHandler(conn);

  close(sock);

  return 0;
}
