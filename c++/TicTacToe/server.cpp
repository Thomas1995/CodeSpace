#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <string>

const char PORT[] = "3490";
const int MAXDATASIZE = 1000;
const int BACKLOG = 20;

char buf[MAXDATASIZE];

int M[9];

int setupServer() {
  struct addrinfo hints, *rez;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(NULL, PORT, &hints, &rez);

  int yes = 1;
  int server = -1;

  for(addrinfo *p = rez; p != NULL; p = p->ai_next) {
    server = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

    if(server == -1) {
      perror("Socket() failed: ");
      continue;
    }

    if(setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
      perror("Setsockopt() failed: ");
      exit(1);
    }

    if(bind(server, p->ai_addr, p->ai_addrlen) == -1) {
      perror("Bind() failed: ");
      exit(1);
    }

    if(listen(server, BACKLOG) == -1) {
      perror("Listen() failed: ");
      exit(1);
    }

    break;
  }

  freeaddrinfo(rez);
  return server;
}

int main() {
  const int server = setupServer();

  if(server == -1) {
    printf("Could not set up server\n");
    exit(1);
  }

  printf("Listening for connections\n");

  sockaddr_storage their_addr;
  socklen_t sin_size = sizeof their_addr;

  fd_set master;    // master file descriptor list
  fd_set read_fds;  // temp file descriptor list for select()

  FD_ZERO(&master);    // clear the master and temp sets
  FD_ZERO(&read_fds);

  // add the server to the master set
  FD_SET(server, &master);

  // keep track of the biggest file descriptor
  int fdmax = server; // so far, it's this one

  int newfd; // newly accept()ed socket descriptor
  struct sockaddr_storage remoteaddr; // client address
  socklen_t addrlen;

  char buf[MAXDATASIZE]; // buffer for client data
  int nbytes;

  while(true) {
    read_fds = master; // copy it
    if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
        perror("Select() failed");
        exit(4);
    }

    // run through the existing connections looking for data to read
    for(int i = 0; i <= fdmax; i++) {
      if (FD_ISSET(i, &read_fds)) { // we got one!!
        if (i == server) {
          // handle new connections
          addrlen = sizeof remoteaddr;
          newfd = accept(server, (struct sockaddr *)&remoteaddr, &addrlen);

          if (newfd == -1) {
            perror("Accept() failed");
          } else {
            FD_SET(newfd, &master); // add to master set
            if (newfd > fdmax) {    // keep track of the max
              fdmax = newfd;
            }

            printf("New connection %d.\n", newfd);
          }
        } else {
          // handle data from a client
          if ((nbytes = recv(i, buf, sizeof(buf), 0)) <= 0) {
            // got error or connection closed by client
            if (nbytes == 0) {
                // connection closed
                printf("%d disconnected.\n", i);
            } else {
                perror("Recv() failed");
            }
            close(i); // bye!
            FD_CLR(i, &master); // remove from master set
          } else {
            // we got some data from a client
            int coord[2];
            memcpy(coord, buf, nbytes);

            M[(coord[0] - 1) * 3 + coord[1] - 1] = i;

            printf("%d %d %d\n%d %d %d\n%d %d %d\n\n",
              M[0], M[1], M[2], M[3], M[4], M[5], M[6], M[7], M[8]);

            for(int j = 0; j <= fdmax; j++)
              // send to everyone except the server
              if (FD_ISSET(j, &master) && j != server)
                if (send(j, M, sizeof(M), 0) == -1)
                  perror("Send() failed");
          }
        } // END handle data from client
      } // END got new incoming connection
    } // END looping through file descriptors
  }

  return 0;
}
