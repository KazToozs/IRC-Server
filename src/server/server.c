/*
** server.c for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed May 18 11:11:21 2016 toozs-_c
** Last update Thu May 19 10:31:30 2016 toozs-_c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

int			handle_client(int cs1, int cs2)
{
  int			len;
  int			len2;
  char			*str;

  str = get_next_line(cs1);
  len = strlen(str);
  if (len == -1)
    {
      write(2, "error on read\n", strlen("error on read\n"));
      exit(1);
    }
  len2 = 0;
  while (len2 != len)
    {
      len = len - len2;
      len2 = write(cs2, str + len2, len);
    }
  return (0);
}

int			check_return(int first, int second)
{
  if (first == -1)
    {
      if (close(second) == -1)
        return (1);
      return (1);
    }
  return (0);
}

int                     make_socket(int port, struct sockaddr_in *s_in)
{
  struct protoent       *pe;
  int                   stat;
  int                   fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (1);
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (1);
  stat = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                 &stat, sizeof(int)) < 0)
    return (1);
  return (fd);
}

int			run_server(int port)
{
  int			fd;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  int			client_fd1;
  int			client_fd2;
  fd_set		readfds;
  socklen_t		s_in_size;

  if ((fd = make_socket(port, &s_in)) == 1)
    return (1);
  if (check_return(bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)), fd))
    return (1);
  if (check_return(listen(fd, 42), fd))
    return (1);

  s_in_size = sizeof(s_in_client);
  client_fd1 = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  printf("accepted1\n");
  client_fd2 = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  printf("accepted2\n");
  while (42)
    {
      FD_ZERO(&readfds);
      FD_SET(client_fd1, &readfds);
      FD_SET(client_fd2, &readfds);
      select((client_fd1 > client_fd2 ? client_fd1 : client_fd2) + 1, &readfds,
	     NULL, NULL, NULL);
      if (FD_ISSET(client_fd1, &readfds))
	{
	  handle_client(client_fd1, client_fd2);
	}
      if (FD_ISSET(client_fd2, &readfds))
	{
	  handle_client(client_fd2, client_fd1);
	}
    }

  if (close(fd) == -1)
    return (1);
  if (close(client_fd1) == -1)
    return (1);
  if (close(client_fd2) == -1)
    return (1);
  return (0);
}