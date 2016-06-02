/*
** list.c for my_irc in /home/toozs-_c/rendu/second_year/PSU/PSU_2015_myirc/src/server
** 
** Made by toozs-_c
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu May 19 18:06:47 2016 toozs-_c
** Last update Thu Jun  2 16:17:14 2016 toozs-_c
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int		list_push_back(t_client **list, int fd)
{
  t_client	*block;
  t_client	*tmp;

  if ((block = malloc(sizeof(*block))) == NULL)
    return (1);
  block->next = NULL;
  block->fd = fd;
  block->registered = 0;
  block->name = NULL;
  block->channels = NULL;
  if ((*list) == NULL)
    {
      block->prev = NULL;
      (*list) = block;
    }
  else
    {
      tmp = (*list);
      while ((*list)->next != NULL)
        (*list) = (*list)->next;
      (*list)->next = block;
      (*list)->next->prev = (*list);
      (*list) = tmp;
    }
  return (0);
}

void			list_remove_node(t_client **head, t_client **node)
{
  t_client		*tmp;

  tmp = (*node);
  if ((*node)->prev != NULL)
    (*node)->prev->next = (*node)->next;
  if ((*node)->next != NULL)
    (*node)->next->prev = (*node)->prev;
  if ((*node)->prev == NULL)
    (*head) = (*head)->next;
  (*node) = (*head);
  close(tmp->fd);
  free(tmp);
}
