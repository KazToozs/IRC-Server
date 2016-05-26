/*
** c_user.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 17:43:24 2016 toozs-_c
** Last update Thu May 26 13:18:41 2016 toozs-_c
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
	dprintf(client->fd, "462 Too few parameters\r\n");
      else
	{
	  printf("name: %s\n", client->name);
	  dprintf(client->fd, ":127.0.0.1 001 %s :Welcome\r\n", client->name);
	}
    }
  else
    dprintf(client->fd, "462 Already registered\r\n");
  return (0);
}
