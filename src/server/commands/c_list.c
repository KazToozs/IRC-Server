/*
** c_list.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:26:10 2016 toozs-_c
** Last update Fri May 27 16:21:14 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ---- LIST -----
**
** ---- CODES -----
** ERR_NOSUCHSERVER
** -> RPL_LIST
** -> RPL_LISTSTART
** -> RPL_LISTEND
*/

int		_list(t_client *client, char **tab)
{
  int		i;

  printf("list command\n");
  i = 1;
  if (client->registered)
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
