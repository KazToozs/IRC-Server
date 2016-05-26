/*
** server.c for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed May 18 11:11:21 2016 toozs-_c
** Last update Thu May 26 20:24:36 2016 toozs-_c
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
#include "server.h"

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

void			server_loop(int sock_fd)
{
  struct timeval	tv;
  t_client		*clients;

  clients = NULL;
  while (42)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 300;
      handle_clients(sock_fd, &tv, &clients);
    }
}

int			run_server(int port)
{
  int			sock_fd;
  struct sockaddr_in	s_in;

  if ((sock_fd = make_socket(port, &s_in)) == 1)
    return (1);
  if (check_return(bind(sock_fd, (const struct sockaddr *)&s_in,
			sizeof(s_in)), sock_fd))
    return (1);
  if (check_return(listen(sock_fd, 42), sock_fd))
    return (1);
  server_loop(sock_fd);
  if (close(sock_fd) == -1)
    return (1);
  return (0);
}
