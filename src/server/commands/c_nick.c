/*
** c_nick.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:06 2016 toozs-_c
** Last update Sat May 28 21:42:04 2016 toozs-_c
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

int		_nick(t_client *cl, char **tab, t_client *clients)
{
  t_client	*tmp;

  printf("nick command\n");
  tmp = cl;
  if (tab[1])
    {
      while (cl->prev != NULL)
	cl = cl->prev;
      while (cl != NULL)
	{
	  if (my_strcmp(cl->name, tab[1]) == 0)
	    {
	      dprintf(cl->fd, "433 Nickname already in use\r\n");
	      return (1);
	    }
	  cl = cl->next;
	}
	  /* dprintf(client->fd, "NICK ok ?\r\n"); */
      cl = tmp;
      cl->name = my_strdup(tab[1]);
    }
  else
    {
      dprintf(cl->fd, "431 No nickname given\r\n");
      return (1);
    }
  return (0);
}
