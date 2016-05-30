/*
** c_user.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 17:43:24 2016 toozs-_c
** Last update Sat May 28 17:59:18 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- USER -----
** user: <username> <hostname> <servername> <realname>
**
** ----- ERROR -----
** -> 461 ERR_NEEDMOREPARAMS: too few parameters
** -> 462 ERR_ALREADYREGISTERED: already logged in?
*/

int		_user(t_client *cl, char **tab, t_client *clients)
{
  int		i;
  printf("User command\n");

  i = 1;
  if (!cl->registered && cl->name)
    {
      while (tab[i])
	i++;
      if (i < 4)
	dprintf(cl->fd, "461 Too few parameters\r\n");
      else
	{
	  printf("name: %s\n", cl->name);
	  cl->registered = 1;
	  dprintf(cl->fd, "001 Welcome\r\n");
	}
    }
  else
    dprintf(cl->fd, "462 Already registered\r\n");
  return (0);
}
