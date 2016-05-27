/*
** c_msg.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:28 2016 toozs-_c
** Last update Fri May 27 17:01:32 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- PRIVMSG -----
** PRIVMSG <receiver>{,<receiver>} <message to send>
**
** ----- CODES -----
** -> ERR_NORECIPIENT
** ERR_CANNOTSENDTOCHAN
** ERR_NOTEXITTOSEND
** ERR_NOTOPLEVEL
** ERR_NOSUCHNICK
*/

int		_privmsg(t_client *client, char **tab)
{
  int		i;
  printf("Join command\n");
  i = 1;
  if (client->registered)
    {
      while (tab[i])
	i++;
      if (i < 2)
	dprintf(client->fd, "401 No such nick or channel\r\n");
      else
	{
	  /* check for channel names that match */
	  /* check for usernames that match */
	  return (0);
	}
    }
  return (0);
}
