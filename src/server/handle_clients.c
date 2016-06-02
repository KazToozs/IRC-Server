/*
** handle_clients.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 26 19:02:27 2016 toozs-_c
** Last update Thu Jun  2 16:18:54 2016 toozs-_c
*/

#include <strings.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "server.h"

t_client		*find_commands(char *buff, t_client *tmp,
				       t_client **clients, t_channel **chans)
{
  int			n;
  int			br;
  char			*new;

  n = 0;
  br = 0;
  new = buff;
  while (buff[n] != '\0' && br == 0)
    {
      if (buff[n] == '\n')
	{
	  buff[n] = 0;
	  n++;
	  if (read_input(new, tmp, *clients, chans) == 3)
	    {
	      list_remove_node(clients, &tmp);
	      br = 1;
	    }
	  new = &(buff[n]);
	}
      n++;
    }
  return (tmp);
}

int                     check_client_event(t_client **clients, fd_set *readfds,
					   t_channel **chans)
{
  t_client              *tmp;
  char                  buff[4096];
  int			ret;

  tmp = *clients;
  ret = 0;
  while (tmp != NULL)
    {
      bzero(buff, 4096);
      if (FD_ISSET(tmp->fd, readfds))
	{
	  if ((ret = read(tmp->fd, buff, 4096)) == 0)
	    {
	      close(tmp->fd);
	      list_remove_node(clients, &tmp);
	    }
	  buff[ret] = 0;
	  tmp = find_commands(buff, tmp, clients, chans);
	}
      if (tmp)
	tmp = tmp->next;
    }
  return (0);
}

int			set_clients(fd_set *readfds, t_client *list)
{
  t_client		*tmp;
  int			highest;

  tmp = list;
  if (tmp == NULL)
    return (-1);
  highest = tmp->fd;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, readfds);
      tmp = tmp->next;
      if (tmp && tmp->fd > highest)
        highest = tmp->fd;
    }
  return (highest);
}

void			handle_clients(int sock_fd, struct timeval *tv,
				       t_client **clients, t_channel **chans)
{
  int			nfds;
  fd_set		readfds;
  socklen_t		s_in_size;
  int			client_fd;
  struct sockaddr_in	s_in_client;

  FD_ZERO(&readfds);
  FD_SET(sock_fd, &readfds);
  s_in_size = sizeof(s_in_client);
  if ((nfds = set_clients(&readfds, *clients)) == -1)
    nfds = sock_fd;
  if (select(nfds + 1, &readfds, NULL, NULL, tv) >= 0)
    {
      if (FD_ISSET(sock_fd, &readfds))
	{
	  if ((client_fd = accept(sock_fd, (struct sockaddr *)&s_in_client,
				  &s_in_size)) != -1)
	    {
	      list_push_back(clients, client_fd);
	      printf("added a client\n");
	    }
	}
      check_client_event(clients, &readfds, chans);
    }
}
