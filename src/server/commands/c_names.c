/*
** c_names.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:46 2016 toozs-_c
** Last update Fri May 27 16:40:29 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- NAMES -----
** NAMES {<channel>, {<channel>}}
**
** ----- CODES -----
** -> RPL_NAMREPLY
** -> RPL_ENDOFNAMES
*/

int		_names(t_client *client, char **tab)
{
  int		i;

  printf("names command\n");
  i = 1;
  if (client->registered)
    {
      while (tab[i])
	i++;
      if (i > 1)
	{
	  printf("list nicknames of users in a particular channel\n");
	}
      else
	{
	  printf("list nicknames of users in all channels visible to clien\n");
	}
    }
  return (0);
}
