/*
** c_list.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:10 2016 toozs-_c
** Last update Mon May 30 14:47:29 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

/* ---- LIST -----
** lists channels and their topics 
** ---- CODES -----
** ERR_NOSUCHSERVER
** -> 322 RPL_LIST: <channel name> <#visible channels> :<topic of channel>
** -> 321 RPL_LISTSTART: "Channel :User Name"
** -> 323 RPL_LISTEND: ":End of /LIST"
*/

void		print_chosen(t_client *cl, char **tab, t_channel **chans)
{
  t_channel	*tmp;
  int		i;
  int		found;

  i = 1;
  dprintf(cl->fd, "321 List Start\r\n");
  while (tab[i])
    {
      found = 0;
      tmp = *chans;
      while (tmp != NULL && found == 0)
	{
	  if (!my_strcmp(tmp->name, tab[i]))
	    {
	      dprintf(cl->fd, "322 %s :topic\r\n", tmp->name);
	      found = 1;
	    }
	  tmp = tmp->next;
	}
      if (found == 0)
	dprintf(cl->fd, "401 %s not found\r\n", tmp->name);
      i++;
    }
  dprintf(cl->fd, "323 List End\r\n");
}

void		print_all(t_client *cl, t_channel **chans)
{
  t_channel	*tmp;

  tmp = *chans;
  printf("start\n");
  dprintf(cl->fd, ":%s 321 Channel :Users Name\r\n", cl->name);
  while (tmp != NULL)
    {
      printf("element\n");
      dprintf(cl->fd, ":%s 322 %s :yolo\r\n", cl->name, tmp->name);
      tmp = tmp->next;
    }
  printf("end\n");
  dprintf(cl->fd, ":%s 323 :List End\r\n", cl->name);
}

int		_list(t_client *cl, char **tab, t_client *clients,
		      t_channel **chans)
{
  int		i;

  printf("list command\n");
  i = 1;
  (void)clients;
  if (cl->registered)
    {
      while (tab[i])
	i++;
      if (i > 1)
	{
	  print_chosen(cl, tab, chans);
	}
      else
	print_all(cl, chans);
    }
  return (2);
}
