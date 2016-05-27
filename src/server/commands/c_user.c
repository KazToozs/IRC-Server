/*
** c_user.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 17:43:24 2016 toozs-_c
** Last update Fri May 27 17:02:36 2016 toozs-_c
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

int		_user(t_client *client, char **tab)
{
  int		i;
  printf("User command\n");

  i = 1;
  if (!client->registered && client->name)
    {
      while (tab[i])
	i++;
      if (i < 4)
	dprintf(client->fd, "461 Too few parameters\r\n");
      else
	{
	  printf("name: %s\n", client->name);
	  client->registered = 1;
	  dprintf(client->fd, "001 Welcome\r\n");
	}
    }
  else
    dprintf(client->fd, "462 Already registered\r\n");
  return (0);
}
