/*
** c_part.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:26 2016 toozs-_c
** Last update Fri May 27 16:57:44 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- PART -----
** part <channel>{,<channel>}
**
** ----- ERROR -----
** -> 461 ERR_NEEDMOREPARAMS
** -> ERR_NOTONCHANNEL
** -> ERR_NOSUCHCHANNEL
*/

int		_part(t_client *client, char **tab)
{
  int		i;
  printf("Part command\n");
  i = 1;
  if (client->registered)
    {
      while (tab[i])
	i++;
      if (i < 2)
        dprintf(client->fd, "461 Too few params\r\n");
      else
        {
          dprintf(client->fd, "lol\r\n");
        }
    }
  return (0);
}
