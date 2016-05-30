/*
** c_names.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:46 2016 toozs-_c
** Last update Mon May 30 17:51:30 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

/* ----- NAMES -----
** NAMES {<channel>, {<channel>}}
**
** ----- CODES -----
** -> 353 RPL_NAMREPLY: a name or channel
** -> 366 RPL_ENDOFNAMES: end of the list
*/

void		print_names_in_channel(char *chan_name, t_client *clients,
				       t_client *cl)
{
  t_client	*tmp;
  t_channel	*chans;
  int		found;

  tmp = clients;
  while (tmp)
    {
      chans = tmp->channels;
      found = 0;
      while (chans && found == 0)
	{
	  if (!my_strcmp(chans->name, chan_name))
	    {
	      dprintf(cl->fd, "353 :%s %s\r\n", cl->name, tmp->name);
	      found = 1;
	    }
	  chans = chans->next;
	}
      tmp = tmp->next;
    }
  dprintf(cl->fd, "366 %s %s :End\r\n", cl->name, chan_name);
}

void		channel_names(char **tab, t_client *cl, t_client *clients)
{
  int		i;
  int		found;
  t_channel	*tmp;

  i = 1;
  while (tab[i])
    {
      tmp = cl->channels;
      found = 0;
      while (tmp != NULL && found == 0)
	{
	  if (!my_strcmp(tab[i], tmp->name))
	    {
	      print_names_in_channel(tab[i], clients, cl);
	      found = 1;
	    }
	  tmp = tmp->next;
	}
      i++;
    }
}

void		print_all_names(t_client *cl, t_client *clients)
{
  t_channel	*chans;
  t_channel	*cli_chans;
  t_client	*tmp;
  int		found;

  chans = cl->channels;
  while (chans != NULL)
    {
      tmp = clients;
      while (tmp != NULL)
	{
	  cli_chans = tmp->channels;;
	  while (cli_chans != NULL && found == 0)
	    {
	      if (!my_strcmp(cli_chans->name, chans->name))
		{
		  dprintf(cl->fd, "353 :%s %s\r\n", cl->name, tmp->name);
		  found = 1;
		}
	      cli_chans = cli_chans->next;
	    }
	  tmp = tmp->next;
	}
      chans = chans->next;
    }
}

int		_names(t_client *cl, char **tab, t_client *clients,
		       t_channel **chans)
{
  int		i;

  printf("names command\n");
  i = 1;
  (void)chans;
  if (cl->registered)
    {
      while (tab[i])
	i++;
      if (i > 1)
	{
	  channel_names(tab, cl, clients);
	}
      else
	{
	  /* printf("list nicknames of users in all channels visible to clien\n"); */
	  print_all_names(cl, clients);
	  dprintf(cl->fd, "366 %s * :End\r\n", cl->name);
	}
    }
  return (2);
}
