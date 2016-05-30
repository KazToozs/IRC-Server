/*
** c_join.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:21:39 2016 toozs-_c
** Last update Mon May 30 13:20:06 2016 toozs-_c
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

void		print_join(t_client *cl, char *chan)
{
  dprintf(cl->fd, ":%s JOIN %s\r\n", cl->name, chan);
  dprintf(cl->fd, ":%s 332 %s %s :%s%s\r\n", "127.0.0.1",
	  cl->name, chan, "Welcome to ",
	  chan);
  dprintf(cl->fd, ":%s 353 %s @ %s :%s", "127.0.0.1",
	  cl->name, chan, cl->name);
  /* print_name(tmp->fd, tmp, tmp->cmd.args); */
  dprintf(cl->fd, "\r\n:%s 366 %s :End of /NAMES list.\r\n",
	  "127.0.0.1" , chan);
}

int		add_channel(t_client *cl, char *chan, t_client *clients,
			    t_channel **chans)
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
	      print_join(cl, chan);
	      return (0);
	    }
	  tmp = tmp->next;
	}
      clients = clients->next;
    }
  ch_push_back(&cl->channels, chan);
  ch_push_back(chans, chan);
  return (1);
}

int		_join(t_client *cl, char **tab, t_client *clients,
		      t_channel **chans)
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
	      if (add_channel(cl, tab[i], clients, chans))
		{
		  dprintf(cl->fd, "403 Channel doesn't exist, creating.\r\n");
		  print_join(cl, tab[i]);
		}
	      i++;
	    }
	}
      return (0);
    }
  return (2);
}
