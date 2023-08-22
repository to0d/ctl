#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

void main()
{
  int fd;
  struct sockaddr_in6 sockaddr;

  int fd_got;
  struct sockaddr_in6 sockaddr_got;
  int sockaddr_got_len = sizeof(struct sockaddr_in6);

  fd = socket(AF_INET6, SOCK_STREAM, 0);
  if (fd == -1)
  {
    perror("socket() failed");
    printf("socket err: %d\n", errno);
    return;
  }

  sockaddr.sin6_family = AF_INET6;
  //sockaddr.sin6_addr = in6addr_any;
  sockaddr.sin6_port = htons(9001);
  memcpy(&sockaddr.sin6_addr, &in6addr_any, sizeof(in6addr_any));

  if(bind(fd, (struct sockaddr *) &sockaddr, sizeof(struct sockaddr_in6)) < 0) 
  {
    printf("bind err: %d\n", errno);
    perror("socket() failed");
    return;
  }

  if (listen(fd, 50) == -1) 
  {
    printf("listen err: %d\n", errno);
    return;
  }

  fd_got = accept(fd, (struct sockaddr *) &sockaddr_got, &sockaddr_got_len);
  if (fd_got == -1)
  {
    return;
  }
  printf("socket: accepted, fd=%d\n", fd_got);

  close(fd_got);
  close(fd);
}