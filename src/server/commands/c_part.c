/*
** c_part.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:26 2016 toozs-_c
** Last update Mon May 30 14:31:13 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

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
	  ch_remove_node(&cl->channels, &tmp);
	  return (1);
	}
      if (tmp)
	tmp = tmp->next;
    }
  return (0);
}

int		leave_channel(t_client *cl, char *ch_name, t_client *clients,
			      t_channel **chans)
{
  t_channel	*tmp;

  (void)clients;
  if (!is_in_channel(cl, ch_name))
    {
      tmp = (*chans);
      while (tmp != NULL)
	{
	  if (!my_strcmp(ch_name, tmp->name))
	    {
	      dprintf(cl->fd, "442 Not on channel %s\r\n", ch_name);
	      return (1);
	    }
	  tmp = tmp->next;
	}
      dprintf(cl->fd, "403 No such channel %s\r\n", ch_name);
      return (1);
    }
  return (0);
}

int		_part(t_client *cl, char **tab, t_client *clients,
		      t_channel **chans)
{
  int		i;

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
	      leave_channel(cl, tab[i], clients, chans);
	      dprintf(cl->fd, ":%s PART %s\r\n", cl->name, tab[i]);
	      i++;
	    }
        }
      return (0);
    }
  return (2);
}
