/*
** c_join.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:21:39 2016 toozs-_c
** Last update Sat May 28 21:55:29 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

/* ----- JOIN -----
** JOIN <channel>{,<channel>}
**
** ----- ERROR -----
** -> 461 ERR_NEEDMOREPARAMS: too few parameters
** ERR_BANNEDFROMCHAN
** ERR_INVITEONLYCHAN
** ERR_CHANNELISFULL
** -> 403 ERR_NOSUCHCHANNEL: channel doesn't exist
** RPL_TOPIC
** ERR_BADCHANNELKEY
** ERR_BADCHAN
** ERR_TOOMANYCHANNELS
*/

int		add_channel(t_client *cl, char *chan, t_client *clients)
{
  t_channel	*tmp;

  while (clients != NULL)
    {
      tmp = clients->channels;
      while (tmp != NULL)
	{
	  if (!my_strcmp(chan, tmp->name))
	    {
	      ch_push_back(&cl->channels, chan);
	      return (0);
	    }
	  tmp = tmp->next;
	}
      clients = clients->next;
    }
  ch_push_back(&cl->channels, chan);
  return (1);
}

int		_join(t_client *cl, char **tab, t_client *clients)
{
  int		i;
  printf("Join command\n");

  i = 1;
  if (cl->registered)
    {
      while (tab[i])
	i++;
      if (i < 2)
	dprintf(cl->fd, "461 Too few params\r\n");
      else
	{
	  i = 1;
	  while (tab[i])
	    {
	      if (add_channel(cl, tab[i], clients))
		{
		  dprintf(cl->fd, "403 Channel doesn't exist, creating.\r\n");
		  dprintf(cl->fd, "%s JOIN %s\r\n", cl->name, tab[i]);
		  dprintf(cl->fd, "332 Fuck la moulinette.\r\n");
		}
	      i++;
	    }
	}
    }
  return (0);
}
