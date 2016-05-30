/*
** c_users.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:44 2016 toozs-_c
** Last update Mon May 30 14:27:19 2016 toozs-_c
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
  (void)clients;
  (void)cl;
  (void)tab;
  (void)chans;
  printf("Join command\n");
  return (0);
}
