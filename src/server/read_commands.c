/*
** read_commmands.c for myirc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 23 14:57:26 2016 toozs-_c
** Last update Fri May 27 11:46:57 2016 toozs-_c
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static t_com g_coms[] =
  {
    {"NICK", &_nick},
    {"USER", &_user},
    {"QUIT", &_quit},
    /* {"/join", &_join}, */
    /* {"/part", &_part}, */
    /* {"/users", &_users}, */
    /* {"/names", &_names}, */
    /* {"/msg", &_msg}, */
    {NULL, NULL}
  };

int		check_commands(t_client *params, char **tab)
{
  int		i;
  int		ret;

  i = 0;
  /* tab[0] = upper_case(tab[0]); */
  while (g_coms[i].command != NULL
         && strcmp(g_coms[i].command, tab[0]) != 0)
    i++;
  if (g_coms[i].command != NULL)
    ret = g_coms[i].ptr(params, tab);
  else
    return (1);
  /* if (ret == 1) */
  /*   send_message(); */
  if (ret == 3)
    return (ret);
  return (0);
}

void		send_message(char *buff, t_client *param, t_client *clients)
{
  while (clients != NULL)
    {
      if (clients != param)
      write(clients->fd, buff, strlen(buff));
      clients = clients->next;
    }
}

int		read_input(char *buff, t_client *params, t_client *clients)
{
  char		**tab;
  int		ret;

  printf("STR: [%s]\n", buff);
  tab = my_str_tab(buff);
  if (tab && tab[0])
    {
      printf("here\n");
      if ((ret = check_commands(params, tab)) != 1)
	return (ret);
      else
	send_message(buff, params, clients);
    }
  free_tab(tab);
  return (0);
}
