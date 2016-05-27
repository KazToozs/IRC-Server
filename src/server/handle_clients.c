/*
** handle_clients.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 26 19:02:27 2016 toozs-_c
** Last update Fri May 27 11:50:32 2016 toozs-_c
*/

#include <strings.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "server.h"

t_client		*find_commands(char *buff, t_client *tmp,
				       t_client **clients)
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
	  /* if (buff[n] == '\n') */
	  /*   n++; */
	  if (read_input(new, tmp, *clients) == 3)
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

int                     check_client_event(t_client **clients, fd_set *readfds)
{
  t_client              *tmp;
  char                  buff[4096];
  int			i;
  int			ret;

  tmp = *clients;
  i = 0;
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
	  printf("client %d RECEIVED: [%s]\n", i++, buff);
	  tmp = find_commands(buff, tmp, clients);
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

void			count_list(t_client *clients)
{
  int			count;
  /* delete this function */

  count = 0;
  while (clients != NULL)
    {
      count++;
      clients = clients->next;
    }
  printf("list count: %d\n", count);
}

void			handle_clients(int sock_fd, struct timeval *tv,
				       t_client **clients)
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
	      count_list(*clients);
	      printf("added a client\n");
	    }
	}
      check_client_event(clients, &readfds);
    }
}
