#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char PORT[] = "3490";
const int MAXDATASIZE = 1000;

int connectToServer() {
  struct addrinfo hints, *rez;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  getaddrinfo(NULL, PORT, &hints, &rez);

  int sockfd = -1;

  addrinfo *p;

  for(p = rez; p != NULL; p = p->ai_next) {
    sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

    if(sockfd == -1) {
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      continue;
    }

    break;
  }

  if(p == NULL) {
    perror("Failed to connect ");
    exit(1);
  }

  freeaddrinfo(rez);
  return sockfd;
}

int M[9];

int main(int argc, char *argv[]) {
  int server = connectToServer();

  printf("Connected to server\n");

  char buf[MAXDATASIZE];

  while(true) {
    recv(server, buf, sizeof(buf), 0);
    if(buf[0] == 't') {
      int coord[2];
      scanf("Your move: %d %d", &coord[0], &coord[1]);
      send(server, coord, sizeof(coord), 0);
    }
    else {
      memcpy(M, buf, sizeof(M));
      printf("%d %d %d\n%d %d %d\n%d %d %d\n\n",
        M[0], M[1], M[2], M[3], M[4], M[5], M[6], M[7], M[8]);
    }
  }

  close(server);

  return 0;
}
