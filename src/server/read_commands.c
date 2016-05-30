/*
** read_commmands.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 14:57:26 2016 toozs-_c
** Last update Mon May 30 17:20:33 2016 toozs-_c
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static t_com g_coms[] =
  {
    {"NICK", &_nick},
    {"USER", &_user},
    {"QUIT", &_quit},
    {"JOIN", &_join},
    {"PART", &_part},
    {"LIST", &_list},
    {"PRIVMSG", &_privmsg},
    {"USERS", &_users},
    {"NAMES", &_names},
    {NULL, NULL}
  };

int		check_commands(t_client *params, char **tab, t_client *clients,
			       t_channel **chans)
{
  int		i;
  int		ret;

  i = 0;
  /* tab[0] = upper_case(tab[0]); */
  while (g_coms[i].command != NULL
         && strcmp(g_coms[i].command, tab[0]) != 0)
    i++;
  if (g_coms[i].command != NULL)
    ret = g_coms[i].ptr(params, tab, clients, chans);
  else
    return (1);
  if (ret == 2)
    dprintf(params->fd, "451 Not registered\r\n");
  if (ret == 3)
    return (ret);
  return (0);
}

void		send_message(char *buff, t_client *param, t_client *clients)
{
  /* not needed ? */
  while (clients != NULL)
    {
      if (clients != param)
      write(clients->fd, buff, strlen(buff));
      write(clients->fd, "\r\n", 2);
      clients = clients->next;
    }
}

int		read_input(char *buff, t_client *params, t_client *clients,
			   t_channel **chans)
{
  char		**tab;
  int		ret;

  printf("STR: [%s]\n", buff);
  tab = my_str_tab(buff);
  if (tab && tab[0])
    {
      printf("here\n");
      if ((ret = check_commands(params, tab, clients, chans)) != 1)
	return (ret);
      else
	/* send_message(buff, params, clients);// */
	dprintf(params->fd, "421 Unknown command\r\n");
    }
  free_tab(tab);
  return (0);
}
