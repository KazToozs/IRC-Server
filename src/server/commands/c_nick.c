/*
** c_nick.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:06 2016 toozs-_c
** Last update Thu Jun  2 16:31:06 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

/* ----- NICK ----- 
** nick <nickname>
**
** ----- ERRORS -----
** -> 431 ERR_NONICKNAMEGIVEN: no parameter
** 432 ERR_ERRONEUSNICKNAME: bad chars (japanese chars for example)
** -> 433 ERR_NICKNAMEINUSE: if nickname already in use
** 436 ERR_NICKCOLLISION: ?
*/

int		has_nick(t_client *cl, char *nick)
{
  t_client	*tmp;

  tmp = cl;
  while (cl->prev != NULL)
    cl = cl->prev;
  while (cl != NULL)
    {
      if (my_strcmp(cl->name, nick) == 0)
	{
	  dprintf(cl->fd, "433 Nickname already in use\r\n");
	  return (1);
	}
      cl = cl->next;
    }
  cl = tmp;
  cl->name = my_strdup(nick);
  return (0);
}

int		_nick(t_client *cl, char **tab, t_client *clients,
		      t_channel **chans)
{
  printf("nick command\n");
  (void)chans;
  (void)clients;
  if (tab[1])
    {
      has_nick(cl, tab[1]);
    }
  else
    {
      dprintf(cl->fd, "431 No nickname given\r\n");
      return (1);
    }
  return (0);
}
