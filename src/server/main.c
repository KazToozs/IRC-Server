/*
** main.c for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 16 11:39:41 2016 toozs-_c
** Last update Wed May 18 16:58:31 2016 toozs-_c
*/

#include <stdlib.h>
#include "../../include/my_irc.h"

int		main(int ac, char **av)
{
  int		port;
  if (ac == 2)
    {
      port = atoi(av[1]);
      run_server(port);
    }
  return (0);
}
