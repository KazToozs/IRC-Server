/*
** c_msg.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:28 2016 toozs-_c
** Last update Fri Jun  3 19:06:55 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

/* ----- PRIVMSG -----
** PRIVMSG <receiver>{,<receiver>} <message to send>
**
** ----- CODES -----
** -> 411 ERR_NORECIPIENT: ":No recipient given"
** ERR_CANNOTSENDTOCHAN
** ERR_NOTEXITTOSEND
** ERR_NOTOPLEVEL
** -> 401 ERR_NOSUCHNICK
*/

void		send_to_channel(char *chan_name, char *msg,
				t_client *clients, t_client *cl)
{
  t_client	*tmp;
  t_channel	*chan;
  int		chan_found;

  tmp = clients;
  while (tmp != NULL)
    {
      if (tmp != cl)
	{
	  chan = tmp->channels;
	  chan_found = 0;
	  while (chan != NULL && chan_found == 0)
	    {
	      if (!my_strcmp(chan->name, chan_name))
		{
		  dprintf(tmp->fd, ":%s PRIVMSG %s :%s\r\n",
			  cl->name, chan_name, msg);
		  chan_found = 1;
		}
	      chan = chan->next;
	    }
	}
      tmp = tmp->next;
    }
}

int		check_channels(t_channel **chan, char **tab,
			       t_client *clients, t_client *cl)
{
  t_channel	*tmp;

  tmp = *chan;
  while (tmp != NULL)
    {
      if (!my_strcmp(tab[1], tmp->name))
	{
	  send_to_channel(tab[1], tab[2], clients, cl);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}

int		check_nicknames(char *nickname, char *msg, t_client *clients,
				t_client *cl)
{
  t_client	*tmp;

  tmp = clients;
  while (tmp != NULL)
    {
      printf("tmp->name: %s , nickname: %s", tmp->name, nickname);
      if (!my_strcmp(tmp->name, nickname))
	{
	  dprintf(tmp->fd, ":%s PRIVMSG %s :%s\r\n", cl->name, nickname, msg);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}

int		_privmsg(t_client *cl, char **tab, t_client *clients,
			 t_channel **chans)
{
  int		i;

  printf("msg command\n");
  i = 1;
  if (cl->registered)
    {
      while (tab[i++]);
      if (i < 2)
	dprintf(cl->fd, "411 No recipient given\r\n");
      else if (i < 3)
	dprintf(cl->fd, "412 No text to send\r\n");
      else
	{
	  if (check_channels(chans, tab, clients, cl))
	    {
	      if (check_nicknames(tab[1], tab[2], clients, cl))
		{
		  dprintf(cl->fd, "401 No nick or channel\r\n");
		  return (1);
		}
	    }
	}
      return (0);
    }
  return (2);
}
