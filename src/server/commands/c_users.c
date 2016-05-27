/*
** c_users.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 15:27:44 2016 toozs-_c
** Last update Fri May 27 16:27:00 2016 toozs-_c
*/

#include <stdio.h>
#include "server.h"

/* ----- USER -----
** USER
**
** ----- CODES -----
** -> RPL_USERSSTART
** -> RPL_NOUSERS
** -> RPL_USERS
** -> RPL_ENDOFUSERS
*/

int		_users(t_client *client, char **tab)
{
  (void)client;
  (void)tab;
  printf("Join command\n");
  return (0);
}
