/*
** c_part.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:26 2016 toozs-_c
** Last update Sun May 29 16:02:12 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- PART -----
** part <channel>{,<channel>}
**
** ----- ERROR -----
** -> 461 ERR_NEEDMOREPARAMS
** -> 442 ERR_NOTONCHANNEL
** -> 403 ERR_NOSUCHCHANNEL
*/

int		is_in_channel(t_client *cl, char *chan)
{
  t_channel	*tmp;

  tmp = cl->channels;
  while (tmp != NULL)
    {
      if (!my_strcmp(chan, tmp->name))
	{
	  ch_remove_node(&cl->channels, tmp);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		leave_channel(t_client *cl, char *chan, t_client *clients)
{
  t_channel	*tmp;

  if (!is_in_channel())
    {
      while (clients != NULL)
	{
	  tmp = clients->channels;
	  while (tmp != NULL)
	    {
	      if (!my_strcmp(chan, tmp->name))
		{
		  dprintf(cl->fd, "442 Not on channel %s\r\n", chan);
		  return (1);
		}
	      tmp = tmp->next;  
	    }
	  clients = clients->next;
	}
      dprintf(cl->fd, "403 No such channel %s\r\n", chan);
      return (1);
    }
  return (0);
}

int		_part(t_client *cl, char **tab, t_client *clients)
{
  int		i;
  int		ret;

  printf("Part command\n");
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
	      leave_channel(cl, tab[i], clients);
	    }
        }
    }
  return (0);
}
