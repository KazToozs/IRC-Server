/*
** c_join.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:21:39 2016 toozs-_c
** Last update Fri May 27 16:10:46 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- JOIN -----
** JOIN <channel>{,<channel>}
**
** ----- ERROR -----
** -> 461 ERR_NEEDMOREPARAMS: too few parameters
** ERR_BANNEDFROMCHAN
** ERR_INVITEONLYCHAN
** ERR_CHANNELISFULL
** -> ERR_NOSUCHCHANNEL
** RPL_TOPIC
** ERR_BADCHANNELKEY
** ERR_BADCHAN
** ERR_TOOMANYCHANNELS
*/

int		_join(t_client *client, char **tab)
{
  int		i;
  printf("Join command\n");
  i = 1;
  if (client->registered)
    {
      while (tab[i])
	i++;
      if (i < 2)
	dprintf(client->fd, "461 Too few params");
      else
	{
	  dprintf(client->fd, "lol\r\n");
	}
    }
  return (0);
}
