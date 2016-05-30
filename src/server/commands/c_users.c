/*
** c_users.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:44 2016 toozs-_c
** Last update Mon May 30 17:50:34 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- USER -----
** USER
**
** ----- CODES -----
** -> 392 RPL_USERSSTART: 
** -> 395 RPL_NOUSERS
** -> 393 RPL_USERS
** -> 394 RPL_ENDOFUSERS
*/

int		_users(t_client *cl, char **tab, t_client *clients,
		       t_channel **chans)
{
  t_client	*tmp;

  (void)tab;
  (void)chans;
  printf("Join command\n");
  if (cl->registered)
    {
      tmp = clients;
      dprintf(cl->fd, "392 :Users start\r\n");
      while (tmp != NULL)
	{
	  dprintf(cl->fd, "393 %s :Users\r\n", tmp->name);
	  tmp = tmp->next;
	}
      dprintf(cl->fd, "394 :Users end\r\n");
      return (0);
    }
  return (2);
}
