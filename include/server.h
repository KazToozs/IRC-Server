/*
** server.h for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/include
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon May 16 11:35:09 2016 toozs-_c
** Last update Sat May 28 18:22:52 2016 toozs-_c
*/

#ifndef __SERV_H_
#define __SERV_H_

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

typedef struct		s_channel
{
  char			*name;
  struct s_channel	*next;
  struct s_channel	*prev;
}			t_channel;

typedef struct		s_client
{
  int			fd;
  int			registered;
  char			*name;
  /* char			(*channels)[10]; */
  t_channel		*channels;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct  s_com
{
  char          *command;
  int           (*ptr)(t_client *, char **, t_client *);
}               t_com;

int			list_push_back(t_client **list, int fd);
void			list_remove_node(t_client **head, t_client **node);
int			ch_push_back(t_channel **list, char *name);
void			ch_remove_node(t_channel **head, t_channel **node);

int			read_input(char *buff, t_client *params,
				   t_client *clients);
char			**my_str_tab(char *str);
void			free_tab(char** tab);
void			handle_clients(int sock_fd, struct timeval *tv,
				       t_client **clients);
int			_nick(t_client *client, char **tab, t_client *clients);
int			_join(t_client *client, char **tab, t_client *clients);
int			_list(t_client *client, char **tab, t_client *clients);
int			_privmsg(t_client *cl, char **tab, t_client *clients);
int			_names(t_client *cl, char **tab, t_client *clients);
int			_part(t_client *client, char **tab, t_client *clients);
int			_users(t_client *cl, char **tab, t_client *clients);
int			_user(t_client *client, char **tab, t_client *clients);
int			_quit(t_client *client, char **tab, t_client *clients);

#endif /* __SERV_H_ */
