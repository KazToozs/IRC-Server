/*
** c_list.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:10 2016 toozs-_c
** Last update Sat May 28 17:55:40 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ---- LIST -----
**
** ---- CODES -----
** ERR_NOSUCHSERVER
** -> 322 RPL_LIST: <channel name> <#visible channels> :<topic of channel>
** -> 321 RPL_LISTSTART: "Channel :User Name"
** -> 323 RPL_LISTEND: ":End of /LIST"
*/

int		_list(t_client *cl, char **tab, t_client *clients)
{
  int		i;

  printf("list command\n");
  i = 1;
  if (cl->registered)
    {
      while (tab[i])
	i++;
      if (i > 1)
	{
	  printf("list only chosen channels\n");
	}
      else
	printf("list all channels\n");
    }
  return (0);
}
