/*
** server.h for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 16 11:35:09 2016 toozs-_c
** Last update Fri May 27 11:48:01 2016 toozs-_c
*/

#ifndef __SERV_H_
#define __SERV_H_

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

typedef struct		s_client
{
  int			fd;
  int			registered;
  char			*name;
  char			(*channels)[10];
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct  s_com
{
  char          *command;
  int           (*ptr)(t_client *, char **);
}               t_com;

int			list_push_back(t_client **list, int fd);
void			list_remove_node(t_client **head, t_client **node);
int			read_input(char *buff, t_client *params,
				   t_client *clients);
char			**my_str_tab(char *str);
void			free_tab(char** tab);
void			handle_clients(int sock_fd, struct timeval *tv,
				       t_client **clients);
int			_nick(t_client *client, char **tab);
int			_join(t_client *client, char **tab);
int			_list(t_client *client, char **tab);
int			_msg(t_client *client, char **tab);
int			_names(t_client *client, char **tab);
int			_part(t_client *client, char **tab);
int			_users(t_client *client, char **tab);
int			_user(t_client *client, char **tab);
int			_quit(t_client *client, char **tab);

#endif /* __SERV_H_ */
