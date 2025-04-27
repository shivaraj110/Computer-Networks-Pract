#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  struct hostent *hen;
  struct in_addr **addr_list;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    exit(1);
  }
  hen = gethostbyname(argv[1]);
  if (hen == NULL) {
    herror("gethostbyname");
    exit(1);
  }
  printf("Hostname: %s\n", hen->h_name);
  addr_list = (struct in_addr **)hen->h_addr_list;
  for (int i = 0; addr_list[i] != NULL; i++) {
    printf("IP Address: %s\n", inet_ntoa(*addr_list[i]));
  }
  return 0;
}
