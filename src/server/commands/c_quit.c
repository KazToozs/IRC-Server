/*
** c_quit.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server/commands
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 26 11:03:09 2016 toozs-_c
** Last update Mon May 30 14:28:20 2016 toozs-_c
*/

#include "server.h"

int		_quit(t_client *cl, char **tab, t_client *clients,
		      t_channel **chans)
{
  (void)clients;
  (void)cl;
  (void)tab;
  (void)chans;
  return (3);
}
